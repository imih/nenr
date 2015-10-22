#include "fuzzy_set.h"

#include <iostream>
#include <sstream>
#include <iomanip>

namespace fuzzy {
std::string FuzzySet::toString() {
  std::ostringstream oss;
  for (int i = 0; i < domain().getCardinality(); ++i) {
    auto cur_element = domain().elementForIndex(i);
    oss << "d[" << cur_element->toString() << "]=" << getValueAt(*cur_element)
        << std::endl;
  }
  return oss.str();
}

}  // namespace fuzzy
