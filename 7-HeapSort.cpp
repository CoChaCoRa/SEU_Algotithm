#include <iostream>
using namespace std;

void heap_min(int array[],int end);

int main(){
    int m;
    cin>>m;
    cin.get();

    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        int *tmp = new int[n];

        for(int j=0;j<n;j++) cin>>tmp[j];
        heap_min(tmp,n-1);
        for(int j=0;j<n;j++) cout<<tmp[j]<<' ';
        cout<<endl;

        delete []tmp;
    }
}

void heap_min(int array[],int end){
    int parent = end;
    while(parent>=0){
        int child = 2*parent+1;
        while(child<=end){
            if(child+1<=end && array[child+1]<array[child]) child+=1;
            if(array[child]<array[parent]){
                int temp = array[parent];
                array[parent] = array[child];
                array[child] = temp;

                parent = child;
                child = 2*parent+1;
            }
            else break;
        }
        parent--;
    }
}