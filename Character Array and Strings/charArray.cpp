#include<iostream>
using namespace std;

int getLength(char name[]){

    int count = 0;
    for(int i=0;name[i] != '\0';i++){
        count++;
    }
    return count;
}

void Reverse(char name[]){

    int s = 0;
    int e = getLength(name)-1;
    while(s<=e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
}

int main(){

    char name[10];
    cout<<"Enter your name: ";
    cin>>name;

    cout<<"Your name is: "<<name<<endl;

    int length = getLength(name);
    
    cout<<"Length of the character array is: "<<length<<endl;

    Reverse(name);

    cout<<"Reverse array is: "<<name<<endl;

    name[2] = '\0';

    cout<<"your name is: "<<name<<endl;

    return 0;
}