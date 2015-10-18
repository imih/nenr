#include "operations.h"

#include "mutable_fuzzy_set.h"

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

static std::unique_ptr<FuzzySet> Operations::unaryOperation(
    std::unique_ptr<FuzzySet> fuzzy_set, std::unique_ptr<UnaryFunction>) {
  std::unique_ptr<Domain> domain(
      new Domain(fuzzy_set->domain()->first(), fuzzy_set->domain()->last()));
  std::unique_ptr<FuzzySet> mutable_fs(new MutableFuzzySet(domain));
  // TODO iterate over domain elements to set the new function
  return mutable_fs;
}

static std::unique_ptr<FuzzySet> Operations::binaryOperation(
    std::unique_ptr<FuzzySet> fuzzy_set_a, std::unique_ptr<FuzzySet> fuzzy_set_b,
    std::unique_ptr<BinaryFunction>) {
  // TODO
  return nullptr;
}

}  // namespace fuzzy
