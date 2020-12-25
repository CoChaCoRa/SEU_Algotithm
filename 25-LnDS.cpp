#include<iostream>
using namespace std;

int M,N;
int a[10000];
int dp_2[10000];
int res_system=0;

int main(){
    cin>>M;
    int *res = new int[M];
    for(int i=0;i<M;i++){
        cin>>N;
        for(int j=0;j<N;j++) cin>>a[j];
        for(int j=0;j<N;j++) dp_2[j]=1;
        for(int j=0;j<N;j++){
            for(int k=0;k<j;k++){
                if(a[j]>=a[k]) dp_2[j] = (dp_2[k]+1>dp_2[j])? dp_2[k]+1:dp_2[j];
            }
        }
        res_system = 0;
        for(int j=0;j<N;j++) res_system = (res_system>dp_2[j])? res_system:dp_2[j];
        //cout<<res_system<<endl;
        res[i]=res_system;
    }
    for(int i=0;i<M;i++) cout<<res[i]<<endl;
}