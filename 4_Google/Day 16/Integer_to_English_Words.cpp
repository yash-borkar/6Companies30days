// https://leetcode.com/problems/integer-to-english-words/

class Solution {
public:
    vector<string> belowTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> belowHundred = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    const int BILLION = 1'000'000'000;
    const int MILLION = 1'000'000;
    const int THOUSAND = 1'000;

    string helper(int num) {
        if (num == 0) return "";
        if (num < 10) return belowTen[num];
        if (num < 20) return belowTwenty[num - 10];
        
        if (num < 100)
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + helper(num % 10) : "");
        if (num < 1000)
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + helper(num % 100) : "");

        if (num < MILLION)
            return helper(num / THOUSAND) + " Thousand" + (num % THOUSAND != 0 ? " " + helper(num % THOUSAND) : "");

        if (num < BILLION)
            return helper(num / MILLION) + " Million" + (num % MILLION != 0 ? " " + helper(num % MILLION) : "");

        return helper(num / BILLION) + " Billion" + (num % BILLION != 0 ? " " + helper(num % BILLION) : "");
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }
};