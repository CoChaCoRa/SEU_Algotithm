#include <iostream>
using namespace std;

int length;
int res[1000];
int MergeSort(int array[],int front,int end,int depth);
int Merge(int array[],int front,int end,int mid,int depth);

int main(){
    int m;
    cin>>m;
    cin.get();

    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        length = n;
        int *tmp = new int[n];
        for(int j=0;j<n;j++) cin>>tmp[j];
        MergeSort(tmp,0,n-1,1);
        //for(int j=0;j<n;j++) cout<<tmp[j]<<' ';
        //cout<<endl;
        for(int j=0;j<n;j++) cout<<res[j]<<' ';
        cout<<endl;
        delete []tmp;
    }
}

int MergeSort(int array[],int front,int end,int depth){
    if(front>=end) return 0;
    int mid = (front+end)/2;
    MergeSort(array,front,mid,depth+1);
    MergeSort(array,mid+1,end,depth+1);
    Merge(array,front,end,mid,depth);
}

int Merge(int array[],int front,int end,int mid,int depth){
    int *left_array = new int[mid-front+1];
    int *right_array = new int[end-mid];
    for(int i=0;i<mid-front+1;i++) left_array[i]=array[i+front];
    for(int i=0;i<end-mid;i++) right_array[i]=array[i+mid+1];
    int idx_left=0,idx_right=0;
    int idx=front;
    while((idx_left<mid-front+1)&&(idx_right<end-mid)){
        array[idx++] = (left_array[idx_left]<=right_array[idx_right])? left_array[idx_left++]:right_array[idx_right++];
    }
    if(idx_left<mid-front+1){
        for(int i=idx;i<=end;i++){
             array[i] = left_array[idx_left++];
        }
    }
    if(idx_right<end-mid){
        for(int i=idx;i<=end;i++){
             array[i] = right_array[idx_right++];
        }
    }

    if(depth==3){
        for(int i=front; i<=end; i++) {
            res[i] = array[i];
        }
    }

    return 0;
}