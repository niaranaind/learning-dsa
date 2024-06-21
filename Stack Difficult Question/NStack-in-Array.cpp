#include<iostream>

class NStack
{
    int *arr;
    int *top;
    int *next;
    int freespace;
    int n,s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //intitialize top array
        for(int i=0 ; i<n ; i++){
            top[i] = -1;
        }

        //initialize next array
        for(int i = 0 ; i<s ; i++ ){
            next[i] = i+1;
        }
        // update last index element of next array to -1
        next[s-1] = -1;

        //initialize freespace 
        freespace = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check overflow condition
        if( freespace == -1){
            return false;
        }

        //find index 
        int index = freespace;

        //update freespace 
        freespace = next[index];

        //insert the element 
        arr[index] = x;

        //update next array
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        //check underflow condition
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespace;
        freespace = index;

        return arr[index];
    }
};

int main(){

    //write your test case here
    return 0;
}