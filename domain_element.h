#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace fuzzy {
class DomainElement : public std::vector<int> {
 public:
  DomainElement() {}

  DomainElement(const std::vector<int>& values) : vector<int>(values) {}

  DomainElement(const std::initializer_list<int> values)
      : std::vector<int>(values) {}

  DomainElement(int value) { push_back(value); }

  ~DomainElement() = default;

  int getNumberOfComponents() const;

  int getComponentValue(int index) const;

  static DomainElement of(const std::vector<int>& values);
  static DomainElement of(const std::initializer_list<int> values);
  static DomainElement of(int value);
  static DomainElement of(int value1, int value2) {
    return of({value1, value2});
  }
};

std::ostream& operator<<(std::ostream& oss,
                         const DomainElement& domain_element);

}  // namespace fuzzy
