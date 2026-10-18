#include<iostream>
#include<vector>

using namespace std;

template<typename T,typename U>
vector<T> PrefixSum(U N,const vector<T> &A){
    vector<T> ruiseki(N+1,0);
    for(int i=1;i<=N;i++){
        ruiseki[i]=ruiseki[i-1]+A[i];
    }
    return ruiseki;
}


int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }

    vector<int> ruiseki=PrefixSum(N,A);
    for(int i=0;i<=N;i++){
        cout << ruiseki[i] << " ";
    }
    cout << endl;
    
    return 0;
}