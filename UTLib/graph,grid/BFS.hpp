#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const int intM = numeric_limits<int>::max();

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

namespace UTLib
{

    vector<vector<int>> BFS(const int H, const int W, const vector<string> &S, const int sh, const int sw)
    {
        vector<vector<int>> visited(H, vector<int>(W, intM));
        queue<tuple<int, int, int>> q;
        visited[sh][sw] = 0;
        q.push({0, sh, sw});
        while (!q.empty())
        {
            auto [w, nowH, nowW] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextH = nowH + dy[i];
                int nextW = nowW + dx[i];
                if (0 <= nextH && nextH < H && 0 <= nextW && nextW < W && S[nextH][nextW] != '#' && visited[nextH][nextW] == intM)
                {
                    visited[nextH][nextW] = w + 1;
                    q.push({w + 1, nextH, nextW});
                }
            }
        }

        return visited;
    }

    vector<vector<int>> BFS2(const int H, const int W, const vector<string> &h, const vector<string> &v, const int sh, const int sw)
    {
        vector<vector<int>> visited(H, vector<int>(W, intM));
        queue<tuple<int, int, int>> q;
        visited[sh][sw] = 0;
        q.push({0, sh, sw});
        while (!q.empty())
        {
            auto [w, nowH, nowW] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextH = nowH + dy[i];
                int nextW = nowW + dx[i];
                if (0 <= nextH && nextH < H && 0 <= nextW && nextW < W && ((i % 2 == 0 && h[min(nowH, nextH)][nextW] == '0') || (i % 2 == 1 && v[nextH][min(nowW, nextW)] == '0')) && visited[nextH][nextW] == intM)
                {
                    visited[nextH][nextW] = w + 1;
                    q.push({w + 1, nextH, nextW});
                }
            }
        }

        return visited;
    }

}