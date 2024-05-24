#include<iostream>
using namespace std;

class solution{

    private:
    bool valid(char ch){
        if((ch>= 'a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }
        else{
            return false;
        }
    }

    char toLowerCase(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return ch;
        }
        else{
            char temp = ch-'A'+'a';
            return temp;
        }
    }

    public:

    bool checkPalindrome(string s){

        string temp="";
        //faltu k char ko hatao
        for(int i=0;s[i] !='\0';i++){

            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }

        //sab uppercase ko lower case kar do
        for(int j=0;temp[j] != '\0';j++){

            temp[j] = toLowerCase(temp[j]);
        }

        int start = 0;
        int end = temp.length()-1;

        while(start<=end){

            if(temp[start] != temp[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;

    }
};

int main(){

    string str;
    cout<<"Enter the input string: ";
    cin>>str;

    solution sol;

    if(sol.checkPalindrome(str)){
        cout<<"Valid Palindrome "<<endl;
    }
    else{
        cout<<"NOT a valid Palindrome "<<endl;
    }

    return 0;
}