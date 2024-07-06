#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class solution{

    public:
    vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){

        deque<long long int> q;
        vector<long long int> ans;

        //creating first window and processing
        for(int i = 0; i<K ; i++){
            int num = A[i];
            if(num<0)
            q.push_back(i);
        }
        
        //store answer for first window
        if(q.size()>0){
            ans.push_back(A[q.front()]);
        }
        else{
            ans.push_back(0);
        }

        //creating next window and processing
        for(int i = K; i < N ; i++){

            //removal logic
            if(!q.empty() && i - q.front() >= K){
                q.pop_front();
            }

            //addition logic
            if(A[i]<0){
                q.push_back(i);
            }

            //store answer
            if(q.size()>0){
                ans.push_back(A[q.front()]);
            }
            else{
                ans.push_back(0);
            }

        }

        return ans;

    }
};

int main(){

    long long int a[] = {-8,2,3,-6,10};

    solution s;
    vector<long long int> ans = s.printFirstNegativeInteger(a,5,2);

    for(int i= 0 ;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}