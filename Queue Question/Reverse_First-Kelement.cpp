#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class solution{

    public:
    queue<int> modifyQueue(queue<int> q, int k){

        stack<int> s;

        //step 1: push first k element in stack from queue
        for(int i= 0 ;i <k ; i++){
            int num = q.front();
            q.pop();
            s.push(num);
        }

        //step 2: push element in queue from stack
        while(!s.empty()){
            int num = s.top();
            s.pop();
            q.push(num);
        }

        //step 3: first push (n-k) element queue
        int t = q.size() - k;
        while(t--){
            int val = q.front();
            q.pop();
            q.push(val);
        }

        return q;
    }

};

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    solution s;
    queue<int> ans = s.modifyQueue(q,3);

    while(!ans.empty()){
        int num = ans.front();
        ans.pop();
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}