#include<iostream>
using namespace std;

char toLowerCase(char ch){

    if(ch>= 'a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch-'A'+'a'; //converting upper case letter into lower case
        return temp;
    }
}

bool CheckPalindrome(char a[],int n){

    int s = 0;
    int e = n-1;
    while(s<=e){
        
        if(toLowerCase(a[s]) != toLowerCase(a[e])){
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
    for(int i=0;a[i] !='\0';i++){
        count++;
    }
    return count;
}

int main(){

    char word[10];
    cout<<"Enter the char array: ";
    cin>>word;

    if(CheckPalindrome(word,getLength(word))){
        cout<<"char array is a Palindrome "<<endl;
    }
    else{
        cout<<"char array is NOT palindrome "<<endl;
    }

    return 0;
}