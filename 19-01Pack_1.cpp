#include<iostream>
#include<math.h>
using namespace std;

int M,N,C;
int v[501],s[501];
int dp[501][101];

int main(){
    cin>>M;

    for(int i=0;i<M;i++){
        cin>>N>>C;
        for(int j=1;j<=N;j++) cin>>s[j]>>v[j];

        for(int j=0;j<=C;j++) dp[0][j]=0;
        for(int j=1;j<=N;j++) dp[j][0]=0;

        for(int j=1;j<=N;j++){
            for(int k=1;k<=C;k++){
                if(k<s[j]) dp[j][k]=dp[j-1][k];
                else dp[j][k] = max(dp[j-1][k-s[j]]+v[j],dp[j-1][k]);
            }
        }
        cout<<dp[N][C]<<endl;
    }
}