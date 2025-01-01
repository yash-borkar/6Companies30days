// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    // Joshephus Problem
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++) q.push(i);

        int count = 1;
        while(q.size() > 1){
            int ele = q.front();
            q.pop();
            if(count % k != 0) q.push(ele);
            count++;
        }
        return q.front();
    }
};
