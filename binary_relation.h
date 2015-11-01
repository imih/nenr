#pragma once

#include <cassert>
#include <iostream>

#include "mutable_fuzzy_set.h"

namespace fuzzy {

class BinaryRelation : public MutableFuzzySet {
public:
	BinaryRelation (const Domain& domainD) : MutableFuzzySet(domainD) {
		assert(domain().getNumberOfComponents() == 2);
	}

	BinaryRelation(const BinaryRelation& binary_relation)
	: BinaryRelation(binary_relation.domain()) {
		calculated_values_.clear();
		calculated_values_.assign(binary_relation.calculated_values_.begin(), binary_relation.calculated_values_.end());
	}

	~BinaryRelation() = default;
};

std::ostream& operator<<(std::ostream& oss, const BinaryRelation& binary_relation);

} /* namespace fuzzy */
