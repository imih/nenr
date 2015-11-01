#include "relations.h"

#include <cassert>
#include <cmath>

namespace fuzzy {
bool fuzzy::Relations::isSymmetric(const BinaryRelation& binary_relation) {
  if (!isUtimesURelations(binary_relation)) {
    return false;
  }
  Domain d1 = binary_relation.domain().getComponent(0);
  for (int i = d1.first()[0]; i < d1.last()[0]; ++i) {
    for (int j = i; j < d1.last()[0]; ++j) {
      if (binary_relation.getValueAt(DomainElement::of(i, j)) !=
          binary_relation.getValueAt(DomainElement::of(j, i))) {
        return false;
      }
    }
  }
  return true;
}

bool fuzzy::Relations::isReflexive(const BinaryRelation& binary_relation) {
  if (!isUtimesURelations(binary_relation)) {
    return false;
  }
  Domain d1 = binary_relation.domain().getComponent(0);
  for (int i = d1.first()[0]; i < d1.last()[0]; ++i) {
    if (binary_relation.getValueAt(DomainElement::of(i, i)) != 1) {
      return false;
    }
  }
  return true;
}

bool fuzzy::Relations::isMaxMinTransitive(const BinaryRelation& binary_relation) {
	if (!isUtimesURelations(binary_relation)) {
		return false;
	}
	Domain d1 = binary_relation.domain().getComponent(0);
	for (int x = d1.first()[0]; x < d1.last()[0]; ++x) {
		for (int z = d1.first()[0]; z < d1.last()[0]; ++z) {
			double cur = -1;
			for(int y = d1.first()[0]; y < d1.last()[0]; ++y) {
				cur  = std::max(cur, std::min(binary_relation.getValueAt(DomainElement::of(x, y)),
						binary_relation.getValueAt(DomainElement::of(y, z))));
			}
			if(cur > binary_relation.getValueAt(DomainElement::of(x, z))) {
				return false;
			}
		}
	}
	return true;
}

BinaryRelation fuzzy::Relations::compositionOfBinaryRelations(
		const BinaryRelation& binary_relation_a, const BinaryRelation& binary_relation_b) {
	Domain a2 = binary_relation_a.domain().getComponent(1);
	Domain b1 = binary_relation_b.domain().getComponent(0);
	assert(a2.first() == b1.first());
	assert(a2.last() == b1.last());

	//u x v; v x z
	Domain U = binary_relation_a.domain().getComponent(0);
	Domain V = binary_relation_a.domain().getComponent(1);
	Domain Z = binary_relation_b.domain().getComponent(1);

	BinaryRelation binary_relation = BinaryRelation(Domain::combine(U, Z));
	for(int x = U.first()[0]; x < U.last()[0]; ++x) {
		for(int z = Z.first()[0]; z < Z.last()[0]; ++z) {
			double cur = -1;
			for(int y = V.first()[0]; y < V.last()[0]; ++y) {
				cur = std::max(cur, std::min(binary_relation_a.getValueAt(DomainElement::of(x, y)),
						binary_relation_b.getValueAt(DomainElement::of(y, z))));
			}
			binary_relation.set(DomainElement::of(x, z), cur);
		}
	}

	return binary_relation;
}

bool fuzzy::Relations::isFuzzyEquivalence(const BinaryRelation& binary_relation) {
  return isReflexive(binary_relation) && isSymmetric(binary_relation) &&
         isMaxMinTransitive(binary_relation);
}

bool fuzzy::Relations::isUtimesURelations(const BinaryRelation& binary_relation) {
  if (binary_relation.domain().getNumberOfComponents() != 2) {
    return false;
  }
  Domain d1 = binary_relation.domain().getComponent(0);
  Domain d2 = binary_relation.domain().getComponent(1);
  if (d1.first() != d2.first()) return false;
  if (d1.last() != d2.last()) return false;
  return true;
}
} /* namespace fuzzy */

