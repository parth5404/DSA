class Solution {
public:
    double total = 0;
    double caluclateArea(double mid, vector<vector<int>>& points) {
        double area = 0;
        for (int i = 0; i < points.size(); i++) {
            double y = points[i][1];
            double len = points[i][2];
            double height = min(max(mid - y, 0.0), len);
            area += height * len;
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        for (int i = 0; i < points.size(); i++) {
            // int x1 = points[i][0];
            // int y1 = points[i][1];
            // int x2 = x1 + points[i][2];
            // int y2 = y1 + points[i][2];
            // double overlap = 0;
            // if ((points[i + 1][0] >= x1 && points[i + 1][0] < x2) &&
            //     (points[i + 1][1] >= y1 && points[i + 1][1] < y2)) {
            //     double length =
            //         min(points[i + 1][2], abs(x2 - points[i + 1][0]));
            //     double breadth =
            //         min(points[i + 1][2], abs(y2 - points[i + 1][1]));
            //     overlap = length * breadth;
            // }
            // total += points[i][2] * points[i][2] +
            //          points[i + 1][2] * points[i + 1][2] - overlap;
            total += 1.0*points[i][2] * points[i][2];
        }

        double s = 0;
        double e = 1e9;
        while (e - s > 1e-6) {
            double mid = (s + e) / 2;
            if (caluclateArea(mid, points) >= total / 2)
                e = mid;
            else
                s = mid;
        }
        return s;
    }
};