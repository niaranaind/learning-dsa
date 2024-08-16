#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    //constructor
    Heap(){
        this->arr[1] = -1;
        this->size = 0;
    }

    void inserction(int value){
        
        size = size+1;
        int index = size;
        arr[index] = value;

        while(index > 1){

            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromHeap(){

        if(size == 0){
            cout<<"nothing to delete "<<endl;
            return ;
        }

        //step 1: put last element in place of root element
        arr[1] = arr[size];
        size--;

        //step 2:put root element in lts correct position
        int i = 1;
        while(i<size){

            int leftIndex = 2*i;
            int rightIndex = 2*i +1;
            
            if(leftIndex <= size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

void heapify1(int arr[],int n,int i){ //building max heap

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify1(arr,n,largest);
    }
}

void heapify2(vector<int> &arr,int n,int i){

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left] ){
        smallest = left;
    }

    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify2(arr,n,smallest);
    }
}

int main(){
    //write your test code here.
    Heap h;
    h.inserction(50);
    h.inserction(55);
    h.inserction(53);
    h.inserction(52);
    h.inserction(54);
    h.print();

    cout<<"deleting node "<<endl;
    h.deletefromHeap();
    h.print();

    //heapify algorithm
    int arr[6] = {-1,54,53,55,52,51};
    int n = 5;

    for(int i = n/2 ; i>0 ; i--){
        heapify1(arr,n,i);
    }

    cout<<"printing the array now"<<endl;
    for(int i = 1; i <=n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //heapify algorithm for min heap case
    vector<int> brr = {54,53,55,52,51};
    int m = 5;

    for(int i=m/2-1 ; i>=0 ;i--){
        heapify2(brr,m,i);
    }

    cout<<"printing the vector now "<<endl;
    for(int i = 0 ; i<m ; i++){
        cout<<brr[i] <<" ";
    }cout<<endl;

    return 0;
}