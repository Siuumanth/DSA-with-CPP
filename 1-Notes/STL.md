
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

// Remove all occurences of a value
vector<int> v = {1, 2, 3, 2, 4};
v.erase(remove(v.begin(), v.end(), 2), v.end());  // removes all 2s


vector<int> v = {10, 20, 30};
v.erase(v.begin() + 1);  // removes element at index 1 (i.e., 20)

vector<int> v = {5, 6, 7, 8, 9};
v.erase(v.begin() + 1, v.begin() + 4);  // removes 6, 7, 8



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

## 2. String
```cpp
 string s = "hello world";

// LENGTH
s.length()  // 11

// ACCESS CHARACTER
cout << "First char: " << s[0] << endl;     // h
cout << "Last char: " << s.back() << endl;  // d

// FRONT / BACK
cout << "Front: " << s.front() << ", Back: " << s.back() << endl;

// APPEND / PUSH_BACK
s.append("!!");
cout << "After append: " << s << endl;  // hello world!!
s.push_back('?');
cout << "After push_back: " << s << endl;  // hello world!!?


// POP_BACK
s.pop_back();
cout << "After pop_back: " << s << endl;  // hello world!!

// INSERT
s.insert(5, "123");
cout << "After insert: " << s << endl;  // hello123 world!!


// ERASE
s.erase(5, 3);  // erase 3 chars from index 5
cout << "After erase: " << s << endl;  // hello world!!


// SUBSTRING
string sub = s.substr(6, 5);  // start=6, len=5
cout << "Substring: " << sub << endl;  // world


// FIND
size_t pos = s.find("world");
cout << "Position of 'world': " << pos << endl;  // 6


// RFind (last occurrence)
size_t rpos = s.rfind("l");
cout << "Last 'l': " << rpos << endl;  // 9


// REPLACE
s.replace(6, 5, "there");
cout << "After replace: " << s << endl;  // hello there!!


// COMPARE
string a = "abc", b = "xyz";
if (a.compare(b) < 0)
    cout << "a < b" << endl;

// CLEAR
s.clear();
cout << "After clear: '" << s << "' with length " << s.length() << endl;


// EMPTY
if (s.empty()) cout << "String is empty\n";

// STRING TO INT
string num = "123";
int n = stoi(num);  // string to int

cout << "stoi: " << n + 1 << endl;  // 124

// INT TO STRING
int x = 456;
string x_str = to_string(x);
```

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

#### Max heap:
```cpp

priority_queue<int> q;
// by default, largest element has the highest priority

q.push();

// returns largest element, as that has the highest priority
q.pop()  // returns void
q.top()

size,empty


```

#### Min heap:

```cpp

priority_queue<int, vector<int>, greater<int>> minQ;

minQ.push(10);
minQ.push(5);
minQ.push(20);

int top = minQ.top();  // returns 5

minQ.pop();            // removes 5

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