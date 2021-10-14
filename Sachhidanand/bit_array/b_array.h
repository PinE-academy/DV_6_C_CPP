//Declaration of functions

// b_create function
typedef struct 
{
    unsigned char *array;
    unsigned int size;

} b_array;

enum b_value {
    b_false,
    b_true
};

b_array *b_create(size_t );
void b_destroy(b_array *);
enum b_value b_get(const b_array *, size_t );
void b_set(b_array *, size_t , enum b_value);
void b_reset(b_array *, size_t );
void b_toggle(b_array *, size_t );
