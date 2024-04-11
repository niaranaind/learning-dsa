#include<iostream>
using namespace std;

class solution{

    public:

    bool checkPalindrome(string str){   //using two pointer approach 

        int start=0;
        int end=str.length()-1;

        while(start<=end){

            if(str[start]!= str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool ispalindrome(string str,int s,int e){   //using two pointer approach and recursion 

        //base case
        if(s>e){

            return true;
        }

        if(str[s]!=str[e]){

            return false;
        }
        else{
            s++;
            e--;
            bool ans=ispalindrome(str,s,e);  //recursion call
            return ans;
        }
    }
};

int main(){

    string str="abbccbba";
    solution sr;

    //using two pointer approach
    if(sr.checkPalindrome(str)){

        cout<<"string is a palindrome "<<endl;
    }
    else{

        cout<<"string is NOT a palindrome "<<endl;
    }

    //using recursion approach
    if(sr.ispalindrome(str,0,str.length()-1)){

        cout<<"string is a palindrome "<<endl;
    }
    else{

        cout<<"string is NOT a palindrome "<<endl;
    }

    return 0;
}