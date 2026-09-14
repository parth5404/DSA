class Solution {
public:
    int M = 1000000007;

public:
    vector<int> nsr(vector<int>& arr, int n) {
        vector<int> abc(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                abc[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return abc;
    }
    vector<int> nsl(vector<int>& arr, int n) {
        vector<int> abc(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                abc[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return abc;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSL = nsl(arr, arr.size());
        vector<int> NSR = nsr(arr, arr.size());
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long ways = ls * rs * arr[i];
            sum = (sum + ways) % M;
        }
        return sum;
    }
};
