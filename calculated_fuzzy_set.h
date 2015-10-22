#pragma once

#include <memory>

#include "domain.h"
#include "domain_element.h"
#include "fuzzy_set.h"
#include "standard_fuzzy_sets.h"

namespace fuzzy {
class CalculatedFuzzySet : public FuzzySet {
 public:
  CalculatedFuzzySet(std::unique_ptr<Domain> domain,
                     std::unique_ptr<IntUnaryFunction> int_unary_function)
      : FuzzySet(std::move(domain)),
        int_unary_function_(std::move(int_unary_function)) {}

  ~CalculatedFuzzySet();

  double getValueAt(const DomainElement& domain_element) const override {
    int index = domain().indexOfElement(domain_element);
    return int_unary_function_->valueAt(index);
  }

 private:
  std::unique_ptr<IntUnaryFunction> int_unary_function_;
};
}  // namespace fuzzy
