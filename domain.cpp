#include "domain.h"

#include <algorithm>
#include <iostream>
#include <sstream>

#include "simple_domain.h"

namespace fuzzy {
Domain Domain::intRange(int first, int last) {
  return SimpleDomain(first, last);
}

Domain Domain::combine(const Domain& domain1, const Domain& domain2) {
  std::vector<int> combined_first;
  combined_first.assign(domain1.first().begin(), domain1.first().end());
  combined_first.insert(combined_first.end(), domain2.first().begin(),
                        domain2.first().end());

  std::vector<int> combined_last;
  combined_last.assign(domain1.last().begin(), domain1.last().end());
  combined_last.insert(combined_last.end(), domain2.last().begin(),
                       domain2.last().end());

  return Domain(DomainElement(combined_first), DomainElement(combined_last));
}

int Domain::getCardinality() const {
  int n = getNumberOfComponents();
  if (n == 0) return 0;
  int card = 1;
  for (int i = 0; i < n; ++i) {
    card *= (last_.getComponentValue(i) - first_.getComponentValue(i));
  }
  return card;
}

Domain Domain::getComponent(int index) const {
  return SimpleDomain(first_.getComponentValue(index),
                      last_.getComponentValue(index));
}

int Domain::getNumberOfComponents() const {
  return first_.getNumberOfComponents();
}

int Domain::indexOfElement(const DomainElement& domain_element) const {
  std::vector<int> indices;
  for (int i = 0; i < domain_element.getNumberOfComponents(); ++i) {
    indices.push_back(domain_element.getComponentValue(i) -
                      first_.getComponentValue(i));
  }
  int cord = getCardinality();
  int index = 0;
  for (int i = 0; i < (int)indices.size(); ++i) {
    cord /= (last_.getComponentValue(i) - first_.getComponentValue(i));
    index += indices[i];
    index *= cord;
  }
  return index;
}

DomainElement Domain::elementForIndex(int index) const {
  int n = first_.getNumberOfComponents();
  int cord = 1;
  std::vector<int> indices;
  for (int i = n - 1; i >= 0; --i) {
    cord *= (last_.getComponentValue(i) - first_.getComponentValue(i));
    indices.push_back(
        index % (last_.getComponentValue(i) - first_.getComponentValue(i)));
    index /= cord;
  }
  std::reverse(indices.begin(), indices.end());
  for (int i = 0; i < n; ++i) {
    indices[i] += first_.getComponentValue(i);
  }
  return DomainElement(indices);
}

std::ostream& operator<<(std::ostream& oss, const Domain& domain) {
  int n = domain.getCardinality();
  for (int i = 0; i < n; ++i) {
    oss << "Element domene: " << domain.elementForIndex(i) << std::endl;
  }
  oss << "Kardinalitet domene je: " << n << std::endl;
  return oss;
}

}  // namespace fuzzy
