// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//  will give tle because dp is not applied
class Solution {
public:
    bool isValid(string &a, set<string>&t){
        if(t.find(a)!=t.end())return true;
        return false;
    }
    bool solve(string &s, set<string>&t, int index){
        if(index>=s.length())return true;
        string a="";
        for(int i=index;i<s.length();i++){
            a+=s[i];
            if(isValid(a,t)){
                bool ans = solve(s,t,i+1);
                if(ans)return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>t;
        for(int i=0;i<wordDict.size();i++){
            t.insert(wordDict[i]);
        }
        // vector<int>dp(s.length()+1,-1);
        return solve(s,t,0);
    }
};