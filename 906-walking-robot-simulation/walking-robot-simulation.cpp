class Solution {
public:
    // static bool comp(vector<int> a, vector<int> b) {
    //     if (a[1] <= b[1])
    //         return a[1] <= b[1];
    //     return a[0] < b[0];
    // }
    static const long long HASH_MULTIPLIER = 60013;

    long long hashCoordinates(long long x, long long y) {
        return x + HASH_MULTIPLIER * y;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // vector<vector<int>> obsx = obstacles;
        // vector<vector<int>> obsy = obstacles;
        // sort(obsx.begin(), obsx.end());
        // sort(oby.begin(), oby.end(), comp);
        // map<int, int> mapx, mapy;
        unordered_set<long long> st;
        for (int i = 0; i < obstacles.size(); i++) {
            st.insert(hashCoordinates(obstacles[i][0],obstacles[i][1]));
        }
        int ans = 0;
        int curr_face = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> curr = {0, 0};

        for (int& cmd : commands) {
            if (cmd == -1) {
                curr_face = (curr_face + 1) % 4;
            } else if (cmd == -2) {
                curr_face = (curr_face + 3) % 4;
            } else {
                for(int i=1;i<=cmd;i++){
                    int nextX=curr[0]+dir[curr_face][0];
                    int nextY=curr[1]+dir[curr_face][1];
                    if(st.find(hashCoordinates(nextX,nextY))!=st.end()){
                        break;
                    }
                    curr[0]=nextX;
                    curr[1]=nextY;   
                }
                ans=max(ans,curr[0]*curr[0]+curr[1]*curr[1]);
            }
        }
        return ans;
    }
};