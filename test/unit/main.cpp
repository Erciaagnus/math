#include <cstdint>

#include "gtest/gtest.h"

auto main(int32_t argc, char **argv) -> int32_t {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}