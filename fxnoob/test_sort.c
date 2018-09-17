#include <sort.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10


int order_asc(int a, int b){
	return (a < b);
}
int order_desc(int a, int b){
	return (a > b);
}

int main(int argc, char const *argv[]){
	
	Sort *sort = Sort_init(SIZE,sizeof(float));
	float *num;
	num = (float *)sort->nums;
	for (int i = 0; i < SIZE; i++){
		num[i] = rand()%50;
		printf("%d  ",(int )num[i]);
		//mem_cpy();
	}
	sort->bubble(sort->nums,sort->size,order_asc);
	printf("\n");
	for (int i = 0; i < SIZE; i++){
		printf("%f  ",num[i]);
	}
	//free memory
    Sort_destruct(sort);
	return 0;
}
