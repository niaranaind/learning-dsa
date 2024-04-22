#include<iostream>
using namespace std;

class sorting{

    public:

    int partition(int arr[],int s,int e){

        int pivot =arr[s];
        int cnt=0;

        for(int i=s+1;i<=e;i++){

            if(arr[i]<=pivot)
            cnt++;
        }

        //place pivot at rigth position
        int pivotIndex=s+cnt;
        swap(arr[pivotIndex],arr[s]);

        //left and right part should satisfy the condition
        int i=s;
        int j=e;

        while(i<pivotIndex && j>pivotIndex){

            while(arr[i]<= pivot){
                i++;
            }

            while(arr[j]>pivot){
                j--;
            }

            if(i<pivotIndex && j>pivotIndex)
            swap(arr[i],arr[j]);
        }

        return pivotIndex;

    }

    void quickSort(int *arr,int s,int e){

        //base base
        if(s>=e){
            return ;
        }

        //partion function
        int p=partition(arr,s,e);

        //recursive call
        quickSort(arr,s,p-1);   //sorting left part
        quickSort(arr,p+1,e);    //sorting rigth part
    }

};

int main(){

    int arr[5]={2,4,1,6,9};
    int n=5;

    sorting sr;

    sr.quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}