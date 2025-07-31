// We have N persons sitting on a round table. Any person can do a handshake with any other person.

//      1
// 2         3
//      4

// Handshake with 2-3 and 1-4 will cause cross.

// In how many ways these N people can make handshakes so that no two handshakes cross each other. N would be even. 
 

// it is solved though catalan number recursively
// For N people, each handshake pairs up 2 people. So, you can have at most N/2 handshakes, and every arrangement of non-crossing handshakes for N people matches the Catalan number at position N/2.
class Solution {
  public:
    int catalan(int n){
        if(n<=1)return 1;
        int ans =0;
        for(int i=1;i<=n;i++){
            ans+=catalan(i-1)*catalan(n-i);
        }
        return ans;
    }
    int count(int N) {
        // code here
        
        return catalan(N/2);
    }
};