class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);//for left smaller values
        vector<int> right(n, 0);//for right smaller values
        stack<int> s;

        // right 
        for(int i=n-1; i>=0; i--){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        // left 
        for(int i=0; i<n; i++){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        

        

        int maxArea = 0;
        for(int i=0; i<n; i++){
            maxArea = max((heights[i]*(right[i]-left[i]-1)), maxArea);
        }

        return maxArea;
    }
};