#include<iostream>
#include<vector>
using namespace std;

class solution{

    private:
    void solve(string str,string output,int index,vector<string> &ans){

        //base case
        if(index>=str.length()){

            if(output.length()>0)
            ans.push_back(output);
            return;
        }

        //excluding recursive call
        solve(str,output,index+1,ans);

        //including recursive call
        char element=str[index];
        output.push_back(element);
        solve(str,output,index+1,ans);

    }

    public:
    vector<string> subsequence(string str){

        vector<string> ans;
        string output="";
        int index=0;

        solve(str,output,index,ans);

        return ans;
    }
};

int main(){

    string str="abc";

    solution sr;

    vector<string> ans=sr.subsequence(str);

    for(int i=0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}