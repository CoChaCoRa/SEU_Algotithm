#include <iostream>
using namespace std;

int length;
int res[1000]={0};

int partition(int array[], int low, int high,int depth);
void QuickSort(int array[], int low, int high,int depth);

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
        QuickSort(tmp,0,n-1,1);
        for(int j=0;j<n;j++) cout<<res[j]<<' ';
        cout<<endl;

        delete []tmp;
    }
}

int partition(int array[], int low, int high,int depth){
    int pivot = low;
	for(int i=low+1;i<=high;i++){
        if(array[i]<array[low]){
            int temp = array[pivot+1];
            array[pivot+1] = array[i];
            array[i] = temp;
            pivot++;
        }
    }
    int temp = array[low];
	array[low] = array[pivot];
    array[pivot] = temp;

    if(depth==1) {
        res[pivot]=array[pivot];    
    }
    if(depth==2) {
        for(int i=low; i<=high; i++) {
            res[i] = array[i];
        }
    }

	return pivot;
}

void QuickSort(int array[], int low, int high,int depth){
    if(low<high){
        int pivot = partition(array, low, high,depth);
		QuickSort(array, low, pivot - 1, depth+1);
		QuickSort(array, pivot + 1, high, depth+1);
    }
}