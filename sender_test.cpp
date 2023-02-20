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

TEST_CASE("Check if more than min max values not sent to console for SOC")
{
  std::ostringstream oss1;
  std::streambuf* p_cout_streambuf = std::cout.rdbuf();
  std::cout.rdbuf(oss1.rdbuf());

  print_SOC(10);

  std::cout.rdbuf(p_cout_streambuf);
  
  REQUIRE(oss1.str() == "10");
}

TEST_CASE("Check if more than min max values not sent to console for temp")
{
  std::ostringstream oss2;
  std::streambuf* p_cout_streambuf = std::cout.rdbuf();
  std::cout.rdbuf(oss2.rdbuf());
  
   print_temp(0);

  std::cout.rdbuf(p_cout_streambuf);
  
  REQUIRE(oss2.str() == "11");
  
  
}
