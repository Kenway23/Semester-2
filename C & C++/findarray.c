#include <stdio.h>
int findIndexRecursive(int arr[], int n, int x, int startIndex) {
 if (startIndex >= n) {
 return -1; // not found
 } else if (arr[startIndex] == x) {
 return startIndex;
 } else {
 return findIndexRecursive(arr, n, x, startIndex + 1);
 }
}
int main() {
 int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 int n = sizeof(arr) / sizeof(arr[0]);
 int x;
 printf("Enter the element to search for: ");
 scanf("%d", &x);
 int startIndex = 0;
 int result = findIndexRecursive(arr, n, x, startIndex);
 if (result!= -1) {
 printf("Element %d found at index %d\n", x, result);
 } else {
 printf("Element %d not found in the array\n", x);
 }
 return 0;
}

