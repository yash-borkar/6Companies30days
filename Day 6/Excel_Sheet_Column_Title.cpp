// https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        map<int, char> mp;
        char ch = 'A';

        for (int i = 1; i <= 26; i++) {
            mp[i] = ch;
            ch++;
        }

        string ans = "";
        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26 + 1;
            ans = mp[remainder] + ans;
            columnNumber = (columnNumber - 1) / 26;
        }

        return ans;   
    }
};