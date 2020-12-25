#include <iostream>
using namespace std;

int M,N;
int inv_cnt;

int MergeSort(int array[],int front,int end);
int Merge(int array[],int front,int end,int mid);

int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N;
        int *tmp = new int[N];
        for(int j=0;j<N;j++) cin>>tmp[j];
        inv_cnt = 0;
        inv_cnt = MergeSort(tmp,0,N-1);
        //for(int j=0;j<N;j++) cout<<tmp[j]<<' ';
        //cout<<endl;
        cout<<inv_cnt<<endl;
        delete []tmp;
    }
}

int MergeSort(int array[],int front,int end){
    if(front>=end) return 0;
    int mid = (front+end)/2;
    inv_cnt = MergeSort(array,front,mid) + MergeSort(array,mid+1,end);
    int cnt = Merge(array,front,end,mid);
    return cnt;
}

int Merge(int array[],int front,int end,int mid){
    int *left_array = new int[mid-front+1];
    int *right_array = new int[end-mid];
    for(int i=0;i<mid-front+1;i++) left_array[i]=array[i+front];
    for(int i=0;i<end-mid;i++) right_array[i]=array[i+mid+1];
    int idx_left=0,idx_right=0;
    int idx=front;
    while((idx_left<mid-front+1)&&(idx_right<end-mid)){
        //array[idx++] = (left_array[idx_left]<=right_array[idx_right])? left_array[idx_left++]:right_array[idx_right++];
        if(left_array[idx_left]<=right_array[idx_right]){
            array[idx++] = left_array[idx_left++];
            inv_cnt += idx_right;
        }
        else{
            array[idx++] = right_array[idx_right++];
        }
    }
    if(idx_left<mid-front+1){
        for(int i=idx;i<=end;i++){
             array[i] = left_array[idx_left++];
             inv_cnt += idx_right;
        }
    }
    if(idx_right<end-mid){
        for(int i=idx;i<=end;i++){
             array[i] = right_array[idx_right++];
        }
    }

    delete []left_array;
    delete []right_array;
    return inv_cnt;
}