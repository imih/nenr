#pragma once

#include <memory>

#include "fuzzy_set.h"

namespace fuzzy {
class BinaryFunction {
 public:
  BinaryFunction() = default;
  virtual double valueAt(double x, double y) const = 0;
};

class UnaryFunction {
 public:
  UnaryFunction() = default;
  virtual double valueAt(double x) const = 0;
};

class ZadehAnd : public BinaryFunction {
 public:
  ZadehAnd() = default;
  double valueAt(double x, double y) const override;
};

class ZadehOr : public BinaryFunction {
 public:
  ZadehOr() = default;
  double valueAt(double x, double y) const override;
};

class ZadehNot : public UnaryFunction {
 public:
  ZadehNot() = default;
  double valueAt(double x) const override { return 1 - x; }
};

class HamacherTNorm : public BinaryFunction {
 public:
  HamacherTNorm(double p) : p_(p) {}
  double valueAt(double x, double y) const override {
    return x * y / (p_ + (1 - p_) * (x + y - x * y));
  }

 private:
  double p_;
};

class HamacherSNorm : public BinaryFunction {
 public:
  HamacherSNorm(double p) : p_(p) {}
  double valueAt(double x, double y) const override {
    return (x + y - (2 - p_) * x * y) / (1 - (1 - p_) * x * y);
  }

 private:
  double p_;
};

class Operations {
 public:
  static std::unique_ptr<FuzzySet> unaryOperation(
      const FuzzySet& fuzzy_set, std::unique_ptr<UnaryFunction> unary_function);

  static std::unique_ptr<FuzzySet> binaryOperation(
      const FuzzySet& fuzzy_set_a, const FuzzySet& fuzzy_set_b,
      std::unique_ptr<BinaryFunction> binary_function);

  static std::unique_ptr<UnaryFunction> zadeh_not() {
    return std::unique_ptr<UnaryFunction>(new ZadehNot());
  }

  static std::unique_ptr<BinaryFunction> zadeh_and() {
    return std::unique_ptr<BinaryFunction>(new ZadehAnd());
  }

  static std::unique_ptr<BinaryFunction> zadeh_or() {
    return std::unique_ptr<BinaryFunction>(new ZadehOr());
  }

  static std::unique_ptr<BinaryFunction> hamacher_tnorm(double p) {
    return std::unique_ptr<BinaryFunction>(new HamacherTNorm(p));
  }

  static std::unique_ptr<BinaryFunction> hamacher_snorm(double p) {
    return std::unique_ptr<BinaryFunction>(new HamacherSNorm(p));
  }

 private:
  Operations() = default;
};
}  // namespace fuzzy
