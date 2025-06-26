




#include<vector>
using namespace std;
#include<algorithm>




// O(nlogn) approach
class Solution {
    public:
        int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
            int ans = 0, n = r1.size();
            vector<int> gain(n);
    
            // Compute gain if the first mouse eats the cheese
            for(int i = 0; i < n; i++) 
                gain[i] = r1[i] - r2[i];
    
            sort(gain.begin(), gain.end()); // Sort gains
    
            // Add the k highest gains
            for(int i = n - k; i < n; i++)
                ans += gain[i];
    
            // Add all reward2 values (initial score)
            for(int num : r2)
                ans += num;
              
            return ans;
        }
    };
    