#include<iostream>
#include<vector>
using namespace std;

int T;
int n,m;
int stack[301];
int top;

int initstack(){
    top = -1;
}

int pop(){
    int temp = stack[top];
    top--;
    return temp;
}

int push(int x){
    top++;
    stack[top]=x;
    return top;
}

bool empty(){
    if(top==-1) return true;
    else return false;
}

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>m;
        int in[301]={0};
        int edge[301][301]={0};
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            edge[x][y]=1;
            in[y]+=1;
        }
        vector<int> res;
        initstack();
        for(int i=1;i<=n;i++){
            if(in[i]==0) push(i);
        }
        int count=0;
        while(!empty()){
            int node = pop();
            res.push_back(node);
            count++;
            for(int i=1;i<=n;i++){
                if(edge[node][i]==1){
                    in[i]--;
                    if(in[i]==0) push(i);
                }
            }
        }
        if(count<n) cout<<0<<endl;
        else{
            for(int i=0;i<n;i++) cout<<res[i]<<" ";
            cout<<endl;
        }
    }
}