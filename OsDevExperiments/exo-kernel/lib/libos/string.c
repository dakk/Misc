#include "string.h"

char *_strstr(char *a, char *b)
{
	return a;
}

/* copy a string in another after first n byte */
void _strncpy2(char *str1, char *str2, size_t n)
{
	str2 = str2 + n;
	
	_strcpy(str1, str2);
}



/* return the len of a string */
size_t _strlen(const char *str)
{
	size_t x = 0;

	while(*str++ != '\0') x++;
		
	return x;
}


/* copy a string in another */
void _strcpy(char *str1, char *str2)
{
	while(*str2 != '\0')
	{
		*str1 = *str2;
		str1++; str2++;
	}
	*str1 = '\0';
}


/* join 2 strings */
void _strcat(char *str1, char *str2)
{
	while(*str1 != '\0') str1++;
	
	while(*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
}


/* compare two strings */
int _strcmp(const char *s1, const char *s2)
{	
	while(1)
	{
		if(*s1 != *s2) return 1;
		else if(*s1 == '\0' && *s2 == '\0') return 0;
		s1++; 
		s2++;
	}
}




/* compare the first n bytes of two strings */
int _strncmp(const char *s1, const char *s2, size_t dim)
{
	int a = 0;
	
	while(a < dim)
	{
		if(*s1 != *s2) return 1;
		else if(*s1 == '\0' && *s2 == '\0') return 0;
		s1++; 
		s2++;
		a++;
	}	
	return 0;
}



