// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int>mp;
        for(auto i: secret) mp[i]++;

        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        for(int i=0; i<n;i++){
            if(guess[i] == secret[i]){
                if(mp[secret[i]] > 0){
                    bulls++;
                    mp[secret[i]]--;
                }
            }
        }

        for(int i=0; i<n;i++){
            if(guess[i] != secret[i]){
                if(mp.find(guess[i]) != mp.end()){
                    if(mp[guess[i]] > 0){
                        cows++;
                        mp[guess[i]]--;
                    }
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};