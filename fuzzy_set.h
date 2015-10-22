#pragma once

#include <memory>

#include "domain.h"
#include "domain_element.h"

namespace fuzzy {
class FuzzySet {
public:
	FuzzySet(std::unique_ptr<Domain> domain) : domain_(std::move(domain)) {}

	const Domain& domain() const { return *domain_; }

	virtual double getValueAt(const DomainElement& domain_element) const = 0;

	std::string toString();

private:
	std::unique_ptr<Domain> domain_;
};
}  // namespace fuzzy
