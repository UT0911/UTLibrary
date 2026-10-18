#pragma once

#include <vector>

using namespace std;

namespace UTLib
{

    template <typename T, typename U>
    vector<T> PrefixSum(U N, const vector<T> &A)
    {
        vector<T> ruiseki(N + 1, 0);
        for (int i = 1; i <= N; i++)
        {
            ruiseki[i] = ruiseki[i - 1] + A[i];
        }
        return ruiseki;
    }

    template <typename T, typename U>
    vector<vector<T>> PrefixSum2(U N, U M, const vector<vector<T>> &A)
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

}