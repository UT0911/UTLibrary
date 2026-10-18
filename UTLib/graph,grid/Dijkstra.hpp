#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

using ll = long long;
using vertex = pair<ll, int>;
using Graph = vector<vector<vertex>>;

const ll llM = numeric_limits<ll>::max();

namespace UTLib
{

    void addEdge(Graph &g, const int u, const int v, const ll w)
    {
        g[u].push_back({w, v});
    }

    vector<ll> Dijkstra(const int N, const Graph &g, const int s)
    {
        vector<ll> dist(N + 1, llM);
        priority_queue<vertex, vector<vertex>, greater<vertex>> q;
        dist[s] = 0LL;
        q.push({0LL, s});
        while (!q.empty())
        {
            auto [w, now] = q.top();
            q.pop();
            if (w != dist[now])
                continue;
            for (pair<ll, int> nextEdge : g[now])
            {
                int next = nextEdge.second;
                ll nextW = w + nextEdge.first;
                if (dist[next] > nextW)
                {
                    dist[next] = nextW;
                    q.push({nextW, next});
                }
            }
        }
        return dist;
    }
}