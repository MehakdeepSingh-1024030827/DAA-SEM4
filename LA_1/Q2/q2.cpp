#include<iostream>
using namespace std;

class Solution{
    public :

    void merge(int arr[],int low, int mid, int high){

        int lsize = mid - low + 1;
        int rsize = high - mid;

        int larr[lsize], rarr[rsize];

        for(int i=0; i<lsize ; i++){
            larr[i] = arr[i];
        }
        for(int j=0; j < rsize ; j++){
            rarr[j] = arr[mid+j+1];
        }

        int i=0,j=0,k=low;

        while(i < lsize && j < rsize){

            if(larr[i] < rarr[j]){
                arr[k] = larr[i];
                i++;
                k++;
            }

            else{
                arr[k] = rarr[j];
                j++;
                k++;
            }
        }

        while(i < lsize){
            arr[k] = larr[i];
            i++;
            k++;
        }
        while( j < rsize ){
            arr[k] = rarr[j];
            k++;
            j++;
        }
    }
    void mergesort(int arr[],int low, int high){

        if(low < high){

            int mid = (low+high)/2;

            mergesort(arr,low,mid);
            mergesort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
};

int main(){
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {38, 27, 43,3, 9, 82, 10};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    Solution s1,s2;
    s1.mergesort(arr1,0,size1-1);
    s2.mergesort(arr2,0,size2-1);

    cout<<"After applying merge sort on first array : "<<endl;

    for(int i=0;i<size1;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"After applying merge sort on second array : "<<endl;

    for(int i=0;i<size2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}