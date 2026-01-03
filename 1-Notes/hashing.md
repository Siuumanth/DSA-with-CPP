hashing syntax:

```cpp
struct PairHash{
        size_t operator()(const pair<int, int>& p) const noexcept{
            return ( (uint64_t)p.first << 32) ^ (uint64_t)p.second; 
        }
    };

    int countTrapezoids(vector<vector<int>>& points) {
        // using it 
        unordered_map< 
            pair<int,int>, 
            unordered_map<pair<int,int>, int, PairHash>, 
            PairHash 
        > mapp;
```