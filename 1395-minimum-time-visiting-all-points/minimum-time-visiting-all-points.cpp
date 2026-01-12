class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[i+1][0];
            int y2=points[i+1][1];
            // if(abs(x1-x2)==abs(y1-y2)){
            //     ans+=abs(x1-x2);
            // }
            // else if(x1==x2||y1==y2){
            //     ans+=(x1==x2)?abs(y1-y2):abs(x1-x2);
            // }
            // else if(abs(x1-x2)<abs(y1-y2)){
            //     ans+=abs(x1-x2)+abs(y2-(y1+abs(x1-x2)));
            // }
            // else{
            //      ans+=abs(y1-y2)+abs(x2-(x1+abs(x1-x2)));
            // }
            ans+=max(abs(x1-x2),abs(y1-y2));
        }
        return ans;
    }
};