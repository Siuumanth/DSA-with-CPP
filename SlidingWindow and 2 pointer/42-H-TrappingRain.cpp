// Approach 2: easier approach 1 given after this 
// explanation given after program
class Solution {
public:
    int trap(vector<int>& arr) {
    
        int n = arr.size();
        int lmax=0, rmax=0, total=0;
        int l=0, r=n-1;

        while(l<r){
            // water at l is limited by lmax only (not rmax).
            if(arr[l] <= arr[r]){

                // trap water
                if(lmax > arr[l])
                    total += lmax - arr[l];
                
                else
                    lmax = arr[l];
                
                l++;        // move right
                
            }
            // water at r is limited by rmax only.
            else if( arr[l] > arr[r] ){
               
                if(rmax > arr[r])
                  total += rmax - arr[r];
                
                else
                  rmax = arr[r];

                r--;
            }
        }

        return total;

    }
};


/*
🧠 Core Idea of the Condition
At each step, we decide which side to process (left or right), based on which boundary is shorter:

✔️ If arr[l] <= arr[r]
It means: the left bar is shorter, so water at l is limited by lmax only (not rmax).

Why? Because even if rmax is high, water can't rise above lmax if the left wall is shorter.

❌ If arr[l] > arr[r]
Now the right bar is shorter, so water at r is limited by rmax only.

The same logic: water can't go higher than the shorter side.

*/


/*
For optimum approach

Intuition Behind the Problem
The goal is to calculate how much rainwater can be trapped between the bars in an elevation map. The amount of water trapped at any point depends on the height of the current bar and the height of the tallest bars to its left and right.

Water can only be trapped if there are taller bars on both the left and right sides of the current bar.

The amount of water trapped at a specific bar is determined by the minimum of the tallest bars on its left and right, minus the height of the current bar.

Key Insight
The water trapped at any point depends on the lower of the two tallest bars (one on the left and one on the right). This is because water will overflow from the shorter side.

If the tallest bar on the left is smaller than the tallest bar on the right, the water level at the current position cannot exceed the height of the left tallest bar.

Similarly, if the tallest bar on the right is smaller, the water level cannot exceed the height of the right tallest bar.

How the Two-Pointer Approach Works
The two-pointer approach is a clever way to solve this problem in O(1) space by using two pointers (one at the start and one at the end of the array) and tracking the tallest bars seen so far from both sides.

Step-by-Step Intuition:
Initialize Two Pointers:

- left starts at the beginning of the array.

- right starts at the end of the array.

Track the Tallest Bars:

- left_max: The tallest bar seen so far from the left side.

- right_max: The tallest bar seen so far from the right side.

Move the Pointers:

Compare the heights at the left and right pointers:

If height[left] < height[right]:

This means the water level at the left pointer is limited by left_max (the tallest bar on the left so far).

If the current height[left] is greater than or equal to left_max, update left_max (no water can be trapped here).

Otherwise, add the difference (left_max - height[left]) to the total water trapped.

Move the left pointer to the right.

If height[left] >= height[right]:

This means the water level at the right pointer is limited by right_max (the tallest bar on the right so far).

If the current height[right] is greater than or equal to right_max, update right_max (no water can be trapped here).

Otherwise, add the difference (right_max - height[right]) to the total water trapped.

Move the right pointer to the left.

Repeat Until Pointers Meet:

Continue this process until the left and right pointers meet. At this point, you’ve considered all bars and calculated the total trapped water.

Why This Works
By moving the pointers based on the comparison of height[left] and height[right], you ensure that you’re always considering the lower of the two tallest bars (either left_max or right_max) to determine the water level.

This approach avoids the need for additional arrays or data structures, making it space-efficient (O(1)).

*/


// Approach 2: On TC and On SC
// For this question we will use the idea of prefix max and suffix max
// prefixMax - stores highest boundary on left side of arr[i]
// suffixMax - stores highest boundary on right side of arr[i]

// Now, formula for finding water stored on 1 arr[i] building is:
// min( leftMax , rightMax ) - arr[i], we just sum it up


class EasierSolution {
public:
    int trap(vector<int>& arr) {
    
        int n = arr.size(), i;
        vector<int> preMax(n), sufMax(n);

        // Step 1. Compute prefixMax and suffixMax

        // prefix Max 
        preMax[0] = arr[0];

        for(i = 1; i< n; i++){
            preMax[i] = max(arr[i], preMax[i-1]);
        }

        // suffix Max
        sufMax[n-1] = arr[n-1];

        for( i = n-2; i>=0; i--){
            sufMax[i] = max(arr[i], sufMax[i+1]);
        }

        // Step 2. Solve problem using formula:
        // water on top of arr[i] = min(leftMax, rightMax) - arr[i]
        int total = 0;
        for(i = 0; i < n ; i++){
            // condition works only if: 
            if(arr[i] < preMax[i] && arr[i] < sufMax[i]){

                int water = min(preMax[i], sufMax[i]) - arr[i];

                total += water;
            }
        }

        return total;

    }
};

