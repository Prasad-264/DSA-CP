class Solution:
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,arr,n):
        sum1 = 0
        maxi = arr[0] 
        for i in range(0, n):
            sum1 += arr[i]
            maxi = max(sum1, maxi); 
            if(sum1 < 0): sum1 = 0
            
        return maxi


import math
 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends