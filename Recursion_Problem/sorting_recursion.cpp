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

class recursionSorting{

    public:

    void bubbleRecursion(int arr[],int n){

        //base case
        if(n==0 || n==1)
        return;

        for(int i=0;i<n-1;i++){

            if(arr[i]>arr[i+1]){

                swap(arr[i],arr[i+1]);
            }
        }

        bubbleRecursion(arr,n-1);

    }

    void selectionRecursion(int arr[],int n,int i){

        //base case
        if(n==0 || n==1){
            return ;
        }

        int minIndex=i;
        for(int i=minIndex+1;i<n;i++){

            if(arr[minIndex]>arr[i]){
                minIndex=i;
            }
        }
        swap(arr[minIndex],arr[i]);

        selectionRecursion(arr,n-1,i+1);
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

    // sr.selectionSorting(arr,6);

    // sr.print(arr,6);

    sr.bubbleSorting(brr,6);

    sr.print(brr,6);

    sr.insertionSorting(crr,6);

    sr.print(crr,6);

    recursionSorting s;

    s.bubbleRecursion(arr,6);

    s.print(arr,6);

    s.selectionRecursion(arr,6,0);

    s.print(arr,6);

    return 0;
}