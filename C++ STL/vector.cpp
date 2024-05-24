#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){

    cout<<" size: "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){

        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){

    //declaration of vector --->  vector<dataType> vector_name;

    vector<int> v;

    //taking inputs in vector
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        print(v);
    }

    print(v);

    vector<int> v1(5);  // this is a vector of size 5
    print(v1);

    v1.push_back(7);
    print(v1);

    v1.pop_back();
    print(v1);

    v1.push_back(7);

    //copying one vector in another
    vector<int> v2 = v1;

    return 0;
}