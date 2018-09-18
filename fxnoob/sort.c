#include <sort.h>
#include <stdlib.h>

//bubble sort
void sort_bubble(void *,int, int (*compare)( int , int ));
//selection sorts
void sort_selection(void *ptr, int size , int (*compare)(int , int));
//helper functions
int sort_max_min_fromIndex(void *array , int index,int (*compare)(int , int)); 
//insertion sort
void sort_insertion(void *ptr, int size , int (*compare)(int , int));
//create sort obj
Sort *Sort_init(int size,int size_of){
	Sort *sort = (Sort *)malloc(sizeof(Sort));
	sort->size = size;
	sort->nums = malloc(size*sizeof(size_of));
	sort->bubble = sort_bubble;
	sort->selection = sort_selection;
	sort->insertion = sort_insertion;
	return sort;
}

//destroy Sort obj
void Sort_destruct(Sort *sort){
	free(sort->nums);
	free(sort);
}

//bubble sort 
void sort_bubble(void *ptr,int size ,int (*compare)(int, int)){
	float *nums,temp;
	nums = (float *)ptr; 
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (compare(nums[j],nums[i])){
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}
//selection sort helper
int sort_max_min_fromIndex(void *array , int index,int (*compare)(int , int)){
	float *nums,key;
	int in;
	nums = (float *)array;
	key = nums[index];
	for (int i = index; i >= 0; i--){
		if (compare(nums[i],key)){
			key = nums[i];
			in = i;
		}
	}
	return in; 
}
//selection sort
void sort_selection(void *ptr, int size , int (*compare)(int , int)){
	float *nums,temp;
	nums = (float *)ptr;
	int in;
	for (int i = size-1; i > -1; i-- ) {
		in = sort_max_min_fromIndex(nums,i,compare);
		temp = nums[in];
		nums[in] = nums[i];
		nums[i] = temp;			
	}
}
//insertion sort
void sort_insertion(void *ptr, int size , int (*compare)(int , int)){
	float *num,key;
	int j;
	num = (float *)ptr;
	for (int i = 2; i < size; i++){
		key = num[i];
		j = i-1;
		while(compare(num[j],num[j+1])&&j){
			num[j+1] = num[j];
			j--;
		}
		num[j+1] = key;
	}
}
