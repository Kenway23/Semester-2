#include <stdio.h>

int A[10]={2,5,7,8,10,11,12,13,20,30};
int i,j;
int k;
int x;
int found;

main(){
	scanf("%d",&x);
	i=0;
	j=9;
	found=0;
	while((found == 0 ) && (i<=j)){
		k=(i+j)/2;
		if(A[k] == x){
			found = 1;
		}else{
			if(A[k] < x ){
				i=k+1;
			}else{
				j=k-1;
			}
		}
	}
}
if(found == 1){
	printf("Ditemukan Di elemen ke- %d",k);
}else{
	printf("Tidak ditemukan");
}
}
}
