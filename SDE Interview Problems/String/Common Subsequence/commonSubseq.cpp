/*
Given two strings a and b. Check whether they contain any common subsequence (non empty) or not.

Example 1:

Input:
a = "ABEF" b = "CADE"
Output: 1
Explanation: Subsequence "AE" occurs
in both the strings.

Example 2:

Input: 
a = "ABCD", b = "EFGH"
Output: 0
Explanation: There's no common subsequence
in both the strings.

*/

class Solution {
public:
	bool commonSubseq (string a, string b) {
	    vector<bool> hash(26, 0);
	    for(auto it : a) hash[it - 'A'] = true;
	    for(auto it : b) {
	        if(hash[it - 'A']) 
	            return true;
	    }
	    return false;
	}
};