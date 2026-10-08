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

ll ncr(ll n,ll r,ll m){
  if(r<0||r>n)return 0;
  if(r==0||r==n)return 1;
  ll bunshi=1;
  for(ll i=1;i<=n;i++)bunshi=(bunshi*i)%m;

  ll bunbo=1;
  for(ll i=1;i<=r;i++)bunbo=(bunbo*i)%m;
  for(ll i=1;i<=n-r;i++)bunbo=(bunbo*i)%m;

  return (bunshi*Power(bunbo,m-2,m))%m;
}

int main(){
    ll N,R,M;
    cin >> N >> R >> M;
    cout << ncr(N,R,M) << endl;
}