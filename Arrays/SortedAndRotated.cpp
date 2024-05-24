//ckeck if array is sorted and rotated

#include<iostream>
#include<vector>
using namespace std;

bool checkRotatedAndSorted(vector<int> &nums){

    int check = false;
    int pairs=0;
    for(int i=1;i<nums.size();i++){

        if(nums[i-1] >nums[i]){
            pairs++;
        }
    }

    if(nums[0] <  nums[nums.size()-1])
    pairs++;

    if(pairs<=1)
    check = true;

    return check;
}

int main(){

    vector<int> v;

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    if(checkRotatedAndSorted(v)){
        cout<<"Array is sorted and rotated"<<endl;
    }
    else{
        cout<<"Array is NOT sorted and rotated"<<endl;
    }
    return 0;
}