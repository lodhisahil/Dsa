class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int index = arr.size() - 1;

        while(!st.empty() && arr[st.top()] <= price){
            st.pop();
        }
        int span;
        if(st.empty()){
            span = index+1;
        }else{
            span = index - st.top();
        }
        st.push(index);
        return span;
    }
};

/*
 *
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */