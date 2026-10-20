// Library : https://github.com/UT0911/UTLibrary

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
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

// system_clock::time_point start = system_clock::now();

// ll getTime()
// {
//     system_clock::time_point end = system_clock::now();
//     return duration_cast<milliseconds>(end - start).count();
// }

// bool CheckTime(const ll limit, const ll eps)
// {
//     return getTime() < limit - eps;
// }

int ketawa(const int x)
{
    string S = to_string(x);
    int sum = 0;
    for (char c : S)
    {
        sum += (int)(c - '0');
    }
    return sum;
}

bool IsPrime(const ll x)
{
    if (x < 2)
        return false;
    for (ll i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

ll Power(ll a, ll b, const ll m)
{
    ll ans = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1LL)
            ans = ans * a % m;

        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

ll Combination(const ll n, const ll r, const ll m)
{
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    ll bunshi = 1;
    for (ll i = 1; i <= n; i++)
        bunshi = (bunshi * i) % m;

    ll bunbo = 1;
    for (ll i = 1; i <= r; i++)
        bunbo = (bunbo * i) % m;
    for (ll i = 1; i <= n - r; i++)
        bunbo = (bunbo * i) % m;

    return (bunshi * Power(bunbo, m - 2, m)) % m;
}

template <typename T, typename U>
vector<T> Imos(const U N, const U M, const vector<U> &L, const vector<U> &R, const vector<T> &W)
{
    vector<T> A(N + 2, 0);
    for (int i = 0; i < M; i++)
    {
        A[L[i]] += W[i];
        A[R[i] + 1] -= W[i];
    }

    for (int i = 1; i <= N; i++)
    {
        A[i] += A[i - 1];
    }

    return A;
}

template <typename T, typename U>
vector<vector<T>> Imos2(const U N, const U M, const U K, const vector<U> &r1, const vector<U> &c1, const vector<U> &r2, const vector<U> &c2, const vector<T> &W)
{
    vector<vector<T>> A(N + 2, vector<T>(M + 2, 0));
    for (int i = 0; i < K; i++)
    {
        A[r1[i]][c1[i]] += W[i];
        A[r2[i] + 1][c2[i] + 1] += W[i];
        A[r1[i]][c2[i] + 1] -= W[i];
        A[r2[i] + 1][c1[i]] -= W[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            A[i][j] += A[i - 1][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            A[i][j] += A[i][j - 1];
        }
    }

    return A;
}

template <typename T, typename U>
vector<T> PrefixSum(const U N, const vector<T> &A)
{
    vector<T> ruiseki(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        ruiseki[i] = ruiseki[i - 1] + A[i];
    }
    return ruiseki;
}

template <typename T, typename U>
vector<vector<T>> PrefixSum2(const U N, const U M, const vector<vector<T>> &A)
{
    vector<vector<T>> ruiseki(N + 1, vector<T>(M + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            ruiseki[i][j] = A[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            ruiseki[i][j] += ruiseki[i - 1][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            ruiseki[i][j] += ruiseki[i][j - 1];
        }
    }

    return ruiseki;
}

vector<vector<int>> BFS(const int H, const int W, const vector<string> &S, const int si, const int sj)
{
    vector<vector<int>> dist(H, vector<int>(W, intM));
    queue<tuple<int, int, int>> q;
    dist[si][sj] = 0;
    q.push({0, si, sj});
    while (!q.empty())
    {
        auto [w, nowH, nowW] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextH = nowH + dy[i];
            int nextW = nowW + dx[i];
            if (0 <= nextH && nextH < H && 0 <= nextW && nextW < W && S[nextH][nextW] != '#' && dist[nextH][nextW] == intM)
            {
                dist[nextH][nextW] = w + 1;
                q.push({w + 1, nextH, nextW});
            }
        }
    }

    return dist;
}

vector<vector<int>> BFS2(const int H, const int W, const vector<string> &h, const vector<string> &v, const int si, const int sj)
{
    vector<vector<int>> dist(H, vector<int>(W, intM));
    queue<tuple<int, int, int>> q;
    dist[si][sj] = 0;
    q.push({0, si, sj});
    while (!q.empty())
    {
        auto [w, nowH, nowW] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextH = nowH + dy[i];
            int nextW = nowW + dx[i];
            if (0 <= nextH && nextH < H && 0 <= nextW && nextW < W && ((i % 2 == 0 && h[min(nowH, nextH)][nextW] == '0') || (i % 2 == 1 && v[nextH][min(nowW, nextW)] == '0')) && dist[nextH][nextW] == intM)
            {
                dist[nextH][nextW] = w + 1;
                q.push({w + 1, nextH, nextW});
            }
        }
    }

    return dist;
}

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

// cout << fixed << setprecision(20) <<

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}