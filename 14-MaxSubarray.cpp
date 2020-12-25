#include<iostream>
#include<math.h>
using namespace std;

int M,N;
int a[50001];
int dp[50001];
int Max;

int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N;
        for(int j=0;j<N;j++) cin>>a[j];

        for(int j=0;j<N;j++) dp[j]=a[j];
        for(int j=1;j<N;j++){
            dp[j] = max(dp[j-1]+a[j],a[j]);
        }

        Max=INT32_MIN;

        for(int j=0;j<N;j++){
            Max = (Max>dp[j])? Max:dp[j];
        }
        cout<<Max<<endl;
    }
}