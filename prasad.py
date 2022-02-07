# ****** Kadanes Algorithm ******
'''
   python Function to return a Largest Sum Contiguous Subarray
   size of arr, n = 8
   arr = [-2, -3, 4, -1, -2, 1, 5, -3]
   output = 7 bcoz sum of [ 4 + (-1) + (-2) + 1 + 5 ] = 7;
'''
def maxSubArraySum(self,arr,n):
    sum1 = 0
    maxi = arr[0] 
    for i in range(0, n):
        sum1 += arr[i]
        maxi = max(sum1, maxi); 
        if(sum1 < 0): sum1 = 0
        
    return maxi

'''
Companies Tags :
*24*7 *nnovation Labs *Accolite *Amazon *Citrix *D-E-Shaw 
*FactSet *Flipkart *Hike *Housing.com *MetLife *Microsoft 
*Morgan *Stanley *Ola *Cabs *Oracle *Payu *Samsung *Snapdeal 
*Teradata *Visa *Walmart *Zoho *Google *Adobe *Arcesium
'''

# follow @code_dsa :) 