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
    int good(int arr[], int size){

        mergesort(arr,0,size-1);
        int ans = 0;
        int j = 0;
        for(int i=0 ; i < size ; i++ ){

            while(arr[i]-arr[j] > 10 ){
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
int main(){
    Solution s;
    int arr[] = {21,15,29,31,19,12,10,27};
    int longest_good = s.good(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<longest_good<<endl;
    return 0;
}