#include <stdio.h>
#include <string.h>

int arr[]={1,7,3,234,77,98,46,4,999,8};

int n = 10;

void swap(int * a,int * b ){
	int temp = *a;
	*a = *b;
	
	*b=temp;
}
void printData(){
	for(int q=0; q<n;q++){
		printf("%d",arr[q]);
	}
	printf("\n");
}

void bubbleSort(){
	for(int q=0;q<n-1;q++){
		for(int w=0;w<n-1;w++){
			if(arr[w]>arr[w+1]){
				swap(&arr[w],&arr[w+1]);
			}
		}
	}
}

int main() {
    printf("Data sebelum diurutkan:\n");
    printData();

    bubbleSort();

    printf("Data setelah diurutkan:\n");
    printData();

    return 0;
}
