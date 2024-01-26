class Solution {
public:
    int longestString(int x, int y, int z) {
        return (z + min(x,y) + min(min(x,y)+1,max(x,y))) * 2;
    }
};