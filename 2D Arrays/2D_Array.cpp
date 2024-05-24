#include<iostream>
using namespace std;

bool linearSearch(int arr[][4],int row,int col,int key){

    for(int i=0;i<row;i++){

        for(int j=0;j<col;j++){

            if(arr[i][j] == key){
                return true;
            }
        }
    }
    return false;
}

int main(){

    //declaring 2D array
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int key;
    cout<<"Enter the key: ";
    cin>>key;

    if(linearSearch(arr,3,4,key)){
        cout<<"key is Present"<<endl;
    }
    else{
        cout<<"key is NOT Present"<<endl;
    }
    

    //printting 2D array
    for(int i=0;i<3;i++){

        for(int j=0;j<4;j++){

            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}