// Google tests
#include <gtest/gtest.h>

// C++
#include <iostream>

// Custom


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
