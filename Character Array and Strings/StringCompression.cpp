#include<iostream>
#include<vector>
using namespace std;

class solution{

    public:
    int compress(vector<char> &chars){

        int i=0;
        int ansIndex = 0;
        int n = chars.size();
        while(i<n){

            int j=i+1;
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            //when entire loop is traversed 
            //or new char is encounter
            chars[ansIndex] = chars[i];
            ansIndex++;

            int count = j-i;

            if(count>1){
                string str = to_string(count);
                for(int k=0;str[k]!='\0';k++){
                    chars[ansIndex++]=str[k];
                }
            }

            i=j;
        }
        return ansIndex;
    }
};

int main(){

    vector<char> chars(7);
    cout<<"Enter the chars: ";
    for(int i=0;i<chars.size();i++){
        cin>>chars[i];
    }

    solution sol;

    cout<<"Output: "<<sol.compress(chars)<<endl;
    return 0;
}