// https://leetcode.com/problems/count-collisions-on-a-road/

class Solution {
public:
    int countCollisions(string directions) {
        string dir = directions;
        int n = directions.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(directions[i] == 'R' && i+1<n){
                if(directions[i+1] == 'L'){
                    ans += 2;
                    directions[i] = 'S';
                    directions[i+1] = 'S';
                }
                else if(directions[i+1] == 'S'){
                    ans += 1;
                    directions[i] = 'S';
                }
            }
            else if(directions[i] == 'L' && i-1 >= 0){
                if(directions[i-1] == 'R'){
                    ans += 2;
                    directions[i] = 'S';
                    directions[i-1] = 'S';
                }
                if(directions[i-1] == 'S'){
                    ans += 1;
                    directions[i] = 'S';
                }
            }
        }

        bool flag = false;
        for(int i=n-1; i>=0; i--){
            if(dir[i]=='L' || dir[i]=='S') flag = true;
            if(dir[i]=='R' && i-1 >=0 && dir[i-1] == 'R' && flag) ans++;
        }
        return ans;
    }
};