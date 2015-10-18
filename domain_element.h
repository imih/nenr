#pragma once

#include <memory>
#include <string>
#include <vector>

namespace fuzzy {
class DomainElement {
 public:
  DomainElement(const std::vector<int>& values) : values_(values) {}

  DomainElement(const std::initializer_list<int> values) : values_(values) {}

  DomainElement(int value) { values_.push_back(value); }

  ~DomainElement() = default;

  int getNumberOfComponents() const;

  int getComponentValue(int index) const;

  long long hashCode() const;

  bool operator==(const DomainElement& domain_element);

  std::string toString() const;

  static std::unique_ptr<DomainElement> of(const std::vector<int>& values);
  static std::unique_ptr<DomainElement> of(
      const std::initializer_list<int> values);
  static std::unique_ptr<DomainElement> of(int value);

  std::vector<int> values() const { return values_; }

 private:
  std::vector<int> values_;
};
}  // namespace fuzzy
