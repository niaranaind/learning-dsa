#include<iostream>
using namespace std;

class sorting{

    public:

    void merge(int *arr,int s,int e){

        int mid=s+(e-s)/2;

        //creating new arrays
        int len1=mid-s+1;
        int len2=e-mid;

        int *first=new int[len1];
        int *second=new int[len2];

        //copying the element
        int mainArrayindex=s;
        for(int i=0;i<len1;i++){

            first[i]=arr[mainArrayindex];
            mainArrayindex++;
        }

         mainArrayindex=mid+1;
        for(int i=0;i<len2;i++){

            second[i]=arr[mainArrayindex];
            mainArrayindex++;
        }

        //merge two sorted array algorithm

        int index1=0;
        int index2=0;
        mainArrayindex=s;

        while(index1<len1 && index2<len2){

            if(first[index1]<second[index2]){

                arr[mainArrayindex]=first[index1];
                index1++;
                mainArrayindex++;
            }
            else{

                arr[mainArrayindex]=second[index2];
                index2++;
                mainArrayindex++;
            }
        }

        //copying the first array element
        while(index1<len1){

            arr[mainArrayindex]=first[index1];
            index1++;
            mainArrayindex++;
        }

        //copying the second array element
        while(index2<len2){

            arr[mainArrayindex]=second[index2];
            index2++;
            mainArrayindex++;
        }
        
    }

    void mergeSort(int arr[],int s,int e){

        //base case
        if(s>=e){
            return ;
        }

        int mid =s+(e-s)/2;

        //sorting the left part
        mergeSort(arr,s,mid);

        //sorting the right part
        mergeSort(arr,mid+1,e);

        //merge
        merge(arr,s,e);

    }
};

int main(){
    
    int arr[5]={3,2,6,1,3};

    int n=5;

    sorting sr;

    sr.mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}