#include<iostream>
#include<stack>
using namespace std;

class solution{

    public:
    bool isValidParenthesis(string expression){

        stack<char> s;
        for(int i=0;i < expression.length() ; i++){

            char ch = expression[i];

            if(ch == '{' || ch == '[' || ch == '('){
                s.push(ch);
            }
            else{
                //ch is a close parenthesis
                if(!s.empty()){
                    char top  = s.top();
                    if((ch == ')' && top == '(' ) || (ch == '}' && top == '{' ) || (ch == ']' && top == '[' )){
                        s.pop();
                    }else{
                        return false;
                    }
                }
                else{
                    return false; //when stack is empty and closing bracket came
                }
            }
        }
        if(s.empty())
        return true;
        else
        return false;
    }
};

void print(string sr){

    for(int i=0 ; sr[i] != '\0' ; i++){
        cout<<sr[i]<<" ";
    }
    cout<<endl;
}



int main(){

    string exp = "[{}]";
    solution s;

    print(exp);
    
    if(s.isValidParenthesis(exp)){
        cout<<" this expression is a valid parenthesis "<<endl;
    }
    else{
        cout<<" this expression is NOT a valid parenthesis "<<endl;
    }

    return 0;
}