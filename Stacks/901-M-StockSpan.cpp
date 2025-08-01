// What data structures will we use?
// 
class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    StockSpanner() {
    }
    
    // Total average complexity is O(1) but total complexity is O(n)
    int next(int price) {

        // pair for maintaining { price, span }
        pair<int, int> day = {price, 1};

        while(!st.empty() && price >= st.top().first ){
            day.second += st.top().second;
            st.pop();
        }
        st.push(day);

        return day.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */