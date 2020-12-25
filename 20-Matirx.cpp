#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int M,N;

typedef struct{
    int row;
    int col;
} Matrix;

Matrix a[501];
int dp[501][501];

int main(){
    cin>>M;

    for(int x=0;x<M;x++){
        cin>>N;
        for(int i=1;i<=N;i++) cin>>a[i].row>>a[i].col;
        for(int i=1;i<=N;i++) dp[i][i]=0;

        for(int p=1;p<N;p++){
            for(int i=1;i<=N-p;i++){
                int j=i+p;
                dp[i][j]=INT32_MAX;
                for(int k=i;k<j;k++){
                    int cost = dp[i][k]+dp[k+1][j]+a[i].row*a[k].col*a[j].col;
                    if(cost<dp[i][j]) dp[i][j]=cost;
                }
            }
        }
        cout<<dp[1][N]<<endl;
    }
}