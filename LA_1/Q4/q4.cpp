#include<iostream>
using namespace std;

class Solution{
    public:
    int max_sub_array_sum(int arr[],int size){
        int s1 = arr[0];
        int s2 = arr[0];

        for(int i=1; i < size; i++){

            int temp = max(arr[i],arr[i]+s1);
            s1 = temp;
            if(temp > s2){
                s2 = temp;
            }
        }
        return s2;
    }
};
int main(){
    int arr[] = {-2,-5,6,-2,-3,1,5,-6};
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution s;
    int ans = s.max_sub_array_sum(arr,size);
    cout<<"maximum subarray sum is : "<<ans<<endl;
    return 0;
}