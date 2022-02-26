/*
Given an array of integers heights representing the histogram's bar height where the 
width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.


Example 2:


Input: heights = [2,4]
Output: 4
*/

//------------------- Striver's Solution ------------------------------------------------------------
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; 
        int maxA = 0; 
        int n = heights.size(); 
        for(int i = 0; i<=n; i++) {
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop(); 
                int width; 
                if(st.empty()) width = i; 
                else width = i - st.top() - 1; 
                
                // cout << i << " " << width << " " << height << endl; 
                maxA = max(maxA, width * height); 
            }
            st.push(i); 
        }
        return maxA;        
    }
};


//----------------------------------------- gfg Solution -----------------------------------------------------------

int getMaxArea(int arr[], int n)
{
    // Your code here
    //we create an empty stack here.
    stack<int> s;
    //we push -1 to the stack because for some elements there will be no previous
    //smaller element in the array and we can store -1 as the index for previous smaller.
    s.push(-1);
    int area = arr[0];
    int i = 0;
    //We declare left_smaller and right_smaller array of size n and initialize them with -1 and n as their default value.
    //left_smaller[i] will store the index of previous smaller element for ith element of the array.
    //right_smaller[i] will store the index of next smaller element for ith element of the array.
    vector<int> left_smaller(n, -1), right_smaller(n, n);
    while(i<n){
        while(!s.empty()&&s.top()!=-1&&arr[s.top()]>arr[i]){
            //if the current element is smaller than element with index stored on the
            //top of stack then, we pop the top element and store the current element index
            //as the right_smaller for the popped element.
            right_smaller[s.top()] = i;
            s.pop();
        }
        if(i>0&&arr[i]==arr[i-1]){
            //we use this condition to avoid the unnecessary loop to find the left_smaller.
            //since the previous element is same as current element, the left_smaller will always be the same for both.
            left_smaller[i] = left_smaller[i-1];
        }else{
            //Element with the index stored on the top of the stack is always smaller than the current element.
            //Therefore the left_smaller[i] will always be s.top().
            left_smaller[i] = s.top();
        } 
        s.push(i);
        i++;
    }
    for(int j = 0; j<n; j++){
        //here we find area with every element as the smallest element in their range and compare it with the previous area.
        // in this way we get our max Area form this.
        area = max(area, arr[j]*(right_smaller[j]-left_smaller[j]-1));
    }
    return area;
}
