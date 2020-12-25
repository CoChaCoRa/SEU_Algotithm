#include<iostream>
using namespace std;

int M,N;
int a[100];
int dp_1[100],dp_2[100];
int res_missile=0,res_system=0;

int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N;
        for(int j=0;j<N;j++) cin>>a[j];
        for(int j=0;j<N;j++) dp_1[j]=1;
        for(int j=0;j<N;j++) dp_2[j]=1;
        for(int j=0;j<N;j++){
            for(int k=0;k<j;k++){
                if(a[j]<=a[k]) dp_1[j] = (dp_1[k]+1>dp_1[j])? dp_1[k]+1:dp_1[j];
                if(a[j]>=a[k]) dp_2[j] = (dp_2[k]+1>dp_2[j])? dp_2[k]+1:dp_2[j];
            }
        }
        res_missile = res_system = 0;
        for(int j=0;j<N;j++) res_missile = (res_missile>dp_1[j])? res_missile:dp_1[j];
        for(int j=0;j<N;j++) res_system = (res_system>dp_2[j])? res_system:dp_2[j];
        //cout<<res_missile<<' '<<res_system<<endl;
        cout<<res_system<<endl;
    }
}