#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class solution{

    private:
    void solve(queue<int> &q){
        //base case
        if(q.empty()){
            return;
        }

        //store front element
        int num = q.front();
        q.pop();

        //recursive call
        solve(q);

        //back tracking
        q.push(num);
    }

    public:
    queue<int> rev2(queue<int> q){

        solve(q);
        return q;
    }

    queue<int> rev(queue<int> q){

        stack<int> s;
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s.push(element);
        }

        while(!s.empty()){
            int element = s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }

    void print(queue<int> q){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
};



int main(){

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    //using approach 1
    
    solution s;
    s.print(q);
    s.print(s.rev(q));

    //using approach 2
    s.print(s.rev2(q));

    return 0;
}