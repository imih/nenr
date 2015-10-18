#pragma once

#include <string>
#include <sstream>

#include "domain.h"
#include "domain_element.h"
#include "fuzzy_set.h"

namespace fuzzy {
class MutableFuzzySet : FuzzySet {
 public:
  MutableFuzzySet(std::unique_ptr<Domain> domain) : domain_(std::move(domain)) {
    calculated_values_.assign(domain->getCardinality(), 0);
  }

  std::unique_ptr<Domain> domain() const override { return domain_; }

  double getValueAt(const DomainElement& domain_element) override {
    int index = domain_->indexOfElement(domain_element);
    return calculated_values_[index];
  }

  void set(const DomainElement& domain_element, double val) {
    int index = domain_->indexOfElement(domain_element);
    calculated_values_[index] = val;
  }

    void set(std::unique_ptr<DomainElement> domain_element, double val) {
        set(*domain_element, val);
    }

    std::string toString() override {
        //TODO
        return "";
    }


 private:
  std::unique_ptr<Domain> domain_;
  std::vector<double> calculated_values_;
};
}  // namespace fuzzy
