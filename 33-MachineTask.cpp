#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct Task{
    int f;
    int v;
}a[60000];

int M,N;

int cmp_v(const void *a , const void *b){
    Task *p1 = (Task *)a;
    Task *p2 = (Task *)b;
    return p2->v - p1->v;
}

int main(){
    cin>>M;
    for(int t=0;t<M;t++){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>a[i].f>>a[i].v;
            if(a[i].f>N) a[i].f=N;
        }
        int p[60000]={0};
        long long res=0;
        qsort(a,N,sizeof(Task),cmp_v);

        for(int i=0;i<N;i++){
            for(int j=a[i].f;j>=1;j--){
                if(p[j]==0){
                    res += a[i].v;
                    p[j]=1;
                    break;
                }
            }
        }

        cout<<res<<endl;
    }
}