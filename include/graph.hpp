#pragma once

// C++
#include <iterator>
#include <fstream>
#include <vector>
#include <map>

class or_graph
{
public:
   using value = std::map<int, unsigned>;
   using iterator = value::iterator;
   using result = int;
   using reference_result = result &;

   // Constructors
   or_graph() noexcept {};
   or_graph(const or_graph &other) noexcept;
   or_graph(or_graph &&other) noexcept;

   // Logic
   void add(int a, int b, unsigned weight) noexcept;
   
   void remove(int a, int b) noexcept;
   void remove(int a) noexcept;

   // Getters
   reference_result get(int a, int b) noexcept;
   reference_result operator()(int a, int b) noexcept;

   // Assignments operators
   or_graph &operator=(const or_graph &other) noexcept;

   or_graph &operator=(or_graph &&other) noexcept;

   // Method for copy-and-swap idiom
   friend void swap(or_graph &a, or_graph &b) noexcept;

private:
   std::map<int, value> m_nodes;

   int m_bad_result = -1;
};

// Main method that read dataset  from file and return them.
static or_graph make_or_graph(const std::string &path)
{
   // Our file
   std::ifstream file(path);

   // Oject to return
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