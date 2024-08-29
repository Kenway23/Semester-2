#include <stdio.h>
int recursiveMultiply(int a, int b) {
	if (b == 0) {
 		return 0; 
	} else { 
		return a + recursiveMultiply(a, b - 1); 
	}
  }
   		
int main() { 
	int a = 5; int b = 3; 
	int result = recursiveMultiply(a, b); 
	printf("%d x %d = %d\n", a, b, result); return 0; 
}

