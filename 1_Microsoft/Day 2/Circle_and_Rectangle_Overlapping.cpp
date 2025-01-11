// https://leetcode.com/problems/circle-and-rectangle-overlapping/

class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int distanceSquared = (xCenter - closestX) * (xCenter - closestX) +
                              (yCenter - closestY) * (yCenter - closestY);

        distanceSquared = sqrt(distanceSquared);
        return distanceSquared <= r ;

    }
};