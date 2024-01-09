// Copyright (C) 2024 Programmers, All Rights Reserved
// Authors: Lim Jeong Hyeok
#ifndef PROGRAMMERS__MATH__UTILS_HPP_
#define PROGRAMMERS__MATH__UTILS_HPP_

namespace programmers::math {

// 사칙연산
// Add, Substract, Multiply, Divide
auto Add(double lhs, double rhs) -> double;
auto Subtract(double lhs, double rhs) -> double;
auto Multiply(double lhs, double rhs) -> double;
auto Divide(double lhs, double rhs) -> double;

// 비교연산
// IsEqual
auto IsEqual(double lhs, double rhs) -> bool;
} // namespace programmers::math

#endif // PROGRAMMERS__MATH__UTILS_HPP_
