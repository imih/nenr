#include "simple_domain.h"

#include <cassert>

namespace fuzzy {
Domain SimpleDomain::getComponent(int index) const {
  assert(index == 0);
  return SimpleDomain(first_val_, last_val_);
}

int SimpleDomain::indexOfElement(const DomainElement& domain_element) const {
  assert(domain_element.getNumberOfComponents() == 1);
  int el_val = domain_element.getComponentValue(0);
  assert(el_val >= first_val_);
  assert(el_val < last_val_);
  return el_val - first_val_;
}

DomainElement SimpleDomain::elementForIndex(int index) const {
  assert(index < last_val_ - first_val_);
  return DomainElement::of({first_val_ + index});
}
}
