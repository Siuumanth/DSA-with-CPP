
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0, c = 0; 
        char ch;
        
        for(int i = 0 ; i<n ; ){
            ch = chars[i], c=0;

            while(i<n && ch==chars[i]){
                i++;
                c++;
            }
            chars[index] = ch;
            index++;

            if(c>1){
                int temp = index;
                while(c!=0 && index<n){
                    int temp2 = c%10;
                    chars[index] = (char)(temp2 + '0');
                    c = c/10;
                    index++;
                }
                reverse(chars.begin() + temp, chars.begin() + index);
            }
        }
        //chars.resize(index-1);
        return index;
    }
};