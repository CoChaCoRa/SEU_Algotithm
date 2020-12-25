#include<iostream>
using namespace std;

int T,n,m;

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>m;
        char *txt = new char[n];
        char *pat = new char[m];
        for(int i=0;i<n;i++) cin>>txt[i];
        for(int i=0;i<m;i++) cin>>pat[i];
        int next[100000]={-1};
        int k = -1, l = 0;
        while (l < m - 1) {
            if (k == -1 || pat[l] == pat[k]) {
                ++k; ++l;
                next[l] = k;
            } else {
                k = next[k];
            }
        }
        int i=0,j=0,res=0;
        while (i<n) {
            if (j == - 1 || txt[i] == pat[j]) {
                ++i; ++j;
            } else {
                j = next[j];
            }
            if(j==m) {
                res += 1;
                j=0;
            }
        }
        cout<<res<<endl;

        delete []txt;
        delete []pat;
    }
}