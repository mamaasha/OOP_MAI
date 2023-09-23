#include <gtest/gtest.h>
#include "lib.h"
#include <string>
#include <iostream>

using namespace std;

TEST(ExampleOfStandartUsageTest1, BasicAssertions){
  // arrange 
  int hour = 2;
  int minute = 5;
  string period = "pm";
  // act
  string result = ConvertTo24h(hour, minute, period);
  // assert
  EXPECT_EQ(result, "1405");
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions){
  // arrange 
  int hour = 12;
  int minute = 45;
  string period = "pm";
  // act
  string result = ConvertTo24h(hour, minute, period);
  // assert
  EXPECT_EQ(result, "0045");
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions){
  // arrange 
  int hour = 12;
  int minute = 45;
  string period = "am"; 
  // act
  string result = ConvertTo24h(hour, minute, period);
  // assert
  EXPECT_EQ(result, "1245");
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions){
  // arrange 
  int hour = 2;
  int minute = 5;
  string period = "am";
  // act
  string result = ConvertTo24h(hour, minute, period);
  // assert
  EXPECT_EQ(result, "0205");
}

TEST(ValidateInputTest1, InvalidHour) {
  // arrange
  int hour = 0;
  int minute = 30;
  string period = "am";
  // act & assert
  EXPECT_THROW(ValidateInput(hour, minute, period), std::out_of_range);
}
TEST(ValidateInputTest2, InvalidPeriod) {
  // arrange
  int hour = 1;
  int minute = 30;
  string period = "pupupu";
  // act & assert
  EXPECT_THROW(ValidateInput(hour, minute, period), std::invalid_argument);
}
TEST(ValidateInputTest3, InvalidMinute) {
  // arrange
  int hour = 5;
  int minute = -1;
  string period = "am";
  // act & assert
  EXPECT_THROW(ValidateInput(hour, minute, period), std::out_of_range);
}
TEST(ValidateInputTest4, ValidInput) {
  // arrange
  int hour = 5;
  int minute = 5;
  string period = "am";
  // act & assert
  EXPECT_NO_THROW(ValidateInput(hour, minute, period));
}
