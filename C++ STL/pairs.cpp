#include<iostream>
using namespace std;

int main(){

    //declaring a pair --> pair<dataType,dataType> name;

    pair<int,int> p2;

    //taking input from terminal
    cin>>p2.first;
    cin>>p2.second;

    cout<<p2.first<<" "<<p2.second<<endl;

    pair<int,string> p;

    //there are two ways to initialize pairs or put value in pair
    p = make_pair(2,"abc");  //---method-1

    pair<int,string> q;

    q = {2,"cbd"};

    //how to access the value of pair-> then it can be done by using first and second function

    cout<<p.first<<" "<<p.second<<endl;

    cout<<q.first<<" "<<q.second<<endl;

    //copying one pair into another pair

    pair<int,string> p1 = p;

    p1.first = 3;

    cout<<p1.first<<" "<<p1.second<<endl;

    cout<<p.first<<" "<<p.second<<endl;

    //arrays and pairs

    int a[] = {1,2,3};
    int b[] = {2,3,4};

    pair<int,int> p_array[3];

    p_array[0] = {1,2};
    p_array[1]= {2,3};
    p_array[2] = {3,4};

    swap(p_array[0],p_array[2]);

    cout<<" print: pair array: "<<endl;
    for(int i=0;i<3;i++){

        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }

    return 0;
}