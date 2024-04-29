#include<iostream>
#include<vector>
using namespace std;

class solution{

    private:
    void solve(string digit,string output,int index,string mapping[],vector<string> &ans){
        //base case
        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }

        int number=digit[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){

            output.push_back(value[i]);
            solve(digit,output,index+1,mapping,ans);
            output.pop_back();
        }
    }

    public:
    vector<string> letterCombinations(string digit){

        vector<string> ans;

        if(digit.length()==0){
            return ans;
        }
        string output="";
        int index=0;
        string mapping[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digit,output,index,mapping,ans);

        return ans;
    }
};

int main(){

    string str="23";

    solution sr;

    vector<string> ans=sr.letterCombinations(str);

    for(int i=0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}