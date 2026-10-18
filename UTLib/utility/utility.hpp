#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>
#include <queue>
#include <limits>
#include <utility>

using namespace std;
using namespace chrono;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vertex = pair<ll, int>;
using Graph = vector<vector<vertex>>;

const int mod9 = 998244353;
const int mod1 = 1000000007;
const int intM = numeric_limits<int>::max();
const ll llM = numeric_limits<ll>::max();
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string abc = "abcdefghijklmnopqrstuvwxyz";
vi dx = {0, 1, 0, -1};
vi dy = {-1, 0, 1, 0};
vi ddx = {-1, 0, 1, -1, 1, -1, 0, 1};
vi ddy = {-1, -1, -1, 0, 0, 1, 1, 1};
template <class T>
using priority_queueR = priority_queue<T, vector<T>, greater<T>>;

#define ALL(x) (x).begin(), (x).end()
#define coutY cout << "Yes" << endl;
#define coutN cout << "No" << endl;

namespace UTLib
{

    template <typename T, typename U>
    void arrIn(T &arr, const U start, const U end)
    {
        for (U i = start; i < end; i++)
        {
            cin >> arr[i];
        }
    }

    template <typename T, typename U>
    void arrOut(const vector<T> &arr, const U start, const U end)
    {
        for (U i = start; i < end; i++)
        {
            cout << arr[i];
            if (i == end - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }

    template <typename T, typename U>
    void arrOut2(const vector<vector<T>> &arr, const U startH, const U startW, const U endH, const U endW)
    {
        for (U i = startH; i < endH; i++)
        {
            for (U j = startW; j < endW; j++)
            {
                cout << arr[i][j];
                if (j == endW - 1)
                {
                    cout << endl;
                }
                else
                {
                    cout << " ";
                }
            }
        }
    }

    template <typename T>
    void UNIQUE(vector<T> &arr)
    {
        sort(ALL(arr));
        arr.erase(unique(ALL(arr)), arr.end());
    }

    void yn(const bool tf) { cout << (tf ? "Yes" : "No") << endl; }
    void YN(const bool tf) { cout << (tf ? "YES" : "NO") << endl; }

    bool kaibun(const string S)
    {
        string T = S;
        reverse(ALL(T));
        return S == T;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2000000000);

    int rnd(const int MIN, const int MAX)
    {
        return MIN + dist(gen) % (MAX - MIN + 1);
    }

    system_clock::time_point start = system_clock::now();

    ll getTime()
    {
        system_clock::time_point end = system_clock::now();
        return duration_cast<milliseconds>(end - start).count();
    }

    bool CheckTime(const ll limit, const ll eps)
    {
        return getTime() < limit - eps;
    }

}