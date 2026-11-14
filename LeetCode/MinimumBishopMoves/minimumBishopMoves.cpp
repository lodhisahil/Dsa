class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];
        int tr = target[0];
        int tc = target[1];
        int dr = abs(sr - tr);
        int dc = abs(sc - tc);
        // Same diagonal
        if (dr == dc) {
            return 1;
        }
        // Different colored squares
        if ((sr + sc) % 2 != (tr + tc) % 2) {
            return -1;
        }
        // Reachable in two moves
        return 2;
    }
};