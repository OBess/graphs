// Google tests
#include <gtest/gtest.h>

// C++
#include <iostream>
#include <vector>

// Custom
#include "include/graph.hpp"

// Commin path to file with or_graph for testing
static constexpr std::string path("or_graph.txt");

// ---------------------- TESTS

TEST(or_graph, ReadData)
{
   or_graph gr = make_or_graph(path);

   ASSERT_EQ(gr(0, 1), 3);
   ASSERT_EQ(gr(1, 0), 4);
   ASSERT_EQ(gr(0, 2), 2);
   ASSERT_EQ(gr(2, 3), 5);
   ASSERT_EQ(gr(2, 4), 7);
}

TEST(or_graph, GetNode)
{
   or_graph gr = make_or_graph(path);

   ASSERT_EQ(gr(0, 1), 3);

   gr(0, 1) = 4;

   ASSERT_EQ(gr(0, 1), 4);
}

TEST(or_graph, AddNewNodeOrConnection)
{
   or_graph gr = make_or_graph(path);

   gr.add(1, 3, 5);
   gr.add(5, 1, 2);

   ASSERT_EQ(gr(0, 1), 3);
   ASSERT_EQ(gr(1, 0), 4);
   ASSERT_EQ(gr(0, 2), 2);
   ASSERT_EQ(gr(2, 3), 5);
   ASSERT_EQ(gr(2, 4), 7);
   ASSERT_EQ(gr(1, 3), 5);
   ASSERT_EQ(gr(1, 5), 7);
}

TEST(or_graph, RemoveNodeOrConnection)
{
   or_graph gr = make_or_graph(path);

   gr.add(1, 3, 5);
   gr.add(5, 1, 2);

   ASSERT_EQ(gr(0, 1), 3);
   ASSERT_EQ(gr(1, 0), 4);
   ASSERT_EQ(gr(0, 2), 2);
   ASSERT_EQ(gr(2, 3), 5);
   ASSERT_EQ(gr(2, 4), 7);
   ASSERT_EQ(gr(1, 3), 5);
   ASSERT_EQ(gr(2, 0), 7);

   gr.remove(1, 0);
   gr.remove(2);

   ASSERT_EQ(gr(0, 1), 3);
   ASSERT_EQ(gr(1, 0), -1);
   ASSERT_EQ(gr(0, 2), 2);
   ASSERT_EQ(gr(2, 3), -1);
   ASSERT_EQ(gr(2, 4), -1);
   ASSERT_EQ(gr(1, 3), 5);
   ASSERT_EQ(gr(2, 0), -1);
}

TEST(or_graph, CopyConstructor)
{
   or_graph gr = make_or_graph(path);

   or_graph gr1(gr);
   ASSERT_EQ(gr1(0, 1), 3);
   ASSERT_EQ(gr1(1, 0), 4);
   ASSERT_EQ(gr1(0, 2), 2);
   ASSERT_EQ(gr1(2, 3), 5);
   ASSERT_EQ(gr1(2, 4), 7);

   or_graph g2 = gr1;
   ASSERT_EQ(gr2(0, 1), 3);
   ASSERT_EQ(gr2(1, 0), 4);
   ASSERT_EQ(gr2(0, 2), 2);
   ASSERT_EQ(gr2(2, 3), 5);
   ASSERT_EQ(gr2(2, 4), 7);
}

TEST(or_graph, BFS)
{
   or_graph gr = make_or_graph(path);

   std::vector<int> v{0, 1, 2, 3, 4};
   auto r = gr.bfs(0);
   for (size_t i = 0; i < v.size(); ++i)
      ASSER_EQ(v[i], r[i]);

   std::vector<int> v1{2, 3, 4};
   auto r1 = gr.bfs(2);
   for (size_t i = 0; i < v1.size(); ++i)
      ASSER_EQ(v1[i], r1[i]);
}

TEST(or_graph, DFS)
{
   or_graph gr = make_or_graph(path);

   std::vector<int> v{0, 1, 2, 3, 4};
   auto r = gr.dfs(0);
   for (size_t i = 0; i < v.size(); ++i)
      ASSER_EQ(v[i], r[i]);

   std::vector<int> v1{2, 3, 4};
   auto r1 = gr.dfs(2);
   for (size_t i = 0; i < v1.size(); ++i)
      ASSER_EQ(v1[i], r1[i]);
}

TEST(or_graph, Dijkstra)
{
   or_graph gr = make_or_graph(path);

   std::vector<int> v{0, 2, 3, 4};
   auto r = gr.shortest(0, 4);
   for (size_t i = 0; i < v.size(); ++i)
      ASSER_EQ(v[i], r[i]);
}

// ---------------------- ~TESTS

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
