
// For this question , we will maintain4 loops for each boundary, top right down left 
// But when m and n is odd, then boundaries may overlap , so we need a corner case checking in 3 and 4

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral;   
        int i;

        int srow = 0, erow = m-1, scol = 0, ecol = n-1;
        
        // Continue looping as long as the current spiral layer has unvisited rows and columns
        
        while(srow <= erow && scol <= ecol) {
        
            // 1. top boundary
            for(int i = scol; i <= ecol; i++) {
                spiral.push_back(matrix[srow][i]);
            }
        
            // 2. right boundary
            for(int i = srow + 1; i <= erow; i++) {
                spiral.push_back(matrix[i][ecol]);
            }
        
            // 3. bottom boundary (only if srow < erow to avoid duplicate row)
            if(srow < erow) {
                for(int i = ecol - 1; i >= scol; i--) {
                    spiral.push_back(matrix[erow][i]);
                }
            }
        
            // 4. left boundary (only if scol < ecol to avoid duplicate column)
            if(scol < ecol) {
                for(int i = erow - 1; i > srow; i--) {
                    spiral.push_back(matrix[i][scol]);
                }
            }
        
            // update boundaries
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return spiral;
    }
};

