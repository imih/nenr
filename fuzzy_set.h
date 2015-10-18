#pragma once

#include <memory>

#include "domain.h"
#include "domain_element.h"

namespace fuzzy {
class FuzzySet {
 public:
  FuzzySet() = default;

  virtual std::unique_ptr<Domain> domain() const = 0;
  virtual double getValueAt(const DomainElement& domain_element) = 0;
  virtual std::string toString() = 0;
};
}  // namespace fuzzy
