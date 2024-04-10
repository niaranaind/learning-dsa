#include<iostream>
using namespace std;

class solution{

    public:

    void sayDigit(int n,string arr[]){

        //base case
        if(n==0)
        return;

        //processing part
        int digit=n%10;
        n=n/10;

        //recursive relation
        sayDigit(n,arr);

        cout<<arr[digit]<<" ";  //head recursion
    }
};

int main(){

    string arr[10]={"zero","one","two","three","four","five","six","seven","eigth","nine"};

    solution sr;

    int n;
    cout<<"enter the number: ";
    cin>>n;

    sr.sayDigit(n,arr);

    return 0;

}