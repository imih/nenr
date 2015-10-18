#include "domain_element.h"

#include <cassert>
#include <iostream>
#include <sstream>

namespace fuzzy {
int DomainElement::getNumberOfComponents() const { return (int)values_.size(); }

int DomainElement::getComponentValue(int index) const {
  assert(index >= 0);
  assert(index < getNumberOfComponents());
  return values_[index];
}

long long DomainElement::hashCode() const {
  long long seed = 0;
  for (const int& val : values_) {
    seed ^= val + 0x9e3779b9 + (seed << 9) + (seed >> 2);
  }
  return seed;
}

bool DomainElement::operator==(const DomainElement& domain_element) {
  return hashCode() == domain_element.hashCode();
}

std::string DomainElement::toString() const {
  std::ostringstream oss;
  int n = (int)values_.size();
  if (n != 1) {
    oss << "(";
  }
  for (int i = 0; i < n; ++i) {
    oss << values_[i];
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

