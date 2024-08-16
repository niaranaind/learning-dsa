#include<iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    //constructor
    Heap(){
        this->arr[0] = -1;
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
            return;
        }

        //step  1: put last element in place of root value
        arr[1] = arr[size];
        size--;

        //step 2: take root node to its correct position
        int i = 1;
        while(i<size){

            int leftIndex = 2*i;
            int rightIndex = 2*i +1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){

                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){

                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return ;
            }
        }
    }

    void print(){
        for(int i = 1; i<=size ; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){

    //write your test code here
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

    return 0;
}