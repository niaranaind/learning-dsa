#include<iostream>
using namespace std;

class solution{

    public:
    string removeDuplicates(string s){
        int i = 0;
        while(i<s.length()){

            if(s[i] == s[i+1]){
                s.erase(i,2);
                i=0;
                continue;
            }
            i++;
        }
        return s;
    }
};

int main(){

    string str;
    cout<<"Enter the string: ";
    cin>>str;

    solution sol;
    cout<<"After removing Duplicate: "<<sol.removeDuplicates(str)<<endl;

    return 0;
}