#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <limits.h>

// GAAT ER VANUIT DAT JE EEN CONNECTED GRAPH HEBT
// anders toepassingen op elke component

using namespace std;

int N_MAX = 7;
typedef pair<int, int> pii;

struct Edge
{
  Edge(int _from, int _to, int _w)
  {
    from = _from;
    to = _to;
    w = _w;
  }

  bool operator <(const Edge& b) const
  {
    return w < b.w;
  }

  bool operator >(const Edge& b) const
  {
    return b.w < w;
  }

  int from;
  int to;
  int w;
};

vector<Edge> edges;
vector<int> distances(N_MAX);

void bellman_ford()
{
  fill(distances.begin(), distances.end(), 10000);
  distances[0] = 0;

  for(int i = 0; i < N_MAX - 1; ++i)
    for(int i = 0; i < edges.size(); ++i)
    {
      if(distances[edges[i].to] > distances[edges[i].from] + edges[i].w)
        distances[edges[i].to] = distances[edges[i].from] + edges[i].w;

      if(distances[edges[i].from] > distances[edges[i].to] + edges[i].w)
        distances[edges[i].from] = distances[edges[i].to] + edges[i].w;
    }

  // OUTPUT
  for(int i = 0; i < N_MAX; ++i)
    cout << "Distance to " << i << " is " << distances[i] << endl;
}

int main()
{
  int num_vertices, num_edges, from, to, weight;
  cin >> num_vertices;
  cin >> num_edges;
  for(int j = 0; j < num_edges; ++j)
  {
    cin >> from >> to >> weight;
    edges.push_back(Edge(from, to, weight));
  }

  bellman_ford();

  return 0;
}
