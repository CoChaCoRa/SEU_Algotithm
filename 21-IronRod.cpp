#include<iostream>
#include<math.h>
using namespace std;

int M,N,K;
int dp[10001];

int main(){
    cin>>M;

    for(int x=0;x<M;x++){
        cin>>N>>K;
        int length,profit;
        int p[10001]={0};
        for(int i=0;i<K;i++){
            cin>>length>>profit;
            if(length<=N) p[length]=profit;
        }
        dp[0]=0;
        for(int j=1;j<=N;j++){
            int temp = INT16_MIN;
            for(int i=1;i<=j;i++){
                temp = max(temp,p[i]+dp[j-i]);
            }
            dp[j]=temp;
        }
        cout<<dp[N]<<endl;
    }
}



/*
#include<iostream>
#include<math.h>
#include<unordered_map>
using namespace std;

int M,N,K;
int dp[10001];

int main(){
    cin>>M;

    for(int x=0;x<M;x++){
        cin>>N>>K;
        int length,profit;
        unordered_map<int,int> p;
        for(int i=0;i<K;i++){
            cin>>length>>profit;
            p.insert(make_pair(length,profit));
        }
        dp[0]=0;
        for(int j=1;j<=N;j++){
            int temp = INT32_MIN;
            for(int i=1;i<=j;i++){
                int tmp_p=0;
                auto iter = p.find(i);
                if(iter!=p.end()) tmp_p = iter->second;
                temp = max(temp,tmp_p+dp[j-i]);
            }
            dp[j]=temp;
        }
        cout<<dp[N]<<endl;
    }
}
*/