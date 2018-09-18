//typedef for 3 params sorting algos
typedef void (*sort_param_3)(void * , int , int (*compare)());

typedef struct SortInternalStructure{
	int size;
	void *nums;
	//bubble sort
	sort_param_3 bubble,selection,insertion;
}Sort;

Sort *Sort_init( int , int );
void Sort_destruct(Sort *);