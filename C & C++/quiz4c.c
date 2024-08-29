#include <stdio.h>
int recursivePowerSum(int n) {
 if (n == 1) {
 return 1;
 } else {
 return pow(5, n - 1) + recursivePowerSum(n - 1);
 }
}
int main() {
 int n = 5;
 int result = recursivePowerSum(n);
 printf("Sum of series up to %d terms: %d\n", n, result);
 return 0;
}

