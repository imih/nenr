#include <iostream>

#include "binary_relation.h"
#include "domain.h"
#include "mutable_fuzzy_set.h"
#include "calculated_fuzzy_set.h"
#include "standard_fuzzy_sets.h"
#include "operations.h"
#include "relations.h"

using namespace fuzzy;
using namespace std;

void domain_main() {
  Domain d1 = Domain::intRange(0, 5);
  cout << "Elementi domene d1:\n" << d1 << endl;

  Domain d2 = Domain::intRange(0, 3);
  cout << "Elementi domene  d2:\n" << d2 << endl;

  Domain d3 = Domain::combine(d1, d2);
  cout << "Elementi domene d3:\n" << d3 << endl;

  cout << d3.elementForIndex(0) << endl;
  cout << d3.elementForIndex(5) << endl;
  cout << d3.elementForIndex(14) << endl;
  cout << d3.indexOfElement(DomainElement::of({4, 1})) << endl;
}

void fuzzy_set_main() {
  Domain d = Domain::intRange(0, 11);
  MutableFuzzySet s1(d);
  s1.set(DomainElement::of(0), 1.0);
  s1.set(DomainElement::of(1), 0.8);
  s1.set(DomainElement::of(2), 0.6);
  s1.set(DomainElement::of(3), 0.4);
  s1.set(DomainElement::of(4), 0.2);
  cout << "Set1:\n " << s1 << endl;

  Domain d2 = Domain::intRange(-5, 6);
  LambdaFunction lambda_f =
      LambdaFunction(d2.indexOfElement(DomainElement::of(-4)),
                     d2.indexOfElement(DomainElement::of(0)),
                     d2.indexOfElement(DomainElement::of(4)));
  CalculatedFuzzySet s2 = CalculatedFuzzySet(d2, lambda_f);
  cout << "Set2:\n" << s2 << endl;
}

void operations_main() {
  Domain d = Domain::intRange(0, 11);
  MutableFuzzySet mfs(d);
  mfs.set(DomainElement::of(0), 1.0);
  mfs.set(DomainElement::of(1), 0.8);
  mfs.set(DomainElement::of(2), 0.6);
  mfs.set(DomainElement::of(3), 0.4);
  mfs.set(DomainElement::of(4), 0.2);
  cout << "Set1:\n" << mfs << endl;

  MutableFuzzySet nots1 = Operations::unaryOperation(mfs, ZadehNot());
  cout << "Not Set1:\n" << nots1 << endl;

  MutableFuzzySet un = Operations::binaryOperation(mfs, nots1, ZadehOr());
  cout << "Set1 U ~Set2:\n" << un << endl;

  MutableFuzzySet hinters =
      Operations::binaryOperation(mfs, nots1, HamacherTNorm(1.0));

  cout << "Set1 intersection with notSet1 using parameterised Hamacher T norm "
          "with "
       << "parameter 1.0:\n" << hinters << endl;
}

void relations_main() {
  Domain u = Domain::intRange(1, 6);
  Domain u2 = Domain::combine(u, u);

  BinaryRelation r1(u2);
  r1.set(DomainElement::of(1, 1), 1);
  r1.set(DomainElement::of(2, 2), 1);
  r1.set(DomainElement::of(3, 3), 1);
  r1.set(DomainElement::of(4, 4), 1);
  r1.set(DomainElement::of(5, 5), 1);
  r1.set(DomainElement::of(3, 1), 0.5);
  r1.set(DomainElement::of(1, 3), 0.5);

  BinaryRelation r2(u2);
  r2.set(DomainElement::of(1, 1), 1);
  r2.set(DomainElement::of(2, 2), 1);
  r2.set(DomainElement::of(3, 3), 1);
  r2.set(DomainElement::of(4, 4), 1);
  r2.set(DomainElement::of(5, 5), 1);
  r2.set(DomainElement::of(3, 1), 0.5);
  r2.set(DomainElement::of(1, 3), 0.1);

  BinaryRelation r3(u2);
  r3.set(DomainElement::of(1, 1), 1);
  r3.set(DomainElement::of(2, 2), 1);
  r3.set(DomainElement::of(4, 4), 1);
  r3.set(DomainElement::of(5, 5), 1);
  r3.set(DomainElement::of(3, 1), 0.5);
  r3.set(DomainElement::of(1, 3), 0.5);
  r3.set(DomainElement::of(3, 3), 0.3);
  r3.set(DomainElement::of(1, 2), 0.6);
  r3.set(DomainElement::of(2, 1), 0.6);
  r3.set(DomainElement::of(2, 3), 0.7);
  r3.set(DomainElement::of(3, 2), 0.7);

  BinaryRelation r4(u2);
  r4.set(DomainElement::of(1, 1), 1);
  r4.set(DomainElement::of(2, 2), 1);
  r4.set(DomainElement::of(3, 3), 1);
  r4.set(DomainElement::of(4, 4), 1);
  r4.set(DomainElement::of(5, 5), 1);
  r4.set(DomainElement::of(1, 2), 0.4);
  r4.set(DomainElement::of(2, 1), 0.4);
  r4.set(DomainElement::of(2, 3), 0.5);
  r4.set(DomainElement::of(3, 2), 0.5);
  r4.set(DomainElement::of(3, 1), 0.4);
  r4.set(DomainElement::of(1, 3), 0.4);

  cout << "r1:\n" << r1 << endl;
  bool test1 = Relations::isUtimesURelations(r1);
  cout << "r1 je definiran nad UxU? " << test1 << endl;

  bool test2 = Relations::isSymmetric(r1);
  cout << "r1 je simetricna? " << test2 << endl;

  bool test4 = Relations::isReflexive(r1);
  cout << "r1 je refleksivna? " << test4 << endl;

  cout << "r2:\n" << r2 << endl;
  bool test3 = Relations::isSymmetric(r2);
  cout << "r2 je simericna? " << test3 << endl;

  cout << "r3:\n" << r3 << endl;
  bool test5 = Relations::isReflexive(r3);
  cout << "r3 je refleksivna? " << test5 << endl;

  bool test6 = Relations::isMaxMinTransitive(r3);
  cout << "r3 je max-min tranzitivna? " << test6 << endl;

  cout << "r4:\n" << r4 << endl;
  bool test7 = Relations::isMaxMinTransitive(r4);
  cout << "r4 je max-min tranzitivna? " << test7 << endl;
}

void composition_of_binary_relations_main() {
  Domain u1 = Domain::intRange(1, 5);
  Domain u2 = Domain::intRange(1, 4);
  Domain u3 = Domain::intRange(1, 5);

  BinaryRelation r1(Domain::combine(u1, u2));
  r1.set(DomainElement::of(1, 1), 0.3);
  r1.set(DomainElement::of(1, 2), 1);
  r1.set(DomainElement::of(3, 3), 0.5);
  r1.set(DomainElement::of(4, 3), 0.5);

  BinaryRelation r2(Domain::combine(u2, u3));
  r2.set(DomainElement::of(1, 1), 1);
  r2.set(DomainElement::of(2, 1), 0.5);
  r2.set(DomainElement::of(2, 2), 0.7);
  r2.set(DomainElement::of(3, 3), 1);
  r2.set(DomainElement::of(3, 4), 0.4);

  BinaryRelation r1r2 = Relations::compositionOfBinaryRelations(r1, r2);
  cout << r1r2 << endl;
}

void fuzzy_equivalence_main() {
  Domain u = Domain::intRange(1, 5);
  BinaryRelation r1(Domain::combine(u, u));
  r1.set(DomainElement::of(1, 1), 1);
  r1.set(DomainElement::of(2, 2), 1);
  r1.set(DomainElement::of(3, 3), 1);
  r1.set(DomainElement::of(4, 4), 1);
  r1.set(DomainElement::of(1, 2), 0.3);
  r1.set(DomainElement::of(2, 1), 0.3);
  r1.set(DomainElement::of(2, 3), 0.5);
  r1.set(DomainElement::of(3, 2), 0.5);
  r1.set(DomainElement::of(3, 4), 0.2);
  r1.set(DomainElement::of(4, 3), 0.2);

  BinaryRelation r2 = r1;
  cout << "Pocetna relacija je neizrazita relacija ekvivalencije? "
       << Relations::isFuzzyEquivalence(r2) << endl;
  for (int i = 1; i <= 3; ++i) {
    r2 = Relations::compositionOfBinaryRelations(r2, r1);
    cout << "Broj odradjenih kompozicija: " << i << ". \nRelacija je: " << endl;
    cout << r2 << endl;
    cout << "Ova relacija je neizrazita relacije ekvivalencije? "
         << Relations::isFuzzyEquivalence(r2) << endl;
  }
}

int main() {
  cout << "\t\tDomain" << endl;
  domain_main();
  cout << "\t\tFuzzy set" << endl;
  fuzzy_set_main();
  cout << "\t\tOperations" << endl;
  operations_main();
  cout << "\t\tRelations" << endl;
  relations_main();
  cout << "\t\tCompositions of binary relations" << endl;
  composition_of_binary_relations_main();
  cout << "\t\tEquivalence" << endl;
  fuzzy_equivalence_main();
  return 0;
}
