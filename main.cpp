#include <cstdio>
#include <memory>

#include "domain.h"
#include "mutable_fuzzy_set.h"
#include "calculated_fuzzy_set.h"
#include "standard_fuzzy_sets.h"
#include "operations.h"

using namespace fuzzy;

void domain_main() {
  std::unique_ptr<Domain> d1 = Domain::intRange(0, 5);
  printf("Elementi domene d1:\n%s\n", d1->toString().c_str());

  std::unique_ptr<Domain> d2 = Domain::intRange(0, 3);
  printf("Elementi domene  d2:\n%s\n", d2->toString().c_str());

  std::unique_ptr<Domain> d3 = Domain::combine(*d1, *d2);
  printf("Elementi domene d3:\n%s\n", d3->toString().c_str());

  printf("%s\n", d3->elementForIndex(0)->toString().c_str());
  printf("%s\n", d3->elementForIndex(5)->toString().c_str());
  printf("%s\n", d3->elementForIndex(14)->toString().c_str());
  printf("%d\n", d3->indexOfElement(*DomainElement::of({4, 1})));
}

void fuzzy_set_main() {
  std::unique_ptr<Domain> d = Domain::intRange(0, 11);
  MutableFuzzySet* mfs = new MutableFuzzySet(std::move(d));
  mfs->set(*DomainElement::of(0), 1.0);
  mfs->set(*DomainElement::of(1), 0.8);
  mfs->set(*DomainElement::of(2), 0.6);
  mfs->set(*DomainElement::of(3), 0.4);
  mfs->set(*DomainElement::of(4), 0.2);
  std::unique_ptr<FuzzySet> s1(mfs);
  printf("Set1:\n%s\n", s1->toString().c_str());

  std::unique_ptr<Domain> d2 = Domain::intRange(-5, 6);
  std::unique_ptr<IntUnaryFunction> lambda_f =
      StandardFuzzySets::lambda_function(
          d2->indexOfElement(*DomainElement::of(-4)),
          d2->indexOfElement(*DomainElement::of(0)),
          d2->indexOfElement(*DomainElement::of(4)));
  std::unique_ptr<FuzzySet> s2(
      new CalculatedFuzzySet(std::move(d2), std::move(lambda_f)));
  printf("Set2:\n%s\n", s2->toString().c_str());
}

void operations_main() {
  std::unique_ptr<Domain> d = Domain::intRange(0, 11);
  MutableFuzzySet* mfs = new MutableFuzzySet(std::move(d));
  mfs->set(*DomainElement::of(0), 1.0);
  mfs->set(*DomainElement::of(1), 0.8);
  mfs->set(*DomainElement::of(2), 0.6);
  mfs->set(*DomainElement::of(3), 0.4);
  mfs->set(*DomainElement::of(4), 0.2);
  std::unique_ptr<FuzzySet> s1(mfs);
  printf("Set1:\n%s\n", s1->toString().c_str());

  std::unique_ptr<FuzzySet> nots1 =
      Operations::unaryOperation(*s1, std::move(Operations::zadeh_not()));
  printf("Not Set1:\n%s\n", nots1->toString().c_str());

  std::unique_ptr<FuzzySet> un = Operations::binaryOperation(
      *s1, *nots1, std::move(Operations::zadeh_or()));
  printf("Set1 U ~Set2:\n%s\n", un->toString().c_str());

  std::unique_ptr<FuzzySet> hinters =
      Operations::binaryOperation(*s1, *nots1, Operations::hamacher_tnorm(1.0));

  printf(
      "Set1 intersection with notSet1 using parameterised Hamacher T norm with "
      "parameter 1.0:\n%s\n",
      hinters->toString().c_str());
}

int main() {
  //	domain_main();
  // fuzzy_set_main();
  operations_main();
  return 0;
}
