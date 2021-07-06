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
void or_graph::add(unsigned a, unsigned b, unsigned weight) noexcept
{
   m_nodes[a].insert({b, weight});
   m_nodes[b];
}

void or_graph::remove(unsigned a, unsigned b) noexcept
{
   m_nodes[a].erase(b);
}

void or_graph::remove(unsigned a) noexcept
{
   m_nodes.erase(a);
}

// Algorithms
std::vector<unsigned> or_graph::bfs(unsigned start) const noexcept
{
   if (m_nodes.count(start) == 0 || empty())
      return {};

   std::queue<unsigned> storage;
   storage.push(start);

   std::vector<unsigned> path;
   std::vector<bool> visited;
   visited.resize(std::max_element(m_nodes.begin(), m_nodes.end(),
                                   [](const auto &l, const auto &r)
                                   { return l.first < r.first; })
                      ->first +
                  1);
   visited[start] = true;

   while (!storage.empty())
   {
      auto value = storage.front();
      const auto &tmp = m_nodes.at(value);
      path.push_back(value);
      storage.pop();

      for (const auto &t : tmp)
         if (!visited[t.first])
         {
            storage.push(t.first);
            visited[t.first] = true;
         }
   }

   return path;
}

std::vector<unsigned> or_graph::dfs(unsigned start) const noexcept
{
   if (m_nodes.count(start) == 0 || empty())
      return {};

   std::stack<unsigned> storage;
   storage.push(start);

   std::vector<unsigned> path;
   std::vector<bool> visited;
   visited.resize(std::max_element(m_nodes.begin(), m_nodes.end(),
                                   [](const auto &l, const auto &r)
                                   { return l.first < r.first; })
                      ->first +
                  1);
   visited[start] = true;

   while (!storage.empty())
   {
      auto value = storage.top();
      const auto &tmp = m_nodes.at(value);
      path.push_back(value);
      storage.pop();

      for (const auto &t : tmp)
         if (!visited[t.first])
         {
            storage.push(t.first);
            visited[t.first] = true;
         }
   }

   return path;
}

std::vector<unsigned> or_graph::shortest(unsigned start, unsigned end) const noexcept
{
   if (m_nodes.count(start) == 0 || empty())
      return {};
   return {};
}

// Getters
or_graph::reference_result or_graph::get(unsigned a, unsigned b) noexcept
{
   m_bad_result = -1;

   if (m_nodes.count(a) > 0)
      if (m_nodes[a].count(b) > 0)
         return (reference_result)m_nodes[a][b];

   return m_bad_result;
}

or_graph::reference_result or_graph::operator()(unsigned a, unsigned b) noexcept
{
   return get(a, b);
}

bool or_graph::empty() const noexcept
{
   return m_nodes.empty();
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