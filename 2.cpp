#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.get();
    char buf[101];
    for(int i=0;i<n;i++){
        cin.getline(buf,101);
        int cnt=0;
        for(int i=0;buf[i]!='\0';i++){
            if(buf[i]>='0'&&buf[i]<='9') cnt++;
        }
        cout<<cnt<<endl;
    }
}