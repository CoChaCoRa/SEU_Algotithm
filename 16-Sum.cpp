#include<iostream>
#include<set>
using namespace std;

int M,N,X;
int a[50001];

int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N>>X;
        set<int> nums;
        for(int j=0;j<N;j++) {
            cin>>a[j];
            nums.insert(a[j]);
        }
        int flag=0;
        for(int j=0;j<N;j++){
            int target = X - a[j];
            if(nums.find(target)!=nums.end()) flag = 1;
        }
        if(flag==1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}