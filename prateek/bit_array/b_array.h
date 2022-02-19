// 
typedef struct 
{
	char *array;
	int size;
} b_array;

 enum b_value{b_false,b_true};

b_array *b_create(size_t);// create a bit array of size given as input
void b_destroy(b_array *);
enum b_value b_get(const b_array *,size_t loc);
void b_set(b_array *,size_t loc,enum b_value binary);
void b_reset (b_array *,size_t size);
void b_toggle (b_array *,size_t loc);
size_t b_size(b_array *);
b_array *b_copy(b_array *);
void arr_bin_print(unsigned char );
