#pragma once

#include <memory>

#include "domain_element.h"

namespace fuzzy {
class Domain {
 public:
  Domain(DomainElement first, DomainElement last)
      : first_(first), last_(last) {}

  static std::unique_ptr<Domain> intRange(int first, int last);

  static std::unique_ptr<Domain> combine(const Domain& domain_first,
                                         const Domain& domain_second);

  virtual int getCardinality() const;

  virtual std::unique_ptr<Domain> getComponent(int index);

  virtual int getNumberOfComponents() const;

  virtual int indexOfElement(const DomainElement& domain_element) const;

  virtual std::unique_ptr<DomainElement> elementForIndex(int index) const;

  virtual std::string toString() const;

  const DomainElement& first() const { return first_; }
  const DomainElement& last() const { return last_; }

 private:
  Domain() = default;

  DomainElement first_;
  DomainElement last_;
};
}
