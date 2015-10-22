#include "domain_element.h"

#include <cassert>
#include <iostream>
#include <sstream>

namespace fuzzy {
int DomainElement::getNumberOfComponents() const { return (int)size(); }

int DomainElement::getComponentValue(int index) const { return at(index); }

std::string DomainElement::toString() const {
  std::ostringstream oss;
  int n = (int)size();
  if (n != 1) {
    oss << "(";
  }
  for (int i = 0; i < n; ++i) {
    oss << at(i);
    if (i != n - 1) oss << ", ";
  }
  if (n != 1) {
    oss << ")";
  }
  return oss.str();
}

std::unique_ptr<DomainElement> DomainElement::of(
    const std::vector<int>& values) {
  return std::unique_ptr<DomainElement>(new DomainElement(values));
}

std::unique_ptr<DomainElement> DomainElement::of(
    const std::initializer_list<int> values) {
  return std::unique_ptr<DomainElement>(new DomainElement(values));
}

std::unique_ptr<DomainElement> DomainElement::of(int value) {
  return std::unique_ptr<DomainElement>(new DomainElement(value));
}
}  // namespace fuzzy

