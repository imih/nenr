#pragma once

#include <memory>

namespace fuzzy {

class IntUnaryFunction {
 public:
  IntUnaryFunction() = default;
  virtual double valueAt(int) = 0;
};

class GammaFunction : public IntUnaryFunction {
 public:
  GammaFunction(int alfa, int beta) : alfa_(alfa), beta_(beta) {}
  double valueAt(int x) override;

 private:
  int alfa_, beta_;
};

class LFunction : public IntUnaryFunction {
 public:
  LFunction(int alfa, int beta) : alfa_(alfa), beta_(beta) {}
  double valueAt(int x) override;

 private:
  int alfa_, beta_;
};

class LambdaFunction : public IntUnaryFunction {
 public:
  LambdaFunction(int alfa, int beta, int gama)
      : alfa_(alfa), beta_(beta), gama_(gama) {}
  double valueAt(int x) override;

 private:
  int alfa_, beta_, gama_;
};

class StandardFuzzySets {
 public:
  StandardFuzzySets() = default;
  static std::unique_ptr<LFunction> lfunction(int alfa, int beta) {
    return std::unique_ptr<LFunction>(new LFunction(alfa, beta));
  }

  static std::unique_ptr<LambdaFunction> lambda_function(int alfa, int beta,
                                                         int gama) {
    return std::unique_ptr<LambdaFunction>(
        new LambdaFunction(alfa, beta, gama));
  }

  static std::unique_ptr<GammaFunction> gamma_function(int alfa, int beta) {
    return std::unique_ptr<GammaFunction>(new GammaFunction(alfa, beta));
  }
};
}  // namespace fuzzy
