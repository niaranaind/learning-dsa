#include<iostream>
using namespace std;

class sortingAlgorithm{

    public:

    void selectionSorting(int arr[],int size){

        for(int i=0;i<size-1;i++){

            int minIndex=i;
            for(int j=i+1;j<size;j++){

                if(arr[minIndex]>arr[j]){

                    minIndex=j;
                }
            }

            swap(arr[minIndex],arr[i]);
        }
    }

    void bubbleSorting(int arr[],int size){

        for(int i=1;i<size;i++){

            for(int j=0;j<size-i;j++){

                if(arr[j]>arr[j+1]){

                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }

    void insertionSorting(int arr[],int n){

        for(int i=1;i<n;i++){

            int temp=arr[i];

            int j=i-1;
            for(;j>=0;j--){

                if(arr[j]>temp){
                    arr[j+1]=arr[j];
                }
                else{
                    break;
                    //out of loop
                }
            }
            arr[j+1]=temp;
        }
    }

    //printing function
    void print(int arr[],int size){

        for(int i=0;i<size;i++){

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    int arr[10]={1,5,2,3,7,6};

    int brr[10]={7,3,8,2,5,1};

    int crr[10]={7,3,8,2,5,1};

    sortingAlgorithm sr;

    sr.selectionSorting(arr,6);

    sr.print(arr,6);

    sr.bubbleSorting(brr,6);

    sr.print(brr,6);

    sr.insertionSorting(crr,6);

    sr.print(crr,6);

    return 0;
}