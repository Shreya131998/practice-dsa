// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]

class Solution {
public:
    bool isValid(string t){
        if(t.size()>3 || t.size()==0)return false;
        if(t.size()>1 && t[0]=='0')return false;
        if(t.size() && stoi(t)>255)return false;
        return true;
    }
    void solve(string &s,int index,vector<string>&ans,string output, int dots){
        if(dots==3){
            if(isValid(s.substr(index))){
                ans.push_back(output+s.substr(index));
            }
            return;
        }
        int sz = s.size();
        for(int i=index;i<min(index+3,sz);i++){
            if(isValid(s.substr(index,i-index+1))){
                output.push_back(s[i]);
                output.push_back('.');
                solve(s,i+1,ans,output,dots+1);
                output.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string output ="";
        solve(s,0,ans,output,0);
        return ans;
    }
};