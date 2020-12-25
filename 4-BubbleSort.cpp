#include<iostream>
using namespace std;

int main(){
    int m;
    cin>>m;
    cin.get();

    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        int *tmp = new int[n];
        for(int j=0;j<n;j++) cin>>tmp[j];
        for(int j=0;j<n-1;j++){
            if(tmp[j]>tmp[j+1]){
                int temp = tmp[j];
                tmp[j]=tmp[j+1];
                tmp[j+1]=temp;
            }
        }
        for(int j=0;j<n;j++) cout<<tmp[j]<<' ';
        cout<<endl;
        delete []tmp;
    }
}