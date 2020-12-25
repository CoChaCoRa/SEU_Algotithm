#include<iostream>
#include<algorithm>
using namespace std;

int T,N;

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        long long c[100001],y[100001];
        for(int i=1;i<=N;i++) cin>>c[i];
        for(int i=1;i<=N;i++) cin>>y[i];
        long long sum=0;
        for(int i=1;i<=N;i++){
            if(i>1) c[i]=min(c[i],c[i-1]+1);
            sum += c[i]*y[i];
        }
        cout<<sum<<endl;
    }
}