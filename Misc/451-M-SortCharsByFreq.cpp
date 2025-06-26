
// On space and On time 
class Solution {
public:
    static bool sortPair(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
    
    string frequencySort(string s) {
        int n = s.length();

         unordered_map<char, int> freq;

        // Step 1: Count frequencies
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Max-heap by frequency
        priority_queue<pair<int, char>> pq;

        for(auto temp : freq){          // creating priority queue
            pq.push({temp.second, temp.first});
        }

        string ans = "";

        while(!pq.empty()){      // getting pairs of {count, char} in desc order , n then concatenating
            auto top = pq.top();
            pq.pop();
            ans += string( top.first, top.second );  // concatenating
            if(top.first == 0) break;
        }

        return ans;
    }
};


/*
nlogn approach

// hash map = record freq 

class Solution {
public:
    static bool sortPair(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
    
    string frequencySort(string s) {
        int n = s.length();

        vector<int> hash(128,0);
        vector<pair<int,int>> freq(128, {0,0});

        // created a pair map
        for(int i = 0; i<n ; i++){
            freq[ (int)s[i] ].first++;
            freq[ (int)s[i] ].second = (int)s[i];
        }

        sort(freq.begin(), freq.end(), sortPair );

        for( auto p: freq){
            cout<< p.second;
        }

        string ans = "";

        for( auto p: freq){
            ans += string( p.first, (char)p.second );  // concatenating

            if(p.first == 0) break;
        }

        return ans;
    }
};
*/