#include "domain_element.h"

#include <cassert>
#include <iostream>
#include <sstream>

namespace fuzzy {
int DomainElement::getNumberOfComponents() const { return (int)size(); }

int DomainElement::getComponentValue(int index) const { return at(index); }

DomainElement DomainElement::of(const std::vector<int>& values) {
  return DomainElement(values);
}

DomainElement DomainElement::of(const std::initializer_list<int> values) {
  return DomainElement(values);
}

DomainElement DomainElement::of(int value) { return DomainElement(value); }

std::ostream& operator<<(std::ostream& oss,
                         const DomainElement& domain_element) {
  int n = (int)domain_element.size();
  if (n != 1) {
    oss << "(";
  }
  for (int i = 0; i < n; ++i) {
    oss << domain_element.at(i);
    if (i != n - 1) oss << ", ";
  }
  if (n != 1) {
    oss << ")";
  }
  return oss;
}

}  // namespace fuzzy

