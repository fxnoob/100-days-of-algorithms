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

void fill_array(Sort *sort, int dynamic){
	float *num;
	num = (float *)sort->nums;
	if (dynamic == 1)
	{
		for (int i = 0; i < SIZE; i++){
			num[i] = rand()%50;
			printf("%d  ",(int )num[i]);
			//mem_cpy();
		}
	}
	else{
		num[0]=4;
		num[1]=10;
		num[2]=3;
		num[3]=5;
		num[4]=11;
		num[5]=14;
		num[6]=15;
		num[7]=13;
		num[8]=25;
		num[9]=17;
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
	fill_array(sort,0);
	float nn[]={4,10,3,5,11,14,15,13,25,17};
	sort->heapsort(nn,sort->size,order_asc);
	printf("\nSorted Array in ascending order: \n");
	show_array(sort->nums);
	printf("\n");
	//free memory
	Sort_destruct(sort);
	return 0;
}
