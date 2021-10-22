#Alternative Sorting
#Given an array of integers, print the array in such a way that the first element is first maximum and second element is first minimum and so on
def alternateSort(arr, n):
    arr.sort()
    i = 0
    j = n-1
     
    while (i < j):
     
        print(arr[j], end =" ")
        j-= 1
        print(arr[i], end =" ")
        i+= 1
 
    # If the total element in array is odd
    # then print the last middle element.
    if (n % 2 != 0):
        print(arr[i])
 
arr = list(map(int, input().split()))
n = len(arr)
 
alternateSort(arr, n)