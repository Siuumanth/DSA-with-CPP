#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 1 = up, 2 = right, 3 = down, 4 = left

class Solution {
public:
    bool isSafe(vector<vector<char>>& grid, int dir, int i, int j, int m, int n){
        
        // 1 = up, 2 = right, 3 = down, 4 = left

        if(dir == 1){ // up
        --i;
        if(i < 0) return false;
        if(grid[i][j] == 'w' || grid[i][j] == 's' || grid[i][j] == 'c') return false;
        }
    
        else if(dir == 2){  // right
            ++j;
            if(j >= n) return false;
            if(grid[i][j] == 'w' || grid[i][j] == 's' || grid[i][j] == 'c') return false;
        }
    
        else if(dir == 3){  // down
            ++i;
            if(i >= m) return false;
            if(grid[i][j] == 'w' || grid[i][j] == 's' || grid[i][j] == 'c') return false;
        }
        
        else if(dir == 4){   // left
            --j;
            if(j < 0) return false;
            if(grid[i][j] == 'w' || grid[i][j] == 's' || grid[i][j] == 'c') return false;
        }
    
        return true;
    }

    int updatedX(int x, int dir){
        if(dir == 1){
            return --x;
        }
  
        else if(dir == 3){
            return ++x;
            
        }
        return x;
    }

    int updatedY(int y, int dir){
        if( dir == 2){
            return ++y;
        }
        else if(dir == 4){
            return --y;
        }
        return y;
    }

    bool findPath(vector<vector<char>>& grid, int x, int y, int m, int n){
                cout<< " We At " << x << y << endl;

        if(grid[x][y] == 'm'){
            return true;
        }

        // exploring logic
        for(int i = 1; i < 5; i++){
            if(isSafe(grid, i, x, y, m, n )){
                // move in this dir
                grid[x][y] = 'c';
                if(findPath(grid, updatedX(x,i), updatedY(y,i), m, n)){
                    return true;
                }
            }
        }
        return false;
    }

    // main function
    bool canReach(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int x,y;
        bool shudBreak = false;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 's'){
                    x = i;
                    y = j;
                    shudBreak = true;
                    break;
                }
            }
            if(shudBreak){
                break;
            }
        }

        return findPath(grid, x, y, m, n);

    }
};

int main() {
    // Example input
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));


    for(int i = 0; i < n; ++i){
        string row;
        cin >> row;
        for(int j = 0; j < m; ++j){
            grid[i][j] = row[j];
        }
    }

    Solution sol;
    bool result = sol.canReach(grid);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}





/*
---

🔳 **Problem Statement (Reconstructed from Image)**

You are given a **2D grid** consisting of characters. Each cell can be one of the following:

* `'s'` – represents the **starting point** (snake).
* `'m'` – represents the **man** (destination).
* `'w'` – represents a **wall** (blocked cell).
* `'p'` – represents a **valid path**.

You can move in **four directions**: up, down, left, right (no diagonals).

#### ❗ Task:

Determine whether the snake can **reach the man** by moving only through `'p'` or `'m'` cells (cannot move through `'w'`). The snake can only move to adjacent (4-directional) cells.

#### ✅ Constraints:

* The grid is of size `n x m` (dimensions not specified).
* There is exactly one `'s'` and one `'m'` in the grid.
* Assume the input is valid.

#### 🧾 Input Format (assumed):

```
First line: two integers `n` and `m` – number of rows and columns.
Next `n` lines: each line contains `m` characters (from {s, m, p, w}) without spaces.
```

#### 🧾 Output Format:

* Print `"YES"` if a valid path exists from `'s'` to `'m'`.
* Print `"NO"` otherwise.

---

### 🔁 Example:

**Input:**

```
4 4
sppw
wpwp
pppw
wwpm
```

**Output:**

```
YES
```

---

Let me know if you want me to generate:

* A sample test case to debug.
* A blank version for practice.
* Or validate your own code against this.

*/