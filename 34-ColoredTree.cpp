#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int T,N;
int dp[50001][2]={0};

struct Node{
    set<int> link;
}a[50001];

void DFS(int x, int pa){
    for(auto iter=a[x].link.begin();iter != a[x].link.end();iter++){
        int y = *iter;
        if(y==pa) continue;
        DFS(y,x);
        dp[x][0]+=max(dp[y][0],dp[y][1]);
        dp[x][1]+=dp[y][0];
    }
}

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        for(int i=1;i<=N-1;i++){
            int u,v;
            cin>>u>>v;
            a[u].link.insert(v);
            a[v].link.insert(u);
        }
        for(int i=0;i<=N;i++){
            dp[i][1]=1;
            dp[i][0]=0;
        }
        DFS(1,0);
        cout<<max(dp[1][1],dp[1][0])<<endl;
        for(int i=0;i<=N;i++){
            a[i].link.clear();
        }
    }
}