/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

    1)Open brackets must be closed by the same type of brackets.
    2)Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true


Example 2:

Input: s = "()[]{}"
Output: true


Example 3:

Input: s = "(]"
Output: false

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            // Push all the opening brackets in stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if(st.empty()) return false;
                // check if the top matches with the c
                if(c == ')' && st.top() != '(') return false;
                if(c == '}' && st.top() != '{') return false;
                if(c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};