#include "relations.h"

namespace fuzzy {
bool fuzzy::Relations::isSymmetric(const FuzzySet& fuzzy_set) {
  if (!isUtimesURelations(fuzzy_set)) {
    return false;
  }
  Domain d1 = fuzzy_set.domain().getComponent(0);
  for (int i = d1.first()[0]; i < d1.last()[0]; ++i) {
    for (int j = i; j < d1.last()[0]; ++j) {
      if (fuzzy_set.getValueAt(DomainElement::of(i, j)) !=
          fuzzy_set.getValueAt(DomainElement::of(j, i))) {
        return false;
      }
    }
  }
  return true;
}

bool fuzzy::Relations::isReflexive(const FuzzySet& fuzzy_set) {
  if (!isUtimesURelations(fuzzy_set)) {
    return false;
  }
  Domain d1 = fuzzy_set.domain().getComponent(0);
  for (int i = d1.first()[0]; i < d1.last()[0]; ++i) {
    if (fuzzy_set.getValueAt(DomainElement::of(i, i)) != 1) {
      return false;
    }
  }
  return true;
}

bool fuzzy::Relations::isMaxMinTransitive(const FuzzySet& fuzzy_set) {
  if (!isUtimesURelations(fuzzy_set)) {
    return false;
  }
  Domain d1 = fuzzy_set.domain().getComponent(0);
  for (int i = d1.first()[0]; i < d1.last()[0]; ++i) {
    for (int j = d1.first()[0]; j < d1.last()[0]; ++j) {
      // TODO
    }
  }
  return false;
}

FuzzySet fuzzy::Relations::compositionOfBinaryRelations(
    const FuzzySet& fuzzy_set_a, const FuzzySet& fuzzy_set_b) {
  // TODO
  return FuzzySet(Domain::intRange(0, 0));
}

bool fuzzy::Relations::isFuzzyEquivalence(const FuzzySet& fuzzy_set) {
  return isReflexive(fuzzy_set) && isSymmetric(fuzzy_set) &&
         isMaxMinTransitive(fuzzy_set);
}

bool fuzzy::Relations::isUtimesURelations(const FuzzySet& fuzzy_set) {
  if (fuzzy_set.domain().getNumberOfComponents() != 2) {
    return false;
  }
  Domain d1 = fuzzy_set.domain().getComponent(0);
  Domain d2 = fuzzy_set.domain().getComponent(1);
  if (d1.first() != d2.first()) return false;
  if (d1.last() != d2.last()) return false;
  return true;
}
} /* namespace fuzzy */

