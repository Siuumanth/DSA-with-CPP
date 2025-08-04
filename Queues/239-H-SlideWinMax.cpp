/*
    Approach: Monotonic Deque (Sliding Window Maximum)

    - We use a deque to store indices of useful elements in the current window.
    - The deque is maintained in decreasing order of element values (monotonic decreasing).
    - For each new element:
        1. Remove indices from the front if they are out of the current window.
        2. Remove indices from the back if the current element is greater than or equal to them
           (they can never be max again while this element is in the window).
    - The front of the deque always contains the index of the maximum element for the current window.
    - We start adding to the result once the first full window is formed (i >= k - 1).

    Time Complexity: O(n)
    - Each element is pushed and popped from the deque at most once.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        // Using deqeueue as a monotonic decreasing stack
        deque<int> dq;

        // <- front ------------------ back ->
        // popping happens from back, we make sure max element is always at the front
        // dequeue will contain the indexes of the elements not the elements themselves 

        for(int i = 0; i < n; i++){

            // If you are at i, then elements <= i-k are only valid
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // keep popping till u encounter a greater element
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
 
            // record max element 
            if(i >= k-1) ans.push_back(arr[dq.front()]);
        }

        return ans;        
    }
};


/*
Approach 1: using priority queue and hash map()nlogk
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        priority_queue<int> pq;  // for getting max element every time 
        unordered_map<int, int> mapp; // for making sure element picked is in our window

        // Step 1: To begin, add elements to pq
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
            mapp[arr[i]]++;
        }

        // Step 2: Complete first window 
        int top = pq.top();
        ans.push_back(top);

        // now pq and mapp has the first window
        int j = 0;
 
        // Step 2: begin the proccess
        for(int i = k; i < n; i++){
            // insert right element to window 
            mapp[arr[i]]++;   
            pq.push(arr[i]);

            // remove previous elements outside of window
            mapp[arr[j]]--;
            j++;

            // keep popping untill you find a valid element in the window
            while(mapp[ pq.top() ] <= 0) pq.pop();  

            ans.push_back(pq.top()); 
        }

        return ans;        
    }
};

*/