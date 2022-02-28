/*
Given an input stream of A of n characters consisting only of lower case alphabets.
The task is to find the first non repeating character, each time a character is 
inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b

'
Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'

*/

class Solution {
public:
	string FirstNonRepeating(string A) {
	    map<char, int> freq;
		queue<char> q;
	    string ans="";
	    
	    for(int i=0; i<A.length(); i++) {
	        freq[A[i]]++;
	        q.push(A[i]);
	        
	        while(!q.empty()) {
	            if(freq[q.front()] > 1) q.pop();
	            else {
	                ans.push_back(q.front());
	                break;
	            }
	        }
	        if(q.empty()) ans.push_back('#');
	    }
	    return ans;
	}

};