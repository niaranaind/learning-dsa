#include<iostream>
using namespace std;

bool checkpassword(string pass,int n){


    //check password containing lower case letter and digit
    for(int i=0;i<n;i++){
        if((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= '0' && pass[i] <= '9')){
            continue;
        }
        else{
            return false;
        }
    }

    //there should be no digit that come after letter
    for(int i=1;i<n;i++){
        int a = pass[i-1];
        int b = pass[i];
        if(a>b){
            return false;
        }
    }

    return true;
}

int main(){

    int t;
    cout<<"enter the number of test case: ";
    cin>>t;

    while(t--){

        int n;
    cout<<"enter the length og string: ";
    cin>>n;

    string str;
    cout<<"enter the string: ";
    cin>>str;
    
        if(checkpassword(str,n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}