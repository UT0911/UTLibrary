#include<iostream>
#include<string>

using namespace std;

int ketawa(int x){
  string S=to_string(x);
  int sum=0;
  for(char c:S){
    sum+=(int)(c-'0');
  }
  return sum;
}

int main(){
    int X;
    cin >> X;
    cout << ketawa(X) << endl;
}