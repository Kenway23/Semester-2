#include <stdio.h>
int recursiveSum(int n) { 
if (n == 1) {
 return 1; 
} else { 
return 2 * n - 1 + recursiveSum(n - 1); 
}
}
int main() {
int n = 5; 
int result = recursiveSum(n); 
printf("Sum of series up to %d terms: %d\n", n, result); 
return 0;
 }

