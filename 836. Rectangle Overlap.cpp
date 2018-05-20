class Solution {
    struct Point
    {
        int x, y;
    };
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        Point l1 = {rec1[0], rec1[3]}, r1 = {rec1[2], rec1[1]};
        Point l2 = {rec2[0], rec2[3]}, r2 = {rec2[2], rec2[1]};
        // If one rectangle is on left side of other
        if (l1.x >= r2.x || l2.x >= r1.x)
            return false;

        // If one rectangle is above other
        if (l1.y <= r2.y || l2.y <= r1.y)
            return false;

        return true;
    }
};
