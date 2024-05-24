#include<iostream>
using namespace std;

class solution{

    private:
    void Reverse(string &str,int s,int e){

        while(s<=e){
            swap(str[s],str[e]);
            s++;
            e--;
        }
    }

    public:
    string ReverseWord(string str){

        int i=0;
        int start = 0;
        while(i<=str.size()){

            if(str[i] == ' ' || str[i] == '\0'){
                Reverse(str,start,i-1);
                start = i+1;
            }
            i++;
        }
        Reverse(str,start,i-1);
        return str;

    }
};

int main(){

    string str;
    cout<<"Enter sentence input: ";
    getline(cin,str);

    solution sol;
    

    cout<<"Reverse word sentence: "<<sol.ReverseWord(str)<<endl;
    return 0;
}