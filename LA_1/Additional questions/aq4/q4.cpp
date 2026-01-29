#include<iostream>
#include<unordered_set>
using namespace std;

class Solution{
public:
    int speciality(int arr[], int size, int k){
        unordered_set<int> specials;
        
        for(int l = 0; l < size; l++){
            for(int r = l; r < size; r++){
                
                for(int i = l; i <= r; i++){
                    int count = 0;
                    
                    for(int j = l; j <= r; j++){
                        if(arr[j] > arr[i]){
                            count++;
                        }
                    }
                    if(count == k){
                        specials.insert(arr[i]);
                    }
                }
            }
        }
        
        int answer = 0;
        for(int val : specials){
            answer += val;
        }
        
        return answer;
    }
};

int main(){
    Solution s;
    
    int arr[] = {3, 1, 4, 2, 5};
    int size = 5;
    int k = 2;
    
    cout << "Specialty: " << s.speciality(arr, size, k) << endl;
    
    return 0;
}