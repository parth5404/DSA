class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 1; // 0=N,1=E,2=S,3=W
    int pos = 0; // distance along perimeter

    Robot(int width, int height) {
        w = width;
        h = height;
    }

    void step(int num) {
        int perimeter = 2 * (w + h - 2);
        if (perimeter == 0) return;

        pos = (pos + num) % perimeter;

        if (pos == 0) {
            x = 0; y = 0;
            dir = 2; // South
            return;
        }

        if (pos <= w - 1) {
            x = pos;
            y = 0;
            dir = 1; // East
        } 
        else if (pos <= (w - 1) + (h - 1)) {
            x = w - 1;
            y = pos - (w - 1);
            dir = 0; // North
        } 
        else if (pos <= 2 * (w - 1) + (h - 1)) {
            x = w - 1 - (pos - (w - 1) - (h - 1));
            y = h - 1;
            dir = 3; // West
        } 
        else {
            x = 0;
            y = h - 1 - (pos - 2 * (w - 1) - (h - 1));
            dir = 2; // South
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        if (dir == 1) return "East";
        if (dir == 0) return "North";
        if (dir == 3) return "West";
        return "South";
    }
};