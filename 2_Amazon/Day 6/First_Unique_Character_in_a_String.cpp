// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        queue<int> q;
        int freq[26] = {0};
        
        // har char ko pakdo frequency store kro queue mai dalo aur check kro
        for (int i = 0; i < s.length(); i++){
            char ch = s[i];
            freq[ch - 'a']++;
            // queue ke ander push taki track rakh pao
            q.push(i);

            // answer find kro
            while (!q.empty()){
                int frontIdx = q.front();
                char frontChar = s[frontIdx];
                // check freq
                if (freq[frontChar - 'a'] > 1){
                    // not an answer
                    q.pop();
                }
                else{
                    ans = frontIdx;
                    break;
                }
            }
            if (q.empty()) ans = -1;
        }
        return ans;
    }
};