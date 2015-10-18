#pragma once

#include <memory>
#include <string>
#include <vector>

#include "domain.h"
#include "domain_element.h"

namespace fuzzy {
class SimpleDomain : public Domain {
 public:
  SimpleDomain(int first, int last) : first_val_(first), last_val_(last) {}

  int getCardinality() const override { return last_val_ - first_val_; }

  std::unique_ptr<Domain> getComponent(int index) override;

  int getNumberOfComponents() const override { return 1; }

  int indexOfElement(const DomainElement& domain_element) const override;

  std::unique_ptr<DomainElement> elementForIndex(int index) const override;

  std::string toString() const override;

  const DomainElement first() const override {
    DomainElement first(first_val_);
    return first;
  };

  const DomainElement last() const override {
    DomainElement last(last_val_);
    return last;
  }

 private:
  int first_val_, last_val_;
};
}
