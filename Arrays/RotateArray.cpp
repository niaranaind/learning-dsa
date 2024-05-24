#include<iostream>
#include<vector>
using namespace std;

void RotateArray(vector<int> &arr,int k){

    //we know that %n = [0 -> (n-1)]
    int n = arr.size();
    vector<int> temp(n) ;

    for(int i=0;i< arr.size();i++){

        temp[(i+k)%n] = arr[i];
    }

    //copying 
    arr = temp;
}

void print(vector<int> arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> v;

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    RotateArray(v,2);

    print(v);
    return 0;
}