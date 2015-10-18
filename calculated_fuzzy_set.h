#pragma once

#include "domain.h"
#include "domain_element.h"
#include "fuzzy_set.h"
#include "int_unary_function.h"

namespace fuzzy {
class CalculatedFuzzySet : FuzzySet {
 public:
  CalculatedFuzzySet(std::unique_ptr<Domain> domain,
                     std::unique_ptr<IntUnaryFunction> int_unary_function)
      : domain_(std::move(domain)),
        int_unary_function_(std::move(int_unary_function)) {}

  std::unique_ptr<Domain> domain() const override { return domain_; }

  double getValueAt(const DomainElement& domain_element) override {
    int val = domain_element.getComponentValue(0);
    return int_unary_function_->valueAt(val);
  }

  std::string toString() override {
    // TODO
    return "";
  }

 private:
  std::unique_ptr<Domain> domain_;
  std::unique_ptr<IntUnaryFunction> int_unary_function_;
};
}  // namespace fuzzy
