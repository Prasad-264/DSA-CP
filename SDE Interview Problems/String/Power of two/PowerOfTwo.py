

class Solution:
	def power(self, A):
         if A=="1":
             return 0
         x = int(A)
         if x&(x-1)==0:
             return 1
         else:
             return 0