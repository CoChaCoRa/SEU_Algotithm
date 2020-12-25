#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct Activity{
    int s;
    int f;
    int v;
}a[10001];

int M,N;

int cmp_fs(const void *a , const void *b){
    Activity *p1 = (Activity *)a;
    Activity *p2 = (Activity *)b;
    if(p1->f != p2->f) {
        return p1->f - p2->f;
    }
    else {
        return p1->s - p2->s;
    }
}

int main(){
    cin>>M;
    for(int t=0;t<M;t++){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>a[i].s>>a[i].f>>a[i].v;
        }
        int p[10001]={0};
        int dp[10001]={0};
        qsort(a,N+1,sizeof(Activity),cmp_fs);
        //for(int i=1;i<=N;i++) cout<<a[i].s<<","<<a[i].f<<endl;
        for(int i=2;i<=N;i++){
            for(int j=i-1;j>0;j--){
                if(a[j].f<=a[i].s){
                    p[i]=j;
                    break;
                }
            }
        }
        //for(int i=1;i<=N;i++) cout<<p[i]<<endl;
        for(int i=1;i<=N;i++) dp[i]=max(dp[p[i]]+a[i].v,dp[i-1]);
        cout<<dp[N]<<endl;
    }
}