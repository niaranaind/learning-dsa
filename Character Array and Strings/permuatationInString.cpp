#include<iostream>
using namespace std;

class solution{

    private:
    bool checkEqual(int count1[],int count2[]){

        for(int i=0;i<26;i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }

    public:
    bool checkInclusion(string s1,string s2){

        int count1[26] = {0};
        for(int i=0;i<s1.length();i++){
            int index = s1[i]-'a';
            count1[index]++;
        }

        int i=0;
        int windowSize = s1.length();
        int count2[26] = {0};
        while(i< windowSize && i<s2.length()){
            int index = s2[i]-'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1,count2)){
            return true;
        }

        while(i<s2.length()){

            char newChar = s2[i];
            int index = newChar-'a';
            count2[index]++;

            char oldChar = s2[i-windowSize];
            index = oldChar-'a';
            count2[index]--;

            i++;
            if(checkEqual(count1,count1)){
                return true;
            }
        }

        return false;

    }
};

int main(){

    string s1,s2;
    cout<<"Enter the first string: ";
    cin>>s1;

    cout<<"Enter the second string: ";
    cin>>s2;

    solution sol;
    if(sol.checkInclusion(s1,s2)){
        cout<<"Permutation of string is PRESENT "<<endl;
    }
    else{
        cout<<"Permutation of string is ABSENT "<<endl;
    }

    return 0;
}