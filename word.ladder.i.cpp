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
Use BFS
1. First of all find all next possiable item which exits in dict.
2. 
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	queue<string> que;
    	queue<string> queBuff;
    	int result(0);

    	if (start.size() != end.size() || !dict.size()) return 0;

    	que.push(start); // init first level for "start"

    	while (dict.size() && !que.empty()) {
    		while (!que.empty()) {
    			string ss = que.front();
    			que.pop();

    			string temp;
				temp = ss;
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
    			if (queBuff.size() > 0) {
    				que.swap(queBuff);
	    			result++;
    			} else {
    				return 0;
    			}
    		}
    	}	

    	return 0;
    }
};
