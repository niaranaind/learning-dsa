#include<iostream>
using namespace std;

bool checkPalindrome(char a[],int n){

    int s = 0;
    int e = n-1;
    while(s<=e){

        if(a[s] != a[e]){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}

int getLength(char a[]){
    int count = 0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){

    char name[10];
    cout<<"Enter the char array: ";
    cin>>name;

    if(checkPalindrome(name,getLength(name))){
        cout<<"char array is a palindrome "<<endl;
    }
    else{
        cout<<"char array is NOT a palindrome "<<endl;
    }

    return 0;
}