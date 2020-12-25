#include<iostream>
#include<iomanip>
using namespace std;

int M,N;
int key[501];
double q[501];
double p[501];
double c[501][501];
double w[501][501];

void optimBST(double p[],double q[],int n){
    for(int i=0;i<=n;i++){
        c[i][i]=0;
        w[i][i]=q[i];
    }
    for(int x=1;x<=n;x++){
        for(int i=0;i<=n-x;i++){
            int j=i+x;
            c[i][j]=INT32_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            //if(i==0&&j==2){cout<<w[0][2]<<endl;}
            for(int k=i+1;k<=j;k++){
                double temp = w[i][j];
                temp += c[i][k-1];
                temp += c[k][j];
                if(temp<c[i][j]) {
                    c[i][j]=temp;
                    //cout<<"c["<<i<<"]["<<j<<"]="<<temp<<endl;
                }
            }
        }
    }
}

int main(){
    cin>>M;
    for(int t=0;t<M;t++){
        cin>>N;
        for(int i=0;i<N;i++) cin>>key[i];
        for(int i=1;i<=N;i++) cin>>p[i];
        for(int i=0;i<=N;i++) cin>>q[i];
        optimBST(p,q,N);
        //cout<<c[0][1]<<endl;
        cout<<fixed<<setprecision(6)<<c[0][N]<<endl;
    }
}