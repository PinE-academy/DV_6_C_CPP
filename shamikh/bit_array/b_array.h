typedef struct {
    unsigned char *array;
    unsigned int size;
} b_array;

b_array *b_create(const unsigned int );
void b_destroy(b_array *);


