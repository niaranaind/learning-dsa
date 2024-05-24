#include<iostream>
using namespace std;

class solution{

    private:
    int getMax(int arr[]){

        int maxi = 0;
        int maxIndex =0;
        for(int i=0;i<26;i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public:

    char getMaxOccuranceChar(string str){

        int arr[26] = {0};
        for(int i=0;i<str.length();i++){

            int temp;
            if(str[i]>='a' && str[i]<='z'){
                temp = str[i]-'a';
            }
            else{
                temp = str[i]-'A';
            }
            arr[temp]++;
        }

        int maxIndex = getMax(arr);

        return 'a'+maxIndex;
    }
};

int main(){

    string str;
    cout<<"Enter the string: ";
    cin>>str;

    solution sol;
    cout<<"Maximum occuring character is: "<<sol.getMaxOccuranceChar(str)<<endl;

    return 0;
}