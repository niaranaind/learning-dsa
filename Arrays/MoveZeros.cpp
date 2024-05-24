#include<iostream>
using namespace std;

void MoveZeros(int arr[],int n){

    //using loops
    int j = 0;
    for(int i=0;i<n;i++){

        if(arr[i] == 0){
            swap(arr[j],arr[i]);
            j++;
        }
    }
}

void print(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[5] = {0,1,0,3,12};

    MoveZeros(arr,5);

    print(arr,5);

    return 0;
}