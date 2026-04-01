class Robot {
public:
    int pos;
    int health;
    char dir;
    int idx;

    Robot(int pos, int health, char dir, int idx) {
        this->pos = pos;
        this->health = health;
        this->dir = dir;
        this->idx = idx;
    }
};

static bool comp(Robot &a, Robot &b) {
    return a.pos < b.pos;
}

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& healths, string dir) {
        int n = pos.size();
        vector<Robot> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back(Robot(pos[i], healths[i], dir[i], i));
        }

        sort(vec.begin(), vec.end(), comp);

        stack<Robot> st;

        for (auto &robot : vec) {
            if (robot.dir == 'R') {
                st.push(robot);
            } else {
                while (!st.empty() && st.top().dir == 'R' && robot.health > 0) {
                    if (st.top().health < robot.health) {
                        robot.health--;
                        st.pop();
                    } else if (st.top().health == robot.health) {
                        st.pop();
                        robot.health = 0;
                        break;
                    } else {
                        st.top().health--;
                        robot.health = 0;
                        break;
                    }
                }
                if (robot.health > 0) {
                    st.push(robot);
                }
            }
        }

        vector<pair<int,int>> survivors;
        while (!st.empty()) {
            survivors.push_back({st.top().idx, st.top().health});
            st.pop();
        }

        sort(survivors.begin(), survivors.end());

        vector<int> result;
        for (auto &p : survivors) {
            result.push_back(p.second);
        }

        return result;
    }
};