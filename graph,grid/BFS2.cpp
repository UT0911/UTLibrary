#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<limits>

using namespace std;

const int intM=numeric_limits<int>::max();

vector<int> dx={0,1,0,-1};
vector<int> dy={-1,0,1,0};

vector<vector<int>> BFS2(int H,int W,vector<string> h,vector<string> v,int sh,int sw){
  vector<vector<int>> visited(H,vector<int> (W,intM));
  queue<tuple<int,int,int>> q;
  visited[sh][sw]=0;
  q.push({0,sh,sw});
  while(!q.empty()){
    auto [w,nowH,nowW]=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nextH=nowH+dy[i];
      int nextW=nowW+dx[i];
      if(0<=nextH&&nextH<H&&0<=nextW&&nextW<W&&((i%2==0&&h[min(nowH, nextH)][nextW]=='0')||(i%2==1&&v[nextH][min(nowW, nextW)]=='0'))&&visited[nextH][nextW]==intM){
        visited[nextH][nextW]=w+1;
        q.push({w+1,nextH,nextW});
      }
    }
  }
  
  return visited;
}

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> h(H-1);
  vector<string> v(H);
  for(int i=0;i<H-1;i++)cin >> h[i];
  for(int i=0;i<H;i++)cin >> v[i];
  int sh,sw;
  cin >> sh >> sw;
  vector<vector<int>> visited=BFS2(H,W,h,v,sh,sw);
  cout << visited.size() << endl;
  
  for(int i=0;i<visited.size();i++){
    for(int j=0;j<visited[i].size();j++){
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}