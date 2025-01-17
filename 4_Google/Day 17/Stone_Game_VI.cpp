// https://leetcode.com/problems/stone-game-vi/

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < n; i++){
            maxHeap.push({aliceValues[i] + bobValues[i], i});
        }
        int aliceScore = 0, bobScore = 0;
        bool aliceTurn = true;
        
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            maxHeap.pop();
            if(aliceTurn==true) aliceScore += aliceValues[index];
            else bobScore += bobValues[index];
            aliceTurn = !aliceTurn; 
        }
        if(aliceScore > bobScore) return 1;
        if(bobScore > aliceScore) return -1;
        return 0;
    }
};

