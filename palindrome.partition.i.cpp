/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> result;
        vector<string> temp;
        stringCut(s, result, temp, 0);
        
        return result;
        
    }
    void stringCut(string s, vector<vector<string>> &result, vector<string> &temp, int start) {  
        if (start == s.length()) {
            result.push_back(temp);
        } else {
            for (int i=1; i<=s.length()-start; i++) { // i is the length of sub string.
                if (isPalindrome(s.substr(start, i))) {
                    temp.push_back(s.substr(start,i));
                    stringCut(s, result, temp, start+i);
                    temp.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string s) {
        if (s.length() == 0) {
            return false;
        } else if (s.length() == 1) {
            return true;
        }
        
        for (int i=0,j=s.length()-1;i<=j;i++,j--) {
            if (s[i]!=s[j]) {
                return false;
            }
        }
        return true;
    }
};