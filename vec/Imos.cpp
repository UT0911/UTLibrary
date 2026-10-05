#include<iostream>
#include<vector>

using namespace std;

using ll = long long;

template<typename T,typename U>
vector<T> Imos(U N,U M,vector<U> L,vector<U> R,vector<T> W){
    vector<T> A(N+2,0);
    for(int i=0;i<M;i++){
        A[L[i]]+=W[i];
        A[R[i]+1]-=W[i];
    }

    for(int i=1;i<=N;i++){
        A[i]+=A[i-1];
    }

    return A;
}


int main(){
    int N,K;
    cin >> N >> K;
    vector<int> L(K);
    vector<int> R(K);
    vector<ll> W(K);
    for(int i=0;i<K;i++)cin >> L[i] >> R[i] >> W[i];

    vector<ll> A=Imos(N,K,L,R,W);
    for(int i=0;i<=N;i++)cout << A[i] << " ";
    cout << endl;

    
    return 0;
}