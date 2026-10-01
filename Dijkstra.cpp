#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<limits>

using namespace std;

using ll = long long;

const ll llM=numeric_limits<ll>::max();

vector<ll> Dijkstra(int N,vector<vector<pair<ll,int>>> edge,int s){
    vector<ll> visited(N+1,llM);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    visited[s]=0LL;
    q.push({0LL,s});
    while(!q.empty()){
        auto [w,now]=q.top();
        q.pop();
        for(int i=0;i<edge[now].size();i++){
            int next=edge[now][i].second;
            int nextW=w+edge[now][i].first;
            if(visited[next]>nextW){
                visited[next]=nextW;
                q.push({nextW,next});
            }
        }
    }
    return visited;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> u(M);
    vector<int> v(M);
    vector<int> w(M);
    vector<vector<pair<ll,int>>> edge(N+1);
    for(int i=0;i<M;i++){
        cin >> u[i] >> v[i] >> w[i];
        edge[u[i]].push_back({w[i],v[i]});
        edge[v[i]].push_back({w[i],u[i]});
    }

    vector<ll> visited=Dijkstra(N,edge,1);

    for(int i=1;i<=N;i++)cout << visited[i] << " ";
    cout << endl;


    return 0;
}