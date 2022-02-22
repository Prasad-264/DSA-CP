/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1


Example 2:

Input: columnTitle = "AB"
Output: 28


Example 3:

Input: columnTitle = "ZY"
Output: 701

*/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); i++) {
            result = result * 26 + (s[i] - 'A' + 1);
        }
        return result;
    }
};