#include "graph.hpp"

// Constructors
or_graph::or_graph(const or_graph &other) noexcept
    : m_nodes(other.m_nodes)
{
}
or_graph::or_graph(or_graph &&other) noexcept
{
   swap(*this, other);
}

// Logic
void or_graph::add(int a, int b, unsigned weight) noexcept
{
   m_nodes[a].insert({b, weight});
}

void or_graph::remove(int a, int b) noexcept
{
   m_nodes[a].erase(b);
}

void or_graph::remove(int a) noexcept
{
   m_nodes.erase(a);
}

// Getters
or_graph::reference_result or_graph::get(int a, int b) noexcept
{
   m_bad_result = -1;

   if (m_nodes.count(a) > 0)
      if (m_nodes[a].count(b) > 0)
         return (reference_result)m_nodes[a][b];

   return m_bad_result;
}

or_graph::reference_result or_graph::operator()(int a, int b) noexcept
{
   return get(a, b);
}

// Assignments operators
or_graph &or_graph::operator=(const or_graph &other) noexcept
{
   or_graph tmp(other);
   swap(*this, tmp);

   return *this;
}

or_graph &or_graph::operator=(or_graph &&other) noexcept
{
   swap(*this, other);
   return *this;
}

// Method for copy-and-swap idiom
void swap(or_graph &a, or_graph &b) noexcept
{
   using std::swap;

   swap(a.m_nodes, b.m_nodes);
}