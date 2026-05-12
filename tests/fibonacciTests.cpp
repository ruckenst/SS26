#include <catch2/catch_test_macros.hpp>
#include "../src/fibonacci.h"

TEST_CASE("Test Test", "[fibonacci]") {
    REQUIRE(fibonacci(0) == 0);
    REQUIRE(fibonacci(1) == 1);
    REQUIRE(fibonacci(2) == 1);
}