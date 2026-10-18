#include<iostream>
#include<vector>

using namespace std;

template<typename T,typename U>
vector<vector<T>> PrefixSum2(U N,U M,const vector<vector<T>> &A){
    vector<vector<T>> ruiseki(N+1,vector<T> (M+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ruiseki[i][j]=A[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ruiseki[i][j]+=ruiseki[i-1][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ruiseki[i][j]+=ruiseki[i][j-1];
        }
    }

    return ruiseki;
}


int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(N+1,vector<int> (M+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> A[i][j];
        }
    }

    vector<vector<int>> ruiseki=PrefixSum2(N,M,A);
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            cout << ruiseki[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}