//Declaration of functions

// b_create function
typedef struct 
{
    unsigned char *array;
    unsigned int size;

} b_array;

b_array *b_create(size_t );
void b_destroy(b_array *);
