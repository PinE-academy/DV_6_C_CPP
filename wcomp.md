# wcomp - word completion 
**wcomp** takes database and scheme as input and prints matching string on the console.

``` sh
usage: wcomp -f file -s scheme word
```

\<file> contains lookup strings  
\<scheme> can be strict, pattern, fuzzy  
\<word> to look for in strings

| Scheme | Description |
|--------|-------------|
| `strict` | Matches string from the beginning |
| `pattern` | Matches for any occurances of word anywhere in the string |
| `fuzzy` | Fuzzy loop up, matches for sequence of characters from the word in the string |


There should be a module for each scheme. A module consists of a .h and .c file, where .h has declerations and .c has implementations.

#### Each module should provides 2 API
1. Loads database  
Takes file as input and returns a optimised database for lookup

2. Lookup  
Searches the database for the word and returns array of strings found or NULL

# Examples
For a database file _database_ that contains:
> This is a string.  
> Another line with string.  
> Just a simple line.

## _strict_ scheme

``` sh
wcomp -f database -s strict "This"
```
<dl>
<b>This</b> is a string.
</dl>

## _pattern_ scheme

``` sh
wcomp -f database -s pattern "string"
```
<dl>
This is a <b>string</b><br>
Another line with <b>string</b>.
</dl>

## _fuzzy_ scheme

``` sh
wcomp -f database -s fuzzy "si"
```

<dl>
Thi<b>s</b> <b>i</b>s a string.<br>
Another line with <b>s</b>tr<b>i</b>ng.
</dl>