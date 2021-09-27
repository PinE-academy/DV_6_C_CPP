# Pascal String
#### Pascal string implementation

Pascal string holds length of string at the begining and then the string without `'\0'` character at the end.

There are two parts of the project.
* driver program
* implementation module

Implementation module contains p_strings.h and p_strings.c  
Driver program uses p_strings.h and dems APIs from p_strings.h

## APIs supported  
### _create p_string_
``` c
p_string p_create(size_t);
```
Creates a p_string object and returns p_string. Takes size of string as an input. 

### _destroy p_string_
``` c
void p_destroy(p_string*);
```
Destroys the underlying p_string object

### _read p_string_
``` c
char read(const p_string*, size_t);
```
Returns a character at the ith index, asserts on illegal index

### _write p_string_
``` c
void write(p_string*, char);
```
Writes a character at the ith index, asserts on illegal index

### _string length_
``` c
size_t pstrlen(const p_string *);
```
Returns length of underlying string.

### _string compare_
``` c
int pstrcmp(const p_string *, const p_string *);
```
Compare 2 p_string and returns -1, 0, 1 similar to strcmp().

### _string concatenation_
``` c
p_string* pstrcat(p_string *, const p_string *);
```
Concatenate string2 into string1, like strcat(), and returns modified p_string

### _string copy_
``` c
p_string pstrcpy(const p_string*);
```
Creates duplicate copy of p_string and returns

### _string to p_string_
``` c
p_string* toP_string(const char *);
```
Converts `\0` terminated string to p_string

### _p_string to string_
``` c
char* toString(p_string*);
```
Converts to p_string to `'\0'` terminated string