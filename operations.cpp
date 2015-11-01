#include "operations.h"

#include <cassert>
#include <iostream>

namespace fuzzy {
double ZadehAnd::valueAt(double x, double y) const {
  if (x <= y) {
    return x;
  } else {
    return y;
  }
}

double ZadehOr::valueAt(double x, double y) const {
  if (x <= y) {
    return y;
  } else {
    return x;
  }
}

MutableFuzzySet Operations::unaryOperation(
    const FuzzySet& fuzzy_set, const UnaryFunction& unary_function) {
  Domain domain(fuzzy_set.domain().first(), fuzzy_set.domain().last());
  int kard = domain.getCardinality();
MutableFuzzySet mfs = MutableFuzzySet(domain);
  for (int i = 0; i < kard; ++i) {
    auto element = fuzzy_set.domain().elementForIndex(i);
    mfs.set(element, unary_function.valueAt(fuzzy_set.getValueAt(element)));
  }
  return mfs;
}

MutableFuzzySet Operations::binaryOperation(
    const FuzzySet& fuzzy_set_a, const FuzzySet& fuzzy_set_b,
    const BinaryFunction& binary_function) {
  Domain domain(fuzzy_set_a.domain().first(), fuzzy_set_a.domain().last());
  assert(fuzzy_set_a.domain().first() == fuzzy_set_b.domain().first());
  assert(fuzzy_set_a.domain().last() == fuzzy_set_a.domain().last());
  int kard = domain.getCardinality();
  MutableFuzzySet mfs = MutableFuzzySet(std::move(domain));
  for (int i = 0; i < kard; ++i) {
    auto element = fuzzy_set_a.domain().elementForIndex(i);
    mfs.set(element,
             binary_function.valueAt(fuzzy_set_a.getValueAt(element),
                                      fuzzy_set_b.getValueAt(element)));
  }
  return mfs;
}

}  // namespace fuzzy
