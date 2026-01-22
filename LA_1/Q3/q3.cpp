#include<iostream>
using namespace std;

class Solution{
    public :

    int partition(int arr[],int low, int high){

        int pivot = arr[high];
        int i = low - 1;
        int j = low;

        while( j < high){

            if(arr[j] < pivot){
                i++;
                swap(arr[i],arr[j]);
            }
            j++;
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    void quicksort(int arr[], int low, int high){
        if(low < high){
            
            int part = partition(arr,low,high);

            quicksort(arr,low,part-1);
            quicksort(arr,part+1,high);
        }
    }
};
int main(){

    int arr[] = { 4, 2, 6, 9, 2 };
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution s1;
    s1.quicksort(arr,0,size-1);
    cout<<"Sorted array by using quick sort algo : ";
    for(int i=0 ; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}