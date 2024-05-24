#include<iostream>
#include<vector>
using namespace std;

void ReverseArray(vector<int> &nums){
    
    int s = 0;
    int e = nums.size()-1;
    while(s<=e){
        swap(nums[s],nums[e]);
        s++;
        e--;
    }
}

vector<int> findArraySum(vector<int> &a,int n,vector<int> &b,int m){

    //sum of two arrays a[n] and b[m]
    vector<int> ans;
    int sum = 0;
    int carry = 0;
    int value =0;

    int i=n-1;
    int j=m-1;
    while(i>=0 && j>=0){

        sum = a[i]+b[j]+carry;
        value = sum%10;
        carry = sum/10;
        ans.push_back(value);
        i--;
        j--;
    }

    //when size of a[n] > a[m]
    while(i>=0){
        sum = a[i]+carry;
        value = sum%10;
        carry = sum/10;
        ans.push_back(value);
        i--;
    }

    //when size of a[n] < a[m]
    while(j>=0){
        sum = b[j]+carry;
        value = sum%10;
        carry = sum/10;
        ans.push_back(value);
        j--;
    }

    ReverseArray(ans);
    return ans;
}

void print(vector<int> nums){

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> a;
    vector<int> b;

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    int m;
    cout<<"Enter the size of 2nd vector: ";
    cin>>m;
    for(int i=0;i<m;i++){
        int y;
        cin>>y;
        b.push_back(y);
    }

    vector<int> ans = findArraySum(a,n,b,m);

    print(ans);

    return 0;

}