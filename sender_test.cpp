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

TEST_CASE("Check if more than min max values not sent to console")
{
  std::ostringstream oss;
  std::streambuf* p_cout_streambuf = std::cout.rdbuf();
  std::cout.rdbuf(oss.rdbuf());

  print_SOC(10);

  std::cout.rdbuf(p_cout_streambuf);
  
  REQUIRE(oss.str() == "10\n");
  
   print_temp(0);

  std::cout.rdbuf(p_cout_streambuf);
  
  REQUIRE(oss.str() == "11\n");
  
  
}
