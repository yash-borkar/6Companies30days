// https://leetcode.com/problems/image-smoother/

class Solution {
public:
    vector<vector<int>> dir{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1} 
    };

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int sum = 0;
                int count = 0;
                for(auto idx: dir){
                    int newI = i + idx[0];
                    int newJ = j + idx[1];

                    if(newI >= 0  && newI < m && newJ >= 0 && newJ < n){
                        sum += img[newI][newJ];
                        count++;
                    }            
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};
