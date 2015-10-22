#pragma once

#include <memory>
#include <string>
#include <vector>

namespace fuzzy {
class DomainElement : public std::vector<int> {
 public:
  DomainElement() {}

  DomainElement(const std::vector<int>& values) : vector<int>(values) {}

  DomainElement(const std::initializer_list<int> values)
      : vector<int>(values) {}

  DomainElement(int value) { push_back(value); }

  ~DomainElement() = default;

  int getNumberOfComponents() const;

  int getComponentValue(int index) const;

  std::string toString() const;

  static std::unique_ptr<DomainElement> of(const std::vector<int>& values);
  static std::unique_ptr<DomainElement> of(
      const std::initializer_list<int> values);
  static std::unique_ptr<DomainElement> of(int value);
};
}  // namespace fuzzy
