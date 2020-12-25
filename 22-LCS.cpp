#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int M;
int lcs[501][501];

int main(){
    cin>>M;

    for(int l=0;l<M;l++){
        string tmp1,tmp2;
        cin>>tmp1>>tmp2;
        int m,n;
        m=tmp1.length();
        n=tmp2.length();
        char x[m+1],y[n+1];
        for(int i=1;i<=m;i++) x[i]=tmp1[i-1];
        for(int i=1;i<=n;i++) y[i]=tmp2[i-1];

        for(int i=0;i<=m;i++) lcs[i][0]=0;
        for(int i=1;i<=n;i++) lcs[0][i]=0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i]==y[j]) lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        cout<<lcs[m][n]<<endl;
    }
}