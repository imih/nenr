#pragma once

#include <memory>

#include "domain.h"
#include "domain_element.h"

namespace fuzzy {
class FuzzySet {
 public:
  FuzzySet(const Domain& domain) : domain_(domain) {}
  FuzzySet(const FuzzySet& fuzzy_set) : FuzzySet(fuzzy_set.domain()) {}
  virtual ~FuzzySet() = default;

  const Domain& domain() const { return domain_; }

  virtual double getValueAt(const DomainElement& domain_element) const {
    return 0;
  }

  std::string toString();

 private:
  Domain domain_;
};

std::ostream& operator<<(std::ostream& oss, const FuzzySet& fuzzy_set);

}  // namespace fuzzy
