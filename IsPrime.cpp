#include<iostream>
#include<cmath>

using namespace std;

using ll = long long;

bool IsPrime(ll x){
    if(x<2)return false;
    for(ll i=2;i<=sqrt(x);i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){
    ll x;
    cin >> x;
    if(IsPrime(x))cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}