#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>

using namespace std;

const int intM=numeric_limits<int>::max();

vector<int> dx={0,1,0,-1};
vector<int> dy={-1,0,1,0};

vector<vector<int>> BFS(int H,int W,vector<string> S,int sh,int sw){
  vector<vector<int>> visited(H,vector<int> (W,intM));
  queue<tuple<int,int,int>> q;
  q.push({0,sh,sw});
  while(!q.empty()){
    auto [c,nowH,nowW]=q.front();
    q.pop();
    visited[nowH][nowW]=c;
    for(int i=0;i<4;i++){
      int nextH=nowH+dy[i];
      int nextW=nowW+dx[i];
      if(0<=nextH&&nextH<H&&0<=nextW&&nextW<W&&S[nextH][nextW]!='#'&&visited[nextH][nextW]==intM){
        q.push({c+1,nextH,nextW});
      }
    }
  }
  
  return visited;
}

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0;i<H;i++)cin >> S[i];
  int sh,sw;
  cin >> sh >> sw;
  vector<vector<int>> visited=BFS(H,W,S,sh,sw);
  cout << visited.size() << endl;
  
  for(int i=0;i<visited.size();i++){
    for(int j=0;j<visited[i].size();j++){
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}