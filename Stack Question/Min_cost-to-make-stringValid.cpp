#include<iostream>
#include<stack>
using namespace std;

class solution{

    public:
    int findMinmumCost(string str){

        //odd condition
        if(str.length()%2 == 1){
            return -1;
        }

        stack<char> s;
        for(int i=0 ; i<str.length() ; i++){
            char ch = str[i];

            if(ch == '{'){
                s.push(ch);
            }
            else{
                //ch is close bracket 
                if(!s.empty() && s.top() == '{'){
                    s.pop();
                }
                else{
                    s.push(ch);
                }
            }
        }

        //stack contain invalid expression
        int a = 0 , b = 0;
        while(!s.empty()){

            if(s.top() == '{'){
                b++;
            }
            else{
                a++;
            }
            s.pop();
        }

        int ans = (a+1)/2 +(b+1)/2;
        return ans;
    }
};

int main(){

    string exp = "{{{}";

    solution sol;

    cout<<"the minimum cost to make a string valid is: "<<sol.findMinmumCost(exp)<<endl;

    return 0;

}