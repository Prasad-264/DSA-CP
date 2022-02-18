/*
Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";  // treat ans as a stack in below for loop
       
       for (char c : num) {
           
           // make sure digits in ans are in ascending order remove one char
           while (ans.length() && ans.back() > c && k) {
               ans.pop_back();         
               k--;                   
           }
           
           // can't have leading '0'
           if (ans.length() || c != '0') {
               ans.push_back(c); 
           }  
       }
        
       // make sure remove k digits in total
       while (ans.length() && k--) {
           ans.pop_back(); 
       }          
       
       return ans.empty() ? "0" : ans;
    }
};

/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = num.size();
        stack<char> mystack;
        //Store the final string in stack
        for(char c: num)
        {
            while(!mystack.empty() && k>0 && mystack.top()>c)
            {   mystack.pop();      k-=1;   }
            
            if(!mystack.empty() || c!='0')
                mystack.push(c);
        }
        
        //Now remove the largest values from the top of the stack
        while(!mystack.empty() && k--)
            mystack.pop();
        if(mystack.empty())
            return "0";
        
        //Now retrieve the number from stack into a string (reusing num)
        while(!mystack.empty())
        {
            num[n-1] = mystack.top();
            mystack.pop();
            n-=1;
        }
        return num.substr(n);
    }
};

*/