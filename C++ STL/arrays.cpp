#include<iostream>
#include<array>
using namespace std;

int main(){

    int basic[4] = {1,2,3,4};

    array<int,4> a = {1,2,3,4};

    int size = a.size();

    cout<<"size of the STL array is: "<<size<<endl;

    //printing the element of stl library 
    for(int i=0;i<size;i++){

        cout<<a[i]<<endl;
    }

    cout<<"value at index = 2 : "<<a.at(2)<<endl;

    cout<<" array is empty or not: "<<a.empty()<<endl;

    cout<<" first element of array : "<<a.front()<<endl;

    cout<<"last element of array : "<<a.back()<<endl;

    return 0;
}