#include<iostream>
#include<vector>
using namespace std;

class solution{

    private:
    void solve (vector<int> nums,vector<vector<int>> &ans,int index){

        //base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            //back tracking
            swap(nums[index],nums[i]);
        }
    }

    public:
    vector<vector<int>> permute(vector<int> &nums){

        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }

};

int main(){

    vector<int> nums={1,2,3};

    solution sr;

    vector<vector<int>> ans=sr.permute(nums);

    //printing solution

    for(int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++){

            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}