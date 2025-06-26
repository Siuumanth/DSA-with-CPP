
STL has containers like vector, algorithm, etc.
## 1. Vector:

- doubles size everytime size exceeds.

```cpp
#include vector 

vector<int> vec(size);

vector<int> nums = {1,2};


// adding elements
vec.push_back(a);
vec.pop_back();

a = vec[i];

// gives us the location of beginning element
vec.begin(); 

// makes first element 0
vec.erase(vec.begin()); 

```

##### Iterators:

- `vec.begin()` : gives us pointer to first element of array
- `vec.end()`:  gives us pointer to 1 element after the last element , garbage value
How to use:

```cpp
//printing all elements
vector<int>::iterator itr;
for(itr = vec.begin(); itr!=vec.end(); itr++){
   cout<< *(itr) << endl;
}

OR

// going backward
for(auto itr = vec.rbegin(); itr!=vec.rend(); itr++){
    cout<< *(it) <<endl;
}
```

---

## 2.List:
Internally implemented as a **Doubly Linked List.**
So random access not possible.
```cpp

lis.push_back(2);
lis.push_back(3);
// pushed from front, output = 3,2
lis.pop_back(); and lis.pop_front();

// Has all functions of vectors as well
```

---

## 3.Deque: Double Ended Queue:
implemented with the help of dynamic arrays, so random access possible.

```cpp
deque<int> d = {1,2,3};

deque<int> dq;

dq.push_front(10);     // Insert at front
dq.push_back(20);      // Insert at back

dq.pop_front();        // Remove from front
dq.pop_back();         // Remove from back

int front = dq.front();  // Access front element
int back = dq.back();    // Access back element

```

- Has all functions of vector.

---

## 4. Pair
Just used to pair 2 values.
```cpp
pair<int,string> p = {"abc", 23};

pair<int,pair<int,int>> p = {"abc", {1,5}};

//accessing elements
p.first;
p.second.first;

Also,

vector<pair <int, int>> vec = {{1,2}, {2,4}};

```

---

## **5. Stack**:
Last in first out principle.
```cpp

stack<int> s;

// Functions:
s.push(4);
s.top() // return top element
s.pop();
s.size()

// checks if stack is empty or not
s.empty();

// while(!s.empty()) - use case

// swaps contents of 2 stacks
stack1.swap(stack2);

```

---

## **6.Queue**
First in first out.

```cpp

queue<int> q;

q.push(1);
q.pop();
q.size();

q.front() // returns firsy element

q.empty();
```


---
## 7. Priority Queue
Uses a max heap structure internally

```cpp

priority_queue<int> q;
// by default, largest element has the highest priority

q.push();

// returns largest element, as that has the highest priority
q.pop()  // returns void
q.top()

size,empty
```

---

## **8.Map:**

With key and value.

```cpp

map< string, int > m;

m[key] = value; // adding value
m["phone"] = 10;

map.erase( 4 ); // erases this key
// can also be considered as pairs 
```

#### Characteristics:
1. All keys are unique.
2. The keys are always lexicographically sorted internally.

```cpp
// inserting elemnts
m.insert({"camera", 25})
m.emplace("camera", 25)

// removiing value
m.erase ("camera");

// finds elements:
temp = m.find("camera")

temp == m.end() // this means element does not exists
else exists
```

---

## 9. Unordered Map:

```cpp
unordered_map<string, int> m;

// has all functions of map
```

unlike normal maps, stores data unorderly, randomly, unlike sorted in maps.


## Main difference between unordered map and Map:

1. `map`: Internally, map is implemented as a self balancing tree, so functions like `insert, erase, count`, takes `O(logn)` time complexity.

2. `unordered_map:` Implemented differently, and if there are no collisions, `insert, erase, count` all takes `O(1)` complexity.

---
## **10.Set**

Only unique values are stored,, ignored duplicates are ignored.
Uses a self balancing tree, so functions have `logn` complexity, and values are sorted.

```cpp
set<int> s;

s.insert(3);

// has all functions of map
// find, count, erase , size , empty
```

---

## **11. unordered_set**:

Same difference as map and unordered map.

---

## **12. Algorithms**

1. Sorting:
```cpp
sort(arr, arr + n)
sort(arr, arr+n, greater<int>())
sort(arr.begin(), arr.end())

//sorting subarray
sort(arr.begin() + start, arr.begin() + end)
```

2.  Reverse:
   `reverse(vec.begin(), vec.end())`

3. Next permutation
   `next_permutation(vec.begin(), vec.end())`

```cpp
swap(a,b);
max(a,b);
min(a,b);
```

### More functions:
```cpp
max_element( vec.begin(), vec.end())
or min

// B search

binary_search(vec.begin(), vec.end(), target)
// target will return true if element exists else false
```