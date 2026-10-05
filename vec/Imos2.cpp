#include<iostream>
#include<vector>

using namespace std;

using ll = long long;

template<typename T,typename U>
vector<vector<T>> Imos2(U N,U M,U K,vector<U> r1,vector<U> c1,vector<U> r2,vector<U> c2,vector<T> W){
    vector<vector<T>> A(N+2,vector<T> (M+2,0));
    for(int i=0;i<K;i++){
        A[r1[i]][c1[i]]+=W[i];
        A[r2[i]+1][c2[i]+1]+=W[i];
        A[r1[i]][c2[i]+1]-=W[i];
        A[r2[i]+1][c1[i]]-=W[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            A[i][j]+=A[i-1][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            A[i][j]+=A[i][j-1];
        }
    }

    return A;
}

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> r1(K);
    vector<int> c1(K);
    vector<int> r2(K);
    vector<int> c2(K);
    vector<ll> W(K);
    for(int i=0;i<K;i++)cin >> r1[i] >> c1[i] >> r2[i] >> c2[i] >> W[i];

    vector<vector<ll>> A=Imos2(N,M,K,r1,c1,r2,c2,W);
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}