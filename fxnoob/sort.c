#include<sort.h>
#include <stdlib.h>
//bubble sort
void sort_bubble(void *,int, int (*compare)( int , int ));

//create sort obj
Sort *Sort_init(int size,int size_of){
	Sort *sort = (Sort *)malloc(sizeof(Sort));
	sort->size = size;
	sort->nums = malloc(size*sizeof(size_of));
	sort->bubble = sort_bubble;
	return sort;
}

//destroy Sort obj
void Sort_destruct(Sort *sort){
	free(sort);
}

//bubble sort 
void sort_bubble(void *ptr,int size ,int (*compare)(int, int)){
	float *nums,temp;
		nums = (float *)ptr; 
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (compare(nums[i],nums[j])){
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}