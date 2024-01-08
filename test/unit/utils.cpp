// Copyright (C) 2024 Programmers, All Rights Reserved
// Authors: Lim Jeong Hyeok

#include "math/utils.hpp"
#include "gtest/gtest.h"

namespace programmers::math {
TEST(MathUtils, Add) {
  // double type, return lhs+rhs
  //  inf, nan
  // lhs, rhs -> nan, inf --> exception std::invalid_argument

  // EXPECT_THROW(Add(0.0, std::nan), std::invalid_argument);
  // EXPECT_THROW(Add(std::nan, 0.0), std::invalid_argument);
  // EXPECT_THROW(Add(std::nan, std::nan), std::invalid_argument);
  // EXPECT_THROW(Add(0.0, std::inf), std::invalid_argument);
  // EXPECT_THROW(Add(std::inf, 0.0), std::invalid_argument);
  // EXPECT_THROW(Add(std::inf, std::inf), std::invalid_argument);

  // EXPECT_EQ(Add(0.0, 0.0), 0.0);
  // EXPECT_EQ(Add(1.0, 0.0), 1.0);
  // EXPECT_EQ(Add(0.5, 0.3), 1.0);
  // EXPECT_EQ(Add(0.0, 2.0), 1.0);
}
} // namespace programmers::math
