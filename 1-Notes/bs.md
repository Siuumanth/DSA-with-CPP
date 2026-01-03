Here are **clean, structured, full-length notes** on:

### ✅ the Fair Pairs question

### ✅ what lower_bound and upper_bound *mean*

### ✅ how to implement them (half-open, correct, bug-free)

### ✅ how to use them to solve the problem

---

# **1. Problem Summary — Count the Number of Fair Pairs**

### **Definition**

You are given:

* An array `nums` of size `n`
* Two integers `lower` and `upper`

You must count how many pairs `(i, j)` satisfy:

```
0 ≤ i < j < n 
lower ≤ nums[i] + nums[j] ≤ upper
```

### **Why O(n²) is too slow**

Checking all pairs would take:

```
n * n = up to 10^10 operations
```

Too slow.

### **Why sorting helps**

After sorting, the array becomes **monotonic**.

Then for each fixed `i`:

* we want all `j > i`
* such that:

```
lower - nums[i] ≤ nums[j] ≤ upper - nums[i]
```

Which is a **value-range search**.
Binary search is perfect for this.

This is where **lower_bound** and **upper_bound** come in.

---

# **2. What Is lower_bound?**

### **Definition**

`lower_bound(arr, key)` =
**first index where arr[index] ≥ key**

So:

* It finds the **first element not less than key**
* It returns the leftmost place where key could appear or be inserted.

Example array:

```
1 2 5 7 7 9
```

`lower_bound(key = 7)` returns index **3?**
No → **index 3?**
Actually:

```
index 2 → 5 < 7
index 3 → 7 ≥ 7 ✔
```

**Answer = 3?**
Wait — careful.

Indexing:

0: 1
1: 2
2: 5
3: 7
4: 7
5: 9

**lower_bound(7) = 3**

(first 7)

---

# **3. What Is upper_bound?**

### **Definition**

`upper_bound(arr, key)` =
**first index where arr[index] > key**

Example:

```
1 2 5 7 7 9
```

`upper_bound(7)` returns index **5?**
No:

```
index 4 → arr[4] = 7 (not > 7)
index 5 → arr[5] = 9 ( > 7 ) ✔
```

**Answer = 5**

---

# **4. Relationship Between the Two**

For an array with duplicates:

```
lower_bound(7) → first 7
upper_bound(7) → index after last 7
```

So:

```
last index of 7 = upper_bound(7) - 1
```

This is exactly why:

* `lower_bound` gives **first element ≥ key**
* `upper_bound - 1` gives **last element ≤ key**

This is crucial for the Fair Pairs problem.

---

# **5. Binary Search Implementation (Half-Open Range)**

We use range = `[low, high)`
That means:

* low is inclusive
* high is exclusive
* valid indices are `[low .. high-1]`

This matches EXACTLY how STL `lower_bound` works.

---

## **5.1 lower_bound Implementation**

**Goal:** first index where `arr[mid] ≥ key`

```cpp
int lower_bound_bs(vector<int>& arr, int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < key)
            low = mid + 1;   // skip smaller elements
        else
            high = mid;      // mid might be the answer
    }
    return low; // first mid where arr[mid] >= key
}
```

---

## **5.2 upper_bound Implementation**

**Goal:** first index where `arr[mid] > key`

```cpp
int upper_bound_bs(vector<int>& arr, int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= key)
            low = mid + 1;   // skip values <= key
        else
            high = mid;      // mid might be the answer
    }
    return low; // first mid where arr[mid] > key
}
```

---

# **6. Getting First and Last Valid Positions**

Using the above two:

### **First element ≥ L**

```
firstIndex = lower_bound_bs(arr, i+1, n, lowKey)
```

### **Last element ≤ U**

```
lastIndex = upper_bound_bs(arr, i+1, n, upKey) - 1;
```

These two indices define a **valid range of `j`s**.

If:

```
firstIndex ≤ lastIndex
```

then valid count is:

```
lastIndex - firstIndex + 1
```

---

# **7. How This Solves Fair Pairs**

For each index `i`:

### Step 1

Compute:

```
lowKey = lower - arr[i]
upKey  = upper - arr[i]
```

We need all `nums[j]` satisfying:

```
lowKey ≤ nums[j] ≤ upKey
```

### Step 2

Binary search for first and last valid `j`:

```cpp
int L = lower_bound_bs(arr, i+1, n, lowKey);
int R = upper_bound_bs(arr, i+1, n, upKey) - 1;
```

### Step 3

Add the count if the interval is valid:

```cpp
if (L <= R)
    ans += (R - L + 1);
```

### Complexity:

```
Sorting: O(n log n)
For each i: O(log n)
Total: O(n log n)
```

---

# **8. Final Clean Notes Summary**

### **lower_bound**

* First index where `arr[i] ≥ key`
* Code uses `< key` check

### **upper_bound**

* First index where `arr[i] > key`
* Code uses `<= key` check

### **last element ≤ key**

* `upper_bound(key) - 1`

### **half-open binary search rule**

Always call with **high = endIndex + 1**

### **Binary search patterns**

```
while(low < high)
```

→ must be used with half-open range.

---

# If you want, I’ll now give you your final Fair Pairs solution using your style, your BS functions, perfectly clean and ready to submit.
