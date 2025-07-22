class Solution {
public:
    vector<string> removeSubfolders(vector<string>& arr) {
        int n = arr.size();

        // Sort the folders so that parent folders come before subfolders
        sort(arr.begin(), arr.end());

        vector<string> ans;

        // Start with the first folder and assume it's a parent
        // We add "/" to help with precise prefix matching (e.g., "/a" vs "/ab")
        string curS = arr[0] + "/";
        int curn = curS.length();

        ans.push_back(arr[0]);

        // Loop through the remaining folders
        for (int i = 1; i < n; i++) {
            // If arr[i] is at least as long as curS and the prefix matches curS,
            // then it's a subfolder and we skip it
            if (arr[i].length() >= curn && arr[i].compare(0, curn, curS) == 0) {
                continue;
            } else {
                // Not a subfolder — keep it
                ans.push_back(arr[i]);

                // Update curS and its length
                curS = arr[i] + "/";
                curn = curS.length();
            }
        }

        return ans;
    }
};
