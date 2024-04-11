#include<iostream>
using namespace std;

class solution{

    public:
     // normal bonary search algorithm using while loop
     int BinarySearch(int arr[],int size,int key){

        int start =0;
        int end=size-1;

        int mid=start+(end-start)/2;

        while(start<=end){

            if(arr[mid]==key){

                return mid;
            }

            else if(arr[mid]<key){

                start=mid+1;
            }
            else{

                end=mid-1;
            }

            mid =start+(end-start)/2;
        }

        return 0;
     }

     //binary search using recursion 

     bool binarySearchRecursion(int arr[],int s,int e,int key){

        //base case
        if(s>e)
        return false;

        int mid = s+(e-s)/2;

        if(arr[mid]== key){

            return true;
        }
        else if(arr[mid]<key){

            return binarySearchRecursion(arr,mid+1,e,key); // search in right part
        }
        else{

            return binarySearchRecursion(arr,s,mid-1,key); //search in left part
        }
     }
     
};

int main(){

    //array is sorted order
    int arr[100]={1,2,3,4,5,6,7,9};

    int size=8;

    int key;
    cout<<"enter the key: ";
    cin>>key;

    solution sr;

    if(sr.BinarySearch(arr,size,key)){

        cout<<"the key is PRESENT "<<endl;
        cout<<"the key is present in Index: "<<sr.BinarySearch(arr,size,key)<<endl;
    }
    else{

        cout<<"the key is NOT present "<<endl;
    }

    //binary search using recursion 

    if(sr.binarySearchRecursion(arr,0,size-1,key)){

        cout<<"the key is PRESENT "<<endl;
    }
    else{

        cout<<"the key is NOT PRESENT "<<endl;
    }
    return 0;
}