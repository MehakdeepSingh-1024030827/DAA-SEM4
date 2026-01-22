#include<iostream>
using namespace std;

class Solution{
    public :

    int binarySearch(int arr[],int size, int target){

        int low = 0;
        int high = size - 1;

        while(low < high){

            int mid = (low + high)/2;

            if(arr[mid]==target){
                return mid;
            }
            else if(target > arr[mid]){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
int main(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr)/sizeof(arr[0]);
    Solution s1;
    int ans = s1.binarySearch(arr,size,23);
    if(ans != -1){
        cout<<"23 found at index : "<<ans<<endl;
        
    }
    else{
        cout<<"23 is not there in the array ! "<<endl;
    }
    return 0;
}