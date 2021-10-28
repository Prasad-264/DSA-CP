def getSum(n):
 
    sum = 0
    while (n != 0):
 
        sum = sum + int(n % 10)
        n = int(n/10)
 
    return sum
 
n = 687
print(getSum(n))

### Recursive Problem
def sumDigits(no):
    return 0 if no == 0 else int(no % 10) + sumDigits(int(no/10))
 
print(sumDigits(68724))


### Taking input as a string
def getSum(n):
    
    sum = 0       # Initializing sum to 0
    
    for i in n:     # Traversing through string
        
        sum = sum + int(i)   # Converting char to int
 
    return sum

n = "123456789123456789123422"
print(getSum(n))
