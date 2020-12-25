#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int start;
    int end;
    int weight;
};

int T;

int cmp_weight(const void *a , const void *b){
    edge *p1 = (edge *)a;
    edge *p2 = (edge *)b;
    return p1->weight - p2->weight;
}

int node[501];

void Init(int n){
    for(int i=1;i<=n;i++) node[i]=i;
}

int find_root(int x){
    if(x==node[x]) return x;
    else return find_root(node[x]);
}

bool same(int x,int y){
    if(find_root(x)==find_root(y)) return true;
    else return false;
}

void unite(int x,int y){
    int root_x = find_root(x);
    int root_y = find_root(y);
    if(root_x != root_y) node[root_x]=root_y;
}

int kruskal(edge a[],int n,int num_node){
    int W=0;
    int visit[501]={0};
    Init(num_node);

    for(int i=0;i<n;i++){
        if(!same(a[i].start,a[i].end)){
            W += a[i].weight;
            unite(a[i].start,a[i].end);
            visit[a[i].start]=visit[a[i].end]=1;
        }
    }
    for(int i=1;i<=num_node;i++){
        if(visit[i]==0) return -1;
    }
    return W;
}

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        int n,E;
        cin>>n>>E;
        edge edges[20000];
        for(int i=0;i<E;i++){
            cin>>edges[i].start>>edges[i].end>>edges[i].weight;
        }
        qsort(edges,E,sizeof(edge),cmp_weight);
        cout<<kruskal(edges,E,n)<<endl;
    }
}