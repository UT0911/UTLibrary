#pragma once

#include <vector>

using namespace std;

namespace UTLib
{

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

}