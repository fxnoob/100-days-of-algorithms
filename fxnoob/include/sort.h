//typedef for 3 params sorting algos
typedef void (*sort_param_3)(void * , int , int (*compare)(int,int));
//typedef for 4 params sorting algos
typedef void (*sort_param_4)(void * , int , int, int (*compare)(int,int));

typedef struct SortInternalStructure{
	int size;
	void *nums;
	//bubble sort
	sort_param_3 bubble,selection,insertion;
	sort_param_4 mergesort;
}Sort;

Sort *Sort_init( int , int );
void Sort_destruct(Sort *);