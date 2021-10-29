// 
typedef struct 
{
	char *array;
	int size;
} b_array;

enum b_value{b_false,b_true};

b_array *b_create(size_t);// create a bit array of size given as input


