// linaer search in array using recursion concept in c++ programming 

#include<iostream>
using namespace std;

class solution{

    public:

    bool linearSearch(int arr[],int size,int key){

        //base case
        if(size==0){
            return false;
        }

        if(arr[0]==key){

            return true;
        }
        else{
            bool ans=linearSearch(arr+1,size-1,key);
            return ans;
        }
    }
};

int main(){

    int arr[5]={1,2,3,4,5};

    int size =5;

    int key;
    cout<<"enter the key: ";
    cin>>key;

    solution sr;

    if(sr.linearSearch(arr,size,key)){

        cout<<"key is Present "<<endl;
    }
    else{

        cout<<"key is NOT present "<<endl;
    }

    return 0;
}