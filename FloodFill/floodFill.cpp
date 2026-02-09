class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int orgColor){
        if(sr < 0 || sc < 0 ||
         sr >= image.size() || sc >= image[0].size() 
         || image[sr][sc] != orgColor || image[sr][sc] == newColor){
            return;
        }

        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, newColor, orgColor);//top
        dfs(image, sr, sc+1, newColor, orgColor);//right
        dfs(image, sr+1, sc, newColor, orgColor);//bottom
        dfs(image, sr, sc-1, newColor, orgColor);//left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};