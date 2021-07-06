// Google tests
#include <gtest/gtest.h>

// C++
#include <iostream>

// Custom
#include "include/graph.hpp"



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
