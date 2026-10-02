#include<iostream>
#include<vector>

using namespace std;

using ll = long long;
vector<ll> Imos(int N,int M,vector<int> L,vector<int> R,vector<ll> W){
    vector<ll> A(N+2,0);
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
    int N,M;
    cin >> N >> M;
    vector<int> L(M);
    vector<int> R(M);
    vector<ll> W(M);
    for(int i=0;i<M;i++)cin >> L[i] >> R[i] >> W[i];

    vector<ll> A=Imos(N,M,L,R,W);
    for(int i=0;i<=N;i++)cout << A[i] << " ";
    cout << endl;

    
    return 0;
}