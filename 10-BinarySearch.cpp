#include<iostream>
using namespace std;

int a[20000];
int M,N,X;

int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N>>X;
        for(int j=0;j<N;j++) cin>>a[j];
        //cout<<N<<X<<endl;
        //for(int j=0;j<N;j++) cout<<a[j];
        int flag=0;
        int low=0,high=N-1;
        int mid = (low + high)/2;
        int father = a[mid];
        while (low <= high) {
            father = a[mid];
            mid = (low + high)/2;
            //cout<<"father = "<<father<<endl;
            if (a[mid] == X){
                cout<<"success, father is "<<father<<endl;
                flag=1;
            }
            if (X < a[mid]) high = mid - 1;
            else low = mid + 1;
        }
        if(flag != 1) cout<<"not found, father is "<<a[mid]<<endl;
    }
}