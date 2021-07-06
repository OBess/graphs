#pragma once

// C++
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

class or_graph
{
public:
   using value = std::map<unsigned, unsigned>;
   using iterator = value::iterator;
   using result = int;
   using reference_result = result &;

   // Constructors
   or_graph() noexcept {};
   or_graph(const or_graph &other) noexcept;
   or_graph(or_graph &&other) noexcept;

   // Logic
   void add(unsigned a, unsigned b, unsigned weight) noexcept;

   void remove(unsigned a, unsigned b) noexcept;
   void remove(unsigned a) noexcept;

   // Algorithms
   std::vector<unsigned> bfs(unsigned start) const noexcept;
   std::vector<unsigned> dfs(unsigned start) const noexcept;
   // --- Dijkstra's Algorithm
   std::vector<unsigned> shortest(unsigned start, unsigned end) const noexcept;

   // Getters
   reference_result get(unsigned a, unsigned b) noexcept;
   reference_result operator()(unsigned a, unsigned b) noexcept;
   bool empty() const noexcept;

   // Assignments operators
   or_graph &operator=(const or_graph &other) noexcept;

   or_graph &operator=(or_graph &&other) noexcept;

   // Method for copy-and-swap idiom
   friend void swap(or_graph &a, or_graph &b) noexcept;

private:
   // Auxiliary
   size_t max_node() const noexcept;

   std::map<unsigned, value> m_nodes;

   int m_bad_result = -1;
};

// Main method that read dataset  from file and return them.
static or_graph make_or_graph(const std::string &path)
{
   // Our file
   std::ifstream file(path);

   // Object to return
   or_graph gr;

   // Tmp values
   int a, b;
   unsigned weight;

   // Read dataset from file and store it
   while (file >> a)
   {
      file >> b;
      file >> weight;
      gr.add(a, b, weight);
   }

   return gr;
}