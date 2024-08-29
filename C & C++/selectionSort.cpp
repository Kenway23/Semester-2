#include <stdio.h>
#include <string.h>

int arr[]={1,7,3,234,77,98,46,4,999,8};
int n = 10;

void swap(int*a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void printData(){
	for(int q=0;q<n;q++){
		printf("%d",arr[q]);
		}
		printf("\n");
}

void selectionSort(){
	int minldx,currentldx=0;
	for (int q=0;q<n-1;q++){
		minldx=q;
		for(int w=0;w<n;w++){
			if(arr[minldx]>arr[w]){
				minldx=w;
			}
		}
		swap(&arr[minldx],&arr[currentldx]);
		currentldx++;
	}
}

int main(){
	printf("Sebelum Urut : ");
	printData();
	
	selectionSort();
	
	printf("Sesudah Urut:");
	printData();
}
