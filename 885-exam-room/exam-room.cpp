class ExamRoom {
public:
    int n;
    vector<int> arr;
    set<int> st;
    ExamRoom(int n) { this->n = n; }
    int seat() {
        if (st.empty()) {
            st.insert(0);
            return 0;
        }
        int maxDist = 0;
        int seatPos = 0;
        int prev = -1;
        for (int x : st) {
            if (prev == -1) {
                if (x > maxDist) {
                    maxDist = x;
                    seatPos = 0;
                }
            } else {
                if ((x - prev) / 2 > maxDist) {
                    maxDist = (x - prev) / 2;
                    seatPos = prev + maxDist;
                }
            }
            prev = x;
        }
        if (n - 1 - *st.rbegin() > maxDist) {
            seatPos = n - 1;
        }
        st.insert(seatPos);
        return seatPos;
    }

    void leave(int p) { st.erase(p); }
};
