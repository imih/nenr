#pragma once

#include <memory>

#include "fuzzy_set.h"

namespace fuzzy {

class Relations {
 public:
  static bool isSymmetric(const FuzzySet& fuzzy_set);
  static bool isReflexive(const FuzzySet& fuzzy_set);
  static bool isMaxMinTransitive(const FuzzySet& fuzzy_set);
  static FuzzySet compositionOfBinaryRelations(const FuzzySet& fuzzy_set_a,
                                               const FuzzySet& fuzzy_set_b);
  static bool isFuzzyEquivalence(const FuzzySet& fuzzy_set);
  static bool isUtimesURelations(const FuzzySet& fuzzy_set);

 private:
  Relations() = default;
};

} /* namespace fuzzy */
