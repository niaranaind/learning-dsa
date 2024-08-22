#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //creation of map
    unordered_map<string,int> m;

    //inserction 1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);

    //inserction 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //inserction 3
    m["mera"] = 1;
    m["mera"] = 2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;

    //size
    cout<<m.size()<<endl;

    //check presence of any key-value pair
    cout<<m.count("love")<<endl;
    cout<<m.count("niaran")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    //printing the content of map using for each loop
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //printing the content of map using a iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}