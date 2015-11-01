#include "binary_relation.h"

namespace fuzzy {
std::ostream& operator<<(std::ostream& oss, const BinaryRelation& fuzzy_set) {
  for (int i = 0; i < fuzzy_set.domain().getCardinality(); ++i) {
    auto cur_element = fuzzy_set.domain().elementForIndex(i);
    oss << "mu[" << cur_element << "]=" << fuzzy_set.getValueAt(cur_element)
        << std::endl;
  }
  return oss;
}
} /* namespace fuzzy */
