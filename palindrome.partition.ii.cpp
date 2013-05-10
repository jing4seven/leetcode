/*
 *
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
class Solution {
public:

    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length();
        vector<vector<int>> dics(n,vector<int>(n));

        for (int i = 0; i < dics.size(); i++)
            for (int j=0; j< dics[i].size(); j++)
                dics[i][j] = -1;

        int m[n];
        for (int i = n-1; i>=0; i--) {
            if (isPalindrome(s, i, n-1, dics)) {
                    m[i]= 0;
            } else {
                int minCount = n-1;
                for (int j=i+1; j<n;j++) {
                    if (isPalindrome(s, i, j-1, dics)) {
                        m[i] =  m[j]+1;
                        if (m[i] < minCount) {
                            minCount = m[i];
                        }
                    }
                }
                if (minCount != n-1) {
                    m[i] = minCount;
                }
            }
        }

        return m[0];
    }

    int isPalindrome(string &s, int i, int j, vector<vector<int>> &dics) {
        if (dics[i][j]!=-1)
            return dics[i][j];
        if (i==j) {dics[i][j] =1; return 1;}

        if (s[i] != s[j]) {
            return dics[i][j] = 0;
        } else {
            if (j-i == 1) {
                return dics[i][j] = 1;
            } else {
                return dics[i][j] = isPalindrome(s, ++i, --j, dics);
            }
        }
    }
};

