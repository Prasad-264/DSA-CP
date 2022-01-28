// Iterative C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;
/* C++ Code to reverse the given array 
    arr[] = {1, 2, 3, 4, 5}
             ^           ^
           start        end
    output = {5, 4, 3, 2, 1}
*/
 
// Iterative function to reverse the arr[] 
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
} 

// Recursive function to reverse the arr[]
void reverseArray1(int arr[], int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);  
    // Recursive Function call
    reverseArray1(arr, start + 1, end - 1);
}
// Time Complexity of both function is O(N)   
 
/* Utility function to print an array */
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
 
   cout << endl;
}
 
/* Driver function to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
     
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // To print original array
    printArray(arr, n);
     
    // Function calling
    reverseArray(arr, 0, n-1);
     
    cout << "Reversed array is" << endl;
     
    // To print the Reversed array
    printArray(arr, n);
     
    return 0;
}