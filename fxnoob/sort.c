#include <sort.h>
#include <stdlib.h>
#include <math.h> 
//bubble sort
void sort_bubble(void *,int, int (*compare)( int , int ));
//selection sorts
void sort_selection(void *ptr, int size , int (*compare)(int , int));
//helper functions
int sort_max_min_fromIndex(void *array , int index,int (*compare)(int , int)); 
//insertion sort
void sort_insertion(void *ptr, int size , int (*compare)(int , int));
//merge-sort helper
void sort_merge_combine(void *, int , int, int, int (*compare)(int , int));
//merge-sort
void sort_mergesort(void *ptr, int l, int r, int (*compare)(int , int));
//heap-sort
void sort_heapsort(void *array,int size,int (*compare)(int , int));
//create sort obj
Sort *Sort_init(int size,int size_of){
	Sort *sort = (Sort *)malloc(sizeof(Sort));
	sort->size = size;
	sort->nums = malloc(size*sizeof(size_of));
	sort->bubble = sort_bubble;
	sort->selection = sort_selection;
	sort->insertion = sort_insertion;
    sort->mergesort = sort_mergesort;
    sort->heapsort = sort_heapsort;
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
	for (int i = 1; i < size; i++){
		key = num[i];
		j = i-1;
		while(compare(num[j], key)&&j>=0){
			num[j+1] = num[j];
			j--;
		}
		num[j+1] = key;
	}
}
//merge-sort helper
void sort_merge_combine(void *array,int l, int m, int r, int (*compare)(int , int)){
	float *arr = (float *)array;
	int i,j,k,n1 = m-l+1;
	int n2 = r-m;
	float arr1[n1],arr2[n2];
	for (i = 0; i < n1; i++){
		arr1[i] = arr[l+i];
	}
	for (j = 0; j < n2; j++){
		arr2[j] = arr[m+1+j];
	}
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if (compare(arr2[j],arr1[i])){
			arr[k] = arr1[i];
			i++;
		}	
		else{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < n1) 
    { 
        arr[k] = arr1[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = arr2[j]; 
        j++; 
        k++; 
    } 
}
//merge-sort(divide and conquer)
void sort_mergesort(void *ptr, int l, int r, int (*compare)(int , int)){
    int m;
    if(l<r){
    	m = (l+r)/2;
	    sort_mergesort(ptr,l,m,compare);
	    sort_mergesort(ptr,m+1,r,compare);
	    sort_merge_combine(ptr,l,m,r,compare);
    }
}
//heap-sort helper
void swapvals(void *a,void *b){
	float k;
	k = *(float *)a;
	*(float *)a = *(float *)b;
	*(float *)b =  k;
}
int sort_heapsort_heapify(void *array,int size,int index,int (*compare)(int , int)){
	float *arr = (float *)array;
	int left = 2*index+1;
	int right = 2*index+2;
	int largest = index;
	if ( left<size && compare(arr[left],arr[index])){
		largest = left;
	}
	if ( right<size && compare(arr[right],arr[index])){
		largest = right;
	}
	if (largest!=index){
		swapvals(&arr[index],&arr[largest]);
		sort_heapsort_heapify(array,size,largest,compare);
	}
	return largest;
}
//heapsort
void sort_heapsort(void *array,int size,int (*compare)(int , int)){
	for (int i = log2(size)-1; i >= 0; i--){
		sort_heapsort_heapify(array,size,i,compare);
	}
	float *arr = (float *)array;
	for (int i = size-1; i >= 0; i--){
		swapvals(&arr[0],&arr[i]);
		sort_heapsort_heapify(array,i,0,compare);	
	}
}
