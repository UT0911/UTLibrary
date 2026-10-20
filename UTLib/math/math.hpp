#include <string>
#include <cmath>

using namespace std;

using ll = long long;
namespace UTLib
{
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
}