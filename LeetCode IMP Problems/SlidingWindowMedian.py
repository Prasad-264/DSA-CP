'''
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]

Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

'''

from sortedcontainers import SortedList

class solution:
    def medianSlidingWindow(self, nums, k):
        sl = SortedList(nums[:k - 1])
        wd = []

        for i in range(k - 1, len(nums)):
            sl.add(nums[i])
            wd.append((sl[(k - 1) // 2] + sl[k // 2]) / 2)
            sl.remove(nums[i - k + 1])
        return wd

