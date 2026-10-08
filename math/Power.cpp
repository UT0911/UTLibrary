#include<iostream>

using namespace std;

using ll=long long;

ll Power(ll a,ll b,ll m){
  ll ans=1,p=a;
  for(ll i=0;i<60;i++){
    if(b&(1LL<<i)){
      ans=(ans*p)%m;
    }
    p=(p*p)%m;
  }
  return ans;
}

int main(){
    ll A,B,M;
    cin >> A >> B >> M;
    cout << Power(A,B,M) << endl;
}