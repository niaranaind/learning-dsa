#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class solution{

    public:
    string FirstNonRepeating(string A){

        //creating unordered maps
        unordered_map<char,int> count;

        //queue
        queue<int> q;

        //ans string 
        string ans = "";
        for(int i = 0; i < A.length() ;i++){

            char ch = A[i];
            //store count value
            count[ch]++;
            //puch char in queue
            q.push(ch);
            while(!q.empty()){

                if(count[q.front()] > 1){
                    //repeating character
                    q.pop();
                }
                else{
                    //non repeating character
                    ans.push_back(q.front());
                    break;
                }
            }

            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
    }
};

int main(){

    string a ="aabc";
    solution s;
    string ans = s.FirstNonRepeating(a);
    cout<<ans<<endl;
    return 0;
}