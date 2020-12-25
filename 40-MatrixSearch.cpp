#include<iostream>
using namespace std;

int T;
int m,n,target;

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>m>>n>>target;
        int a[1000][1000];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) cin>>a[i][j];
        }
        int left=n-1,up=0;
        int flag=0;
        while(left>=0 && up<m){
            if(target==a[up][left]){
                flag=1;
                break;
            }
            if(target<a[up][left]) left--;
            if(target>a[up][left]) up++;
        }
        if(flag==1) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}