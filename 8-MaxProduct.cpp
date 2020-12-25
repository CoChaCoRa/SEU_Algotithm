#include<iostream>
#include<string>
using namespace std;

unsigned long long dp[45][6];
unsigned long long number[45];
int N,K;

unsigned long long num(int front, int end){
    unsigned long long temp=0;
    for(int i=front;i<=end;i++){
        temp *= 10;
        temp = temp + number[i];
    }
    return temp;
}

int main(){
    int M;
    cin>>M;
    cin.get();

    int *res = new int[M];

    for(int i=0;i<M;i++){
        string in;
        cin>>N>>K>>in;
        //cout<<in<<endl;
        for(int i=0;i<45;i++){
            for(int j=0;j<6;j++) dp[i][j]=0;
        }
        for(int i=1;i<=N;i++) number[i]=in[i-1]-'0';
        for(int i=1;i<=N;i++) dp[i][0]=num(1,i);
        //cout<<number[1]<<endl;

        for(int i=2;i<=N;i++){
            int gap = (i-1<K)? i-1:K;
            for(int j=1;j<=gap;j++){
                for(int k=j;k<i;k++){
                    dp[i][j] = (dp[k][j-1]*num(k+1,i)>dp[i][j])? dp[k][j-1]*num(k+1,i):dp[i][j];
                }
            }
        }

        //cout<<dp[N][K]<<endl;;
        res[i] = dp[N][K];
    }
    for(int i=0;i<M;i++) cout<<res[i]<<endl;
}