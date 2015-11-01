#pragma once

#include <string>
#include <sstream>
#include <memory>

#include "domain.h"
#include "domain_element.h"
#include "fuzzy_set.h"

namespace fuzzy {
class MutableFuzzySet : public FuzzySet {
 public:
  MutableFuzzySet(const Domain& domainD) : FuzzySet(domainD) {
    calculated_values_.assign(domain().getCardinality(), 0);
  }

  MutableFuzzySet(const MutableFuzzySet& mutable_fuzzy_set)
      : MutableFuzzySet(mutable_fuzzy_set.domain()) {}

  ~MutableFuzzySet() = default;

  double getValueAt(const DomainElement& domain_element) const override {
    int index = domain().indexOfElement(domain_element);
    return calculated_values_[index];
  }

  void set(const DomainElement& domain_element, double val) {
    int index = domain().indexOfElement(domain_element);
    calculated_values_[index] = val;
  }

 protected:
  std::vector<double> calculated_values_;
};
}  // namespace fuzzy
