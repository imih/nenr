#include "domain.h"
#include "simple_domain.h"

namespace fuzzy {
std::unique_ptr<Domain> Domain::intRange(int first, int last) {
  return std::unique_ptr<Domain>(new SimpleDomain(first, last));
}

std::unique_ptr<Domain> Domain::combine(const Domain& domain1,
                                        const Domain& domain2) {
  auto domain1_element_first = domain1.first().values();
  auto domain1_element_last = domain1.last().values();

  auto domain2_element_first = domain2.first().values();
  auto domain2_element_last = domain2.last().values();

  std::vector<int> combined_first;
  combined_first.assign(domain1_element_first.begin(),
                        domain1_element_first.end());
  combined_first.insert(combined_first.end(), domain2_element_first.begin(),
                        domain2_element_first.end());

  std::vector<int> combined_last;
  combined_last.assign(domain1_element_last.begin(),
                       domain1_element_last.end());
  combined_last.insert(combined_last.end(), domain2_element_last.begin(),
                       domain2_element_last.end());
  return std::unique_ptr<Domain>(
      new Domain(DomainElement(combined_first), DomainElement(combined_last)));
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

std::unique_ptr<Domain> Domain::getComponent(int index) {
  return std::unique_ptr<Domain>(new SimpleDomain(
      first_.getComponentValue(index), last_.getComponentValue(index)));
}

int Domain::getNumberOfComponents() const {
  return first_.getNumberOfComponents();
}

int Domain::indexOfElement(const DomainElement& domain_element) const {
  // TODO
  return -1;
}

std::unique_ptr<DomainElement> Domain::elementForIndex(int index) const {
  // TODO
  return nullptr;
}

std::string Domain::toString() const {
  // TODO
  return "";
}

}  // namespace fuzzy
