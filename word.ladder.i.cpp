/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/*
Implement by BFS
1. First of all, find all next possiable item which exits in dict.
2. If it exits in dict, then push it to collector, erase it in dict.
3. Lopp step1 and step2.
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (start.size() != end.size() || !dict.size()) return 0;

        queue<string> que;
        queue<string> queBuff;

        int result(1);
        que.push(start); // init first level for "start"
        while (dict.size() && !que.empty()) {
            while (!que.empty()) {
                string ss = que.front();
                que.pop();

                string temp;
                temp = ss; // Back up original item.
                for (int i=0; i<ss.length(); i++) {     
                    for (char j='a'; j<='z'; j++) {
                        if (ss[i] == j) continue;
                        
                        ss[i] = j;

                        if (ss == end) return ++result;

                        if (dict.count(ss)) {
                            queBuff.push(ss);
                            dict.erase(ss);
                        }
                    }
                    ss = temp;
                }
                
            }
            que.swap(queBuff); // Make next level item can be loop.
            result++;   
        }   

        return 0;
    }
};
