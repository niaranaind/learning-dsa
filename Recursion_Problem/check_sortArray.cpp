/*checking wether an array is sorted or Not using recursion */
#include<iostream>
using namespace std;

class solution{

    public:

    bool isSorted(int arr[],int size){

        //base case
        if(size==0 || size==1){
            return true;
        }

        if(arr[0]>arr[1]){

            return false;
        }
        else{

            bool ans=isSorted(arr+1,size-1);
            return ans;
        }
    }
};

int main(){

    int arr[100];
    int size;

    cout<<"enter the size of array: ";
    cin>>size;

    cout<<"enter the element in array: ";
    for(int i=0;i<size;i++){

        cin>>arr[i];
    }

    solution sr;

    if(sr.isSorted(arr,size)){

        cout<<"the array is sorted "<<endl;
    }
    else{

        cout<<"the array is Not sorted "<<endl;
    }

    return 0;
}

