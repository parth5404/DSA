class Solution {
public:
    int bestClosingTime(string cus) {
        int max=0,score=0,time=-1;
        for(int i=0;i<cus.length();i++){
            score+=(cus[i]=='Y')?1:-1;
            if(score>max){
                max=score;
                time=i;
            }
        }
        return time+1;
    }
};