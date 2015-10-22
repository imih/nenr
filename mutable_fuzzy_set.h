#pragma once

#include <string>
#include <sstream>

#include "domain.h"
#include "domain_element.h"
#include "fuzzy_set.h"

namespace fuzzy {
class MutableFuzzySet : public FuzzySet {
 public:
  MutableFuzzySet(std::unique_ptr<Domain> domainD)
      : FuzzySet(std::move(domainD)) {
    calculated_values_.assign(domain().getCardinality(), 0);
  }

  virtual ~MutableFuzzySet() = default;

  double getValueAt(const DomainElement& domain_element) const override {
    int index = domain().indexOfElement(domain_element);
    return calculated_values_[index];
  }

  void set(const DomainElement& domain_element, double val) {
    int index = domain().indexOfElement(domain_element);
    calculated_values_[index] = val;
  }

 private:
  std::vector<double> calculated_values_;
};
}  // namespace fuzzy
