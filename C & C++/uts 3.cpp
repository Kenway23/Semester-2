#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	char str [200]="STMIK MARDIRA INDONESIA BANDUNG";
	int y = 0, x;
	
	for (x=0;str[x] != '\0';x++)
	{
		if (str[x] == ' ' && str[x-1] != ' ' )
		y++;
	}
	
	printf("%d\n", y);
}
