#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canDivide(vector<int>& A, int N, int M, int maxOR) {
        int segments = 1;     
        int currentOR = 0;     
        
        for(int i = 0; i < N; i++) {
            int newOR = currentOR | A[i];
            
            if(newOR <= maxOR) {
                currentOR = newOR;  
            } else {
                segments++;         
                currentOR = A[i];   
                
                if(A[i] > maxOR) {  
                    return false;
                }
            }
        }
        
        return segments <= M; 
    }
    
    int minMaxOR(vector<int>& A, int N, int M) {
       
        int high = 0;
        for(int i = 0; i < N; i++) {
            high |= A[i];
        }
        
        int low = 0;
        int answer = high;
        
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(canDivide(A, N, M, mid)) {
                answer = mid;     
                high = mid - 1;
            } else {
                low = mid + 1;     
            }
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    
    
    vector<int> A1 = {1, 2, 3, 4};
    int N1 = 4, M1 = 2;
    cout << "Array: [1, 2, 3, 4], M = 2" << endl;
    cout << "Minimum Maximum OR: " << sol.minMaxOR(A1, N1, M1) << endl;
    cout << endl;
}
