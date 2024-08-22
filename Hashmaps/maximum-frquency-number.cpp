#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class solution{
    public:
    int maximumFrequency(vector<int> &arr,int n){

        unordered_map<int,int> count;
        int maxfreq = 0;
        int maxAns = 0;

        for(int i = 0; i<n ;i++){

            count[arr[i]]++;
            maxfreq = max(maxfreq,count[arr[i]]);
        }

        for(int i = 0 ; i<n ; i++){

            if(maxfreq == count[arr[i]]){
                maxAns = arr[i];
                break;
            }
        }

        return maxAns;
    }
};

int main(){
    //write your test code here
    vector<int> arr = {4,5,1};

    solution sr;
    cout<<"maximum frequency number is : "<<sr.maximumFrequency(arr,arr.size())<<endl;

    return 0 ;
}