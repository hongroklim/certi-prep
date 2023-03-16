#include "gtest/gtest.h"
#include "stdio.h"

extern "C" {
  #include "foo.h"
}

class MainTestSuite : public ::testing::Test {
  void SetUp() override {
    printf("SetUp\n");
  }

  void TearDown() override {
    printf("TearDown\n");
  }
};

TEST_F(MainTestSuite, init){
   EXPECT_EQ(1+1, 2);
};

TEST_F(MainTestSuite, foo){
  EXPECT_EQ(addIntegers(1, 1), 1+1);
};
