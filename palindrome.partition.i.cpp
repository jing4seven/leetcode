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
        vector<vector<string>> temp;
        for (int i=0;i<s.length();i++) {
            temp = stringCut(s,i);
            for (int j=0;j<temp.size();j++) {
                if (temp[j].size() > 0) {
                    result.push_back(temp[j]);
                }
            }
        }
        return result;
        
    }
    vector<vector<string>> stringCut(string s, int countCut) {
        vector<vector<string>> result;
        vector<string> temp;
        
        if (countCut == 0) {
            if (isPalindrome(s)) {
                temp.push_back(s);
                result.push_back(temp);
            }
        } else {
            for (int i=0; i<s.length();i++) {
                bool flag1 = false;
                temp.clear();
                string tempStr = s.substr(0,i);
                if (isPalindrome(tempStr)) {
                    flag1 = true;
                } else {
                    continue;
                }
                vector<vector<string>> subResult;
                subResult = stringCut(s.substr(i, s.length()-i), countCut-1);
                bool flag3 = false;
                for (int j=0;j<subResult.size();j++) {
                    for (int k=0; k<subResult[j].size();k++) {
                        bool flag2 = false;
                        if (isPalindrome(subResult[j][k])) {
                            flag2 = true;    
                        }
                        if (flag1 == true && flag2 == true) {
                            if (flag3 == false) {
                                temp.push_back(tempStr);
                                flag3 = true;
                            }
                            temp.push_back(subResult[j][k]);
                        }
                    }
                }
                result.push_back(temp);
            }
            
        }
        
        return result;
    }
    bool isPalindrome(string &s) {
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