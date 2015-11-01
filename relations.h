#pragma once

#include <memory>

#include "binary_relation.h"

namespace fuzzy {

class Relations {
 public:
  static bool isSymmetric(const BinaryRelation& binary_relation);
  static bool isReflexive(const BinaryRelation& binary_relation);
  static bool isMaxMinTransitive(const BinaryRelation& binary_relation);
  static BinaryRelation compositionOfBinaryRelations(
      const BinaryRelation& binary_relation_a,
      const BinaryRelation& binary_relation_b);
  static bool isFuzzyEquivalence(const BinaryRelation& binary_relation);
  static bool isUtimesURelations(const BinaryRelation& binary_relation);

 private:
  Relations() = default;
};

} /* namespace fuzzy */
