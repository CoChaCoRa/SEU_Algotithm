#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *c = new int[n];
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        c[i]=a+b;
    }
    for(int i=0;i<n;i++){
        cout<<c[i]<<endl;
    }
    delete []c;
}