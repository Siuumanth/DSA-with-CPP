
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p = part.length();
        int index;
        while(1){
            index = s.find(part);
            if(index < s.length())
                s.erase(index,p);
            else return s;
        }
        
        return s;
    }
};