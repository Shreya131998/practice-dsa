// He wants to test his students, so, he asks them a similar related question. He asks them to print all the valid balanced bracket sequence given N pairs of parantheses () and M pairs of braces {}.

// Can you solve this variation of his problem?

// Remember a balanced parentheses has following properties:

// For any type of bracket (parentheses/brace), the number of opening and closing brackets should be equal. The following are invalid: (){}} ({({})}
// For any type of bracket, and any index of the string, the number of opening bracket before that index should be greater or equal to the number of closing brackets. The following are invalid: ()}{ ({}))(
// For any two matching pairs of different types of brackets, it should not happen that one type of bracket has opening before the opening of other bracket but has closing after the second type of closing. This is invalid: {(}) but these are valid: {()} ({}).

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int open1, int close1, int open2, int close2,string output,string stack){
    if(open1==0 && close1==0 && open2==0 && close2==0){
        cout<<output<<endl;
        return;
    }
    if(open1>0){
        solve(open1-1,close1,open2,close2,output+'(', stack+'(');
    }
    if(open1<close1 && !stack.empty() && stack.back()=='('){
        solve(open1,close1-1,open2,close2,output+')', stack.substr(0,stack.size()-1));
    }
    if(open2>0){
        solve(open1,close1,open2-1,close2,output+'{',stack+'{');
    }
    if(open2<close2 && !stack.empty() && stack.back()=='{'){
        solve(open1,close1,open2,close2-1,output+'}',stack.substr(0,stack.size()-1));
    }
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,m;
    cin>>n;
    cin>>m;
    string output="";
    solve(n,n,m,m,output,"");
    return 0;
}

