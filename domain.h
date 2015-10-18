#pragma once

#include <memory>

#include "domain_element.h"

namespace fuzzy {
class Domain {
 public:
  Domain() = default;
  Domain(DomainElement first, DomainElement last)
      : first_(first), last_(last) {}

  static std::unique_ptr<Domain> intRange(int first, int last);

  static std::unique_ptr<Domain> combine(const Domain& domain_first,
                                         const Domain& domain_second);

  virtual int getCardinality() const;

  virtual std::unique_ptr<Domain> getComponent(int index);

  virtual int getNumberOfComponents() const;

  virtual int indexOfElement(const DomainElement& domain_element) const;

  int int indexOfElement(std::unique_ptr<DomainElement> domain_element) const {
    return indexOfElement(*domain_element);
  }

  virtual std::unique_ptr<DomainElement> elementForIndex(int index) const;

  virtual std::string toString() const;

  virtual const DomainElement first() const { return first_; }
  virtual const DomainElement last() const { return last_; }

 private:
  DomainElement first_;
  DomainElement last_;
};
}
