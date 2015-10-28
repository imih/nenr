#pragma once

#include <memory>

#include "domain_element.h"

namespace fuzzy {
class Domain {
 public:
  Domain(DomainElement first, DomainElement last)
      : first_(first), last_(last) {}

  static Domain intRange(int first, int last);

  static Domain combine(const Domain& domain_first,
                        const Domain& domain_second);

  virtual int getCardinality() const;

  virtual Domain getComponent(int index) const;

  virtual int getNumberOfComponents() const;

  virtual int indexOfElement(const DomainElement& domain_element) const;

  virtual DomainElement elementForIndex(int index) const;

  const DomainElement& first() const { return first_; }
  const DomainElement& last() const { return last_; }

 private:
  Domain() = default;

  DomainElement first_;
  DomainElement last_;
};

std::ostream& operator<<(std::ostream& oss, const Domain& domain);

} /* namespace fuzzy */
