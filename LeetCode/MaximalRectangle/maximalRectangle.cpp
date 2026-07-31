class Solution {
public:
    int largestRectangleInRow(vector<int>& heights) {
        int n = heights.size();
        vector<int> PSE(n, 0);
        vector<int> NSE(n, 0);
        stack<int> st;
        // finding PSE -> previous smaller element
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                PSE[i] = st.top();
            }else{
                PSE[i] = -1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        // finding NSE -> next smaller element
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                NSE[i] = st.top();
            }else{
                NSE[i] = n;
            }
            st.push(i);
        }
        int area = 0;
        for(int i=0; i<n; i++){
            area = max (area, heights[i]*(NSE[i] - PSE[i] -1));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    heights[j] ++;
                }else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleInRow(heights));
        }
        return maxArea;
    }
};