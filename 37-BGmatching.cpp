#include<iostream>
#include<memory.h>
using namespace std;

int T;
int m,n;
int visit[51]={0};
int girl[51]={0};
int edge[51][51]={0};

bool find(int x){
	int i,j;
	for (j=1;j<=m;j++){
		if (edge[x][j]==1 && visit[j]==false){
			visit[j]=1;
			if (girl[j]==0 || find(girl[j])) { 
				girl[j]=x;
				return true;
			}
		}
	}
	return false;
}

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>m;
        memset(visit,0,sizeof(visit));
        memset(girl,0,sizeof(girl));
        memset(edge,0,sizeof(edge));
        for(int i=1;i<=n;i++){
            int K;
            cin>>K;
            for(int k=0;k<K;k++){
                int j;
                cin>>j;
                edge[i][j]=1;
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            memset(visit,0,sizeof(visit));
            if(find(i)) res+=1;
        }
        cout<<res<<endl;
    }
}