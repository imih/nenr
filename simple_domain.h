#pragma once

#include <memory>
#include <string>
#include <vector>

#include "domain.h"
#include "domain_element.h"

namespace fuzzy {
class SimpleDomain : public Domain {
 public:
  SimpleDomain(int first, int last)
      : Domain(first, last), first_val_(first), last_val_(last) {}

  int getCardinality() const override { return last_val_ - first_val_; }

  Domain getComponent(int index) const override;

  int getNumberOfComponents() const override { return 1; }

  int indexOfElement(const DomainElement& domain_element) const override;

  DomainElement elementForIndex(int index) const override;

 private:
  int first_val_, last_val_;
};
}
