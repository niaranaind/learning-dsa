#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left] ){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){

    int size = n;
    while(size > 1){

        //step 1 swap root element with last element
        swap(arr[1],arr[size]);
        size--;

        //step 2 heapify algorithm
        heapify(arr,size,1);
    }
}

int main(){

    //heap creation
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr,n,i);
    }

    cout<<"printing the array "<<endl;
    for(int i = 1; i<=n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //heap sort
    heapSort(arr,n);

    cout<<"printing sorted array "<<endl;
    for(int i=1 ; i<=n ;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}