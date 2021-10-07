# Bit array
Implementation of array of bits.

There are two parts of the project.
* driver program
* implementation module

Implementation module contains b_array.h and b_array.c  
Driver program uses b_array.h and dems APIs from b_array.h

### b_array
b_array is the internal structure that holds bit array and meta info.
``` c
typedef struct b_array
{
    unsigned char *array;
    unsigned int size;
} b_array;
```

### b_value
b_array uses b_value enum that defines b_false and b_true.
``` c
enum b_value {
    b_false,
    b_true
};
```

## APIs supported  
### _create b_array_
``` c
barray* b_create(size_t);
```
Creates a bit array of size given as input.

### _destroy b_array_
``` c
void b_destroy(b_array*);
```
Destroys underlying bit array b_array.

### _get bit_
``` c
b_value b_get(const b_array*, size_t);
```
Get bit value ith index

### _set bit_
``` c
void b_set(b_array*, size_t, b_value);
```
Set a bit at ith index

### _reset bit_
``` c
void b_reset(b_array*, size_t);
```
Reset reset a bit at ith index

### _toggle bit_
``` c
void b_toggle(b_array*, size_t);
```
Toggles bit at ith index

### _size of b_array_
``` c
size_t b_size(const b_array*);
```
Returns size of the b_array

### _copy b_array_
``` c
b_array b_copy(const b_array*);
```
Creates a copy of the b_array
