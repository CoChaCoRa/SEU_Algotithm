#include<iostream>
#include<math.h>
using namespace std;

int M,N,K;

int main(){
    cin>>M;
    for(int t=0;t<M;t++){
        long long sum[21];
        long long dp[21][21]={0};
        cin>>N>>K;
        sum[0]=0;
        for(int i=1;i<=N;i++){
            int temp;
            cin>>temp;
            sum[i]=sum[i-1]+temp;
        }
        for(int i=1;i<=N;i++) dp[i][0]=sum[i];
        for(int i=2;i<=N;i++){
            for(int j=1;j<i && j<=K;j++){
                for(int k=2;k<=i;k++){
                    dp[i][j]=max(dp[i][j],dp[k-1][j-1]*(sum[i]-sum[k-1]));
                }
            }
        }
        cout<<dp[N][K]<<endl;
    }
}