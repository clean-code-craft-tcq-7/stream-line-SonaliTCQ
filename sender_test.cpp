#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "sender/sender.hpp"
#include "test/catch.hpp"
#include <iostream>
#include <sstream>

TEST_CASE("Check print on console")
{

  REQUIRE(SOC_generate_values() == 1);
  REQUIRE(temp_generate_values() == 1);

}
