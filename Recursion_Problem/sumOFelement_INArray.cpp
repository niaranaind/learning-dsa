/*sum of all the element of array using recursion in c++ programming */

#include<iostream>
using namespace std;

class solution{

    public:

    int getSum(int arr[],int size){

        //base case
        if(size==0){

            return 0;
        }
        if(size==1){
            return arr[0];
        }

        //recursive relation
        int remainingPart=getSum(arr+1,size-1);
        int sum= arr[0]+remainingPart;

        return sum;
    }
};

int main(){

    int arr[100];
    int size;

    cout<<"enter the size of array: ";
    cin>>size;

    cout<<"enter the element of array: ";
    for(int i=0;i<size;i++){

        cin>>arr[i];
    }

    solution sr;

    cout<<"the sum of all element of array is: "<<sr.getSum(arr,size)<<endl;

    return 0;
}