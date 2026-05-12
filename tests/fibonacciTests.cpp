#include "fibonacci.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test Fibonacci with 0 Should Return 0", "[fibonacci]") {
    // Arrange

    // Act
    int result = fibonacci(0);

    // Assert
    REQUIRE(result == 0);
}