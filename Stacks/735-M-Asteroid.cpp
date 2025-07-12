class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();

        // can use a monotonic stack, and then pop into a vector as well

        // we will use vector as a stack, supports push and pop
        vector<int> st;
        bool pushOrNot = false;

        // back() in vector = top() in stack 
        for(int i = 0; i<n; i++){
            pushOrNot = true;

            while(!st.empty() && st.back() > 0){
                // top is positive
                if(arr[i] < 0){  // collision
                    if(abs(arr[i]) == st.back()){  // equal
                        st.pop_back();
                        pushOrNot = false;
                        break;
                    }
                    else if(abs(arr[i]) > st.back()){  // destroy top
                        st.pop_back();
                    }
                    else{   // incoming is -ve and too weak to destroy
                        pushOrNot = false;
                        break;
                    }
                }
                else {    // incoming and top is +ve
                    break;
                }
            }
            
            if(pushOrNot){
                st.push_back(arr[i]);
            }
        }
        /*
        No push conditions are:
        - incoming gets destroyed by top
        - incoming is equal in magnitude but differnt in sign than top
        */
    
        return st;
    }
};


/*
while(!st.empty() && abs(arr[i]) > st.top()){
                st.pop();
            }

            if(!st.empty() && arr[i] < 0 && abs(arr[i]) <= st.top()){
                if( abs(arr[i]) == st.top()){
                    st.pop();
                    continue;  // destroy incoming and both
                }
                else
                    continue;  // destroy incoming
            }

            st.push(arr[i]);  // if current is +ve and smaller then push 
*/