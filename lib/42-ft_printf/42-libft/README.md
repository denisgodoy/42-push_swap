![ImperativeProgramming](https://img.shields.io/badge/ImperativeProgramming-306998) ![Rigor](https://img.shields.io/badge/Rigor-306998) ![Algorithms&AI](https://img.shields.io/badge/Algorithms&AI-306998)

# Libft :computer:
Writing my own C library functions.

- [Evaluation](https://github.com/denisgodoy/42-libft#evaluation)
- [Part 1 - Libc functions](https://github.com/denisgodoy/42-libft#part-1---libc-functions)
- [Part 2 - Additional functions](https://github.com/denisgodoy/42-libft#part-2---additional-functions)
- [Bonus part](https://github.com/denisgodoy/42-libft#bonus-part)

## Evaluation
![evaluation](https://user-images.githubusercontent.com/56933400/130153702-8f2c7ee7-0f47-4ffb-b96b-f3620741139c.png)
![badge](https://game.42sp.org.br/static/assets/achievements/libftm.png)

## Part 1 - Libc functions

| Function 	|  Description  |    Library   	|
|:--------:	|:------------:	|:------------:	|
|  ft_strlen  	|Calculates the length of the string s, excluding the terminating null byte (aq\0aq).|   string.h   	|
|  ft_memset  	|Fills the first n bytes of the memory area pointed to by s with the constant byte c.|   string.h   	|
|   ft_bzero  	|Sets the first n bytes of the area starting at s to zero (bytes containing aq\0aq).|   string.h   	|
|  ft_memcpy  	|Copies n bytes from memory area src to memory area dest. The memory areas must not overlap.|   string.h   	|
|  ft_memmove 	|Copies n bytes from memory area src to memory area dest. The memory areas may overlap.|   string.h   	|
|  ft_strchr  	|Returns a pointer to the first occurrence of the character c in the string s.|   string.h   	|
|  ft_strrchr  |Returns a pointer to the last occurrence of the character c in the string s.|   string.h   	|
|  ft_strncmp 	|Compares the first n bytes of strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.|   string.h   	|
|  ft_memchr  	|Scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.|   string.h   	|
|  ft_memcmp  	|Compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.|   string.h   	|
|  ft_calloc  	|Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero.|   string.h   	|

| Function 	|  Description  |    Library   	|
|:--------:	|:------------:	|:------------:	|
|  ft_strlcpy 	|Copy strings. Designed to be safer, more consistent, and less error prone replacement for strncpy(3).|    bsd/string.h   	|
|  ft_strlcat 	|Concatenate strings. Designed to be safer, more consistent, and less error prone replacement for strncat(3).|    bsd/string.h   	|
|  ft_strnstr 	|Locates the first occurrence of the	null-terminated string needle in the	string haystack, where not more than len characters are searched.|    bsd/string.h   	|

| Function 	|  Description  |    Library   	|
|:--------:	|:------------:	|:------------:	|
|   ft_atoi   	|Converts the initial portion of the string pointed to by str to int.|    stdlib.h   	|
|  ft_strdup  	|Returns a pointer to a new string which is a duplicate of the string s. Memory for the new string is obtained with malloc(3), and can be freed with free(3).|    stdlib.h   	|

| Function 	|  Description  |    Library   	|
|:--------:	|:------------:	|:------------:	|
|  ft_isalpha 	|Checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper(c) or islower(c)).|    ctype.h   	|
|  ft_isdigit 	|Checks for a digit (0 through 9).|    ctype.h   	|
|  ft_isalnum 	|Checks for an alphanumeric character; it is equivalent to (isalpha(c) or isdigit(c)).|    ctype.h   	|
|  ft_isascii 	|Checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.|    ctype.h   	|
|  ft_isprint 	|Checks for any printable character including space.|    ctype.h   	|
|  ft_toupper 	|Converts the letter c to upper case, if possible.|    ctype.h   	|
|  ft_tolower 	|Converts the letter c to lower case, if possible.|    ctype.h   	|

## Part 2 - Additional functions

| Function 	|  Description  |
|:--------:	|:------------:	|
|  ft_substr 	|Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.|
|  ft_strjoin 	|Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.|
|  ft_strtrim 	|Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.|
|  ft_split 	|Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.|
|  ft_itoa 	|Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.|
|  ft_strmapi 	|Applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc(3)) resulting from successive applications of ’f’.|
|  ft_striteri 	|Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary.|
|  ft_putchar_fd 	|Outputs the character ’c’ to the given file descriptor.|
|  ft_putstr_fd 	|Outputs the string ’s’ to the given file descriptor.|
|  ft_putendl_fd 	|Outputs the string ’s’ to the given file descriptor, followed by a newline.|
|  ft_putnbr_fd 	|Outputs the integer ’n’ to the given file descriptor.|

## Bonus part

| Function 	|  Description  |
|:--------:	|:------------:	|
|  ft_lstnew 	|Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.|
|  ft_lstadd_front 	|Adds the element ’new’ at the beginning of the list.|
|  ft_lstsize 	|Counts the number of elements in a list.|
|  ft_lstlast 	|Returns the last element of the list.|
|  ft_lstadd_back 	|Adds the element ’new’ at the end of the list.|
|  ft_lstdelone 	|Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed.|
|  ft_lstclear 	|Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL.|
|  ft_lstiter 	|Iterates the list ’lst’ and applies the function ’f’ to the content of each element.|
|  ft_lstmap	|Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.|
