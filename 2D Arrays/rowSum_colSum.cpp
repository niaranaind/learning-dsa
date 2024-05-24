#include<iostream>
using namespace std;

class TwoDArray{

    public:
    void rowSum(int arr[][4],int row,int col){

        for(int i=0;i<row;i++){
            int sum = 0;
            for(int j=0;j<col;j++){

                sum=sum+arr[i][j];
            }
            cout<<sum<<endl;
        }
        cout<<endl;
    }

    void colSum(int arr[][4],int row ,int col){

        for(int i=0;i<col;i++){
            int sum = 0;
            for(int j=0;j<row;j++){

                sum=sum+arr[j][i];
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }

    void print(int arr[][4],int row,int col){

        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){

                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){

    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    TwoDArray sol;

    cout<<"Row sum of 2D array is: "<<endl;
    sol.rowSum(arr,3,4);

    cout<<"Col sum of 2D array is: "<<endl;
    sol.colSum(arr,3,4);

    sol.print(arr,3,4);

    return 0;
}