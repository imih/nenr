#include "standard_fuzzy_sets.h"

namespace fuzzy {
double GammaFunction::valueAt(int x) override {
  if (x < alfa_) {
    return 0;
  }
  if (x >= beta_) {
    return 1;
  }
  return (x - alfa_) / ((double)beta_ - alfa_);
}

double LFunction::valueAt(int x) override {
  if (x < alfa_) {
    return 1;
  } else if (x >= beta_) {
    return 0;
  }
  return (beta_ - x) / ((double)beta_ - alfa_);
}

double GammaFunction::valueAt(int x) override {
  if (x < alfa_) {
    return 0;
  }
  if (x >= beta_) {
    return 1;
  }
  return (x - alfa_) / ((double)beta_ - alfa_);
}

double LambdaFunction::valueAt(int x) override {
  if (x < alfa_) {
    return 0;
  }
  if (x >= gama_) {
    return 0;
  }
  if (alfa_ <= x && x < beta_) {
    return (x - alfa_) / ((double)beta_ - alfa_);
  }
  return (gama_ - x) / ((double)gama_ - beta_);
}

}  // namespace fuzzy
