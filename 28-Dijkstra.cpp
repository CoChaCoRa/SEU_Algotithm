#include<iostream>
#include<algorithm>
using namespace std;

int T;
int num_nations,num_edges,num_start,num_end;
int edges[501][501];
int visit[501];
int dist[501];
int pre[501];

void dijkstra(){
    for(int i=1; i<=num_nations;i++){
        dist[i] = edges[num_start][i];
        //if(edges[num_start][i]!=INT32_MAX) dist[i] = edges[num_start][i];
        //else dist[i] = edges[i][num_start];
        visit[i] = 0;
        pre[i] = num_start;
    }
    dist[num_start]=0;
    visit[num_start]=1;

    for(int i=2; i<=num_nations; i++){
        int mindist = INT32_MAX;
        int u = num_start;
        for(int j=1; j<=num_nations;j++){
            if((!visit[j]) && dist[j]<mindist){
                u = j;
                mindist = dist[j];
            }
        }
        visit[u] = true; 
        for(int j=1; j<=num_nations;j++){
            if((!visit[j]) && edges[u][j]<INT32_MAX){
                if(dist[u] + edges[u][j] < dist[j]){
                    dist[j] = dist[u] + edges[u][j];
                    pre[j] = u;
                }
            }
        }
    }
}

int main(){
    cin>>T;

    for(int l=0;l<T;l++){
        cin>>num_nations>>num_edges>>num_start>>num_end;
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++) edges[i][j]=INT32_MAX;
        }
        for(int i=0;i<num_edges;i++){
            int start,end,weight;
            cin>>start>>end>>weight;
            if(edges[start][end]>weight) edges[start][end]=edges[end][start]=weight;
        }
        edges[num_start][num_start]=0;
        dijkstra();
        if(dist[num_end]!=INT32_MAX) cout<<dist[num_end]<<endl;
        else cout<<-1<<endl;
    }
}