class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(),arr.end());

        long long k=mass;
        for(int i=0;i<arr.size();i++){
            if(k<arr[i])return false;
            k+=arr[i];
        }
        return true;
    }
};