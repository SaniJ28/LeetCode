class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=hour*30;
        h+=(minutes*0.5);
        double min=6*minutes;
        double angle=abs(h-min);
        if(angle>180)return 360-angle;
        return angle;
    }
};