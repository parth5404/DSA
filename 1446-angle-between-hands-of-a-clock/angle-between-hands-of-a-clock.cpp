class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrs = (hour % 12) * 5 + (minutes) / 12.0;
        double theta = abs(hrs - minutes) * 6.0;
        return min(theta, 360.0 - theta);
    }
};