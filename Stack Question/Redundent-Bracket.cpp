#include<iostream>
#include<stack>
using namespace std;

class solution{

    public:
    bool findRedundentBracket(string &s){

        stack<char> st;
        for(int i=0 ; i< s.length(); i++){
            char ch = s[i];

            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else{
                //ch is close bracket or lower case letter
                if(ch == ')'){
                    bool isRedundent = true;

                    while(st.top() != '('){
                        char top = st.top();
                        if(top == '+' || top == '-' || top == '*' || top == '/'){
                            isRedundent = false;
                        }
                        st.pop(); //poping the operator
                    }
                    if(isRedundent == true)
                    return true;
                    st.pop(); //poping the opening bracket
                }
            }
        }
        return false;
    }
};

void print(string str){

    for(int i=0; str[i] != '\0'; i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
}

int main(){

    string exp = "((a+b))";
    print(exp);

    solution sol;
    if(sol.findRedundentBracket(exp)){

        cout<<"Redundent bracket is Present "<<endl;
    }
    else{
        cout<<"Redundent bracket is NOT Present "<<endl;
    }

    return 0;

}