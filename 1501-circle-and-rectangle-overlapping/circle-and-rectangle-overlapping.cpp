class Solution {
public:
    long long distance(int ux, int uy, int vx, int vy) {
        return (long long)pow(ux - vx, 2) + (long long)pow(uy - vy, 2);
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        /* The center of the circle is inside the rectangle */
        if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) {
            return true;
        }
        /* The center of the circle is above the rectangle*/
        if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter &&
            yCenter <= y2 + radius) {
            return true;
        }
        /* The center of the circle is below the rectangle*/
        if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter &&
            yCenter <= y1) {
            return true;
        }
        /* The center of the circle is to the left of the rectangle*/
        if (x1 - radius <= xCenter && xCenter <= x1 && y1 <= yCenter &&
            yCenter <= y2) {
            return true;
        }
        /* The center of the circle is to the right of the rectangle*/
        if (x2 <= xCenter && xCenter <= x2 + radius && y1 <= yCenter &&
            yCenter <= y2) {
            return true;
        }
        /* The upper-left corner of the rectangle */
        if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
            return true;
        }
        /* The lower-left corner of the rectangle */
        if (distance(xCenter, yCenter, x1, y1) <= radius * radius) {
            return true;
        }
        /* The upper-right corner of the rectangle */
        if (distance(xCenter, yCenter, x2, y2) <= radius * radius) {
            return true;
        }
        /* The lower-right corner of the rectangle */
        if (distance(xCenter, yCenter, x2, y1) <= radius * radius) {
            return true;
        }
        /* No intersection */
        return false;
    }
};