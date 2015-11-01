#pragma once

#include <memory>

namespace fuzzy {

class IntUnaryFunction {
 public:
  IntUnaryFunction() = default;
  virtual double valueAt(int) const = 0;
};

class GammaFunction : public IntUnaryFunction {
 public:
  GammaFunction(int alfa, int beta) : alfa_(alfa), beta_(beta) {}
  double valueAt(int x) const override;

 private:
  int alfa_, beta_;
};

class LFunction : public IntUnaryFunction {
 public:
  LFunction(int alfa, int beta) : alfa_(alfa), beta_(beta) {}
  double valueAt(int x) const override;

 private:
  int alfa_, beta_;
};

class LambdaFunction : public IntUnaryFunction {
 public:
  LambdaFunction(int alfa, int beta, int gama)
      : alfa_(alfa), beta_(beta), gama_(gama) {}
  double valueAt(int x) const override;

 private:
  int alfa_, beta_, gama_;
};

}  // namespace fuzzy
