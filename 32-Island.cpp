#include<iostream>
#include<iomanip>
using namespace std;

int T,N;
double p[1001];
double dp[1001];

int main(){
    cin>>T;

    for(int t=0;t<T;t++){
        cin>>N;
        for(int i=1;i<N;i++){
            double prob;
            cin>>prob;
            p[i]=prob/100;
        }
        dp[1]=1;
        for(int i=2;i<=N;i++){
            dp[i]=dp[i-1]*(1-p[i-1])+(dp[i-1]+1)*p[i-1];
        }
        cout<<fixed<<setprecision(6)<<dp[N]<<endl;
    }
}