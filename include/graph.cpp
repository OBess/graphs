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

// Getters
or_graph::reference_result or_graph::get(int a, int b) noexcept
{
   return m_nodes[a][b];
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