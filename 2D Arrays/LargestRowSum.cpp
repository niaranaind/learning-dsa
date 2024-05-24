#include<iostream>
using namespace std;

class solution{

    public:
    int largestRowSum(int arr[][4],int row,int col){
        int max =0;

        for(int i=0;i<row;i++){

            int sum = 0;
            for(int j=0;j<col;j++){

                sum+=arr[i][j];
            }
            if(sum>max){
                max = sum;
            }
        }
        return max;
    }
};

int main(){

    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    solution sol;

    cout<<"Largest row sum is: "<<sol.largestRowSum(arr,3,4)<<endl;

    return 0;
}