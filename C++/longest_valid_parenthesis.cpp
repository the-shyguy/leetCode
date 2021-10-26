#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int result = 0, previous = -1;
        
        for (int i = 0; i < s.size(); i++) {
            
           if (s[i] == '(') st.push(i);
            
            else {
                if (!st.empty()) {
                    st.pop();
                    if (st.empty()) result = max(result, i - previous);
                    else result = max(result, i - st.top()); 
                }
                else previous = i;
            }
        }
        
        return result;
    }
        
    
};


int main() {
    Solution s;
    cout<<s.longestValidParentheses("(())()(()")<<endl;
    return 0;
}