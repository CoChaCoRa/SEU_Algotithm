#include<iostream>
using namespace std;

int main(){
    int m;
    cin>>m;
    cin.get();
    
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        cin.get();

        int min=1000,second=1001;
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp<min){
                second = min;
                min = tmp;
            }
            else if(tmp<second){
                second = tmp;
            }
        }
        cout<<second<<endl;;
    }
}