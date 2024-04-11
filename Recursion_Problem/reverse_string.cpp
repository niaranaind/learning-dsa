#include<iostream>
using namespace std;

class solution{

    public:
    //reversing the string using two pointer approach
    void reverseString(string str){

        int s=0;
        int e=str.length()-1;

        while(s<=e){

            swap(str[s],str[e]);
            s++;
            e--;
        }

        cout<<str<<endl;
    }
    //reversing the string using recusion approach 
    void reverseStringRecursion(string& str,int s,int e){  //here we pass the string as reference variable 

        //base case
        if(s>e){
            return;
        }

        swap(str[s],str[e]);  //processing part
        s++;
        e--;

        //recursive call
        reverseStringRecursion(str,s,e);
    }
};

int main(){

    string str="abcde";

    solution sr;

    sr.reverseString(str);

    sr.reverseStringRecursion(str,0,str.length()-1);

    cout<<str<<endl;

    return 0;
}