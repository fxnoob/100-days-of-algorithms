#include <sort.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10


int order_asc(int a, int b){
	return (a > b);
}

int order_desc(int a, int b){
	return (a < b);
}

void fill_array(Sort *sort){
	float *num;
	num = (float *)sort->nums;
	for (int i = 0; i < SIZE; i++){
		num[i] = rand()%50;
		printf("%d  ",(int )num[i]);
		//mem_cpy();
	}
}
void show_array(void *num){
	float *n ;
	n = (float *)num;
	for (int i = 0; i < SIZE; i++){
		printf("%f  ",n[i]);
	}
}
int main(int argc, char const *argv[]){
	
	Sort *sort = Sort_init(SIZE,sizeof(float));
	fill_array(sort);
	sort->insertion(sort->nums,sort->size,order_asc);
	printf("\nSorted Array in ascending order: \n");
	show_array(sort->nums);
	printf("\n");
	//free memory
	Sort_destruct(sort);
	return 0;
}
