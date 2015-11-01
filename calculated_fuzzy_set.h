#pragma once

#include <memory>
#include <functional>

#include "domain.h"
#include "domain_element.h"
#include "fuzzy_set.h"
#include "standard_fuzzy_sets.h"

namespace fuzzy {
class CalculatedFuzzySet : public FuzzySet {
 public:
  CalculatedFuzzySet(const Domain& domain,
                     const IntUnaryFunction& int_unary_function)
      : FuzzySet(domain), int_unary_function_(std::move(int_unary_function)) {}

  virtual ~CalculatedFuzzySet() = default;

  double getValueAt(const DomainElement& domain_element) const override {
    int ind = domain().indexOfElement(domain_element);
    return int_unary_function_.valueAt(ind);
  }

 private:
  const IntUnaryFunction& int_unary_function_;
};
}  // namespace fuzzy
