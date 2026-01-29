#include<iostream>
#include<vector>
#include<algorithm>  
using namespace std;

class Solution{
public:
    void remove_element(int arr[], int &size, int element){
        int j = 0;
        
    
        while(j < size && arr[j] != element){
            j++;
        }
        
       
        if(j == size){
            return;
        }
        
        
        for(int k = j; k < size - 1; k++){
            arr[k] = arr[k + 1];
        }
        
        size--;
    }
    
    int findmedian(vector<int> v){
        
        sort(v.begin(), v.end());
        return v[v.size() / 2];
    }
    
    int work(int arr[], int size){
        vector<int> medians;
      
        for(int possible = 3; possible <= size; possible += 2){
            int parts = size - possible + 1;
            
   
            for(int j = 0; j < parts; j++){
                vector<int> temp;
                
       
                for(int k = j; k < j + possible; k++){
                    temp.push_back(arr[k]);
                }
                

                int m = findmedian(temp);
                medians.push_back(m);
            }
        }
        
    
        int ans = medians[0];
        for(int i = 1; i < medians.size(); i++){
            if(medians[i] < ans){
                ans = medians[i];
            }
        }
        
        return ans;
    }
    
    int calculate_answer(int arr[], int size){
    
        sort(arr, arr + size);
    
        
        int original_size = size;  
        
        for(int i = 0; i < original_size - 2; i++){
            
            int to_remove = work(arr, size);
            
            remove_element(arr, size, to_remove);
        }
    

        int sum = 0;
        for(int j = 0; j < size; j++){
            sum += arr[j];
        }
        
        return sum;
    }
};

int main(){
    Solution s;
    
    int arr[] = {5, 3, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl << endl;
    
    int answer = s.calculate_answer(arr, size);
    cout << "\nAnswer is: " << answer << endl;
    
    return 0;
}