#include <stdio.h>
#include <string.h>
void reverseString(char str[], int start, int end) {
 char temp;
 if (start >= end) {
 return;
 } else {
 temp = str[start];
 str[start] = str[end];
 str[end] = temp;
 reverseString(str, start + 1, end - 1);
 }
}
void printReversedString(char str[]) {
 int length = strlen(str);
 reverseString(str, 0, length - 1);
 printf("Reversed string: %s\n", str);
}
int main() {
 char str[100]; // buffer to store the input string
 printf("Masukan Kata: ");
 fgets(str, 100, stdin); // read input from user
 str[strlen(str) - 1] = '\0'; // remove the newline character
 printf("Kata Asli: %s\n", str);
 printReversedString(str);
 return 0;
}

