//模拟实现字符串函数
size_t my_strlen(char * str)
{
	char * p = str;
	while(*p)
	{
		p++;
	}
	return p-str;
}


//方式二：不创建临时变量
size_t my_strlen(char * str)
{
	if(*str == ‘\0')
	{
		return 0;
	}
	
	return 1+my_strlen(str++);
}


char* my_strcpy(char *des,const char *src)
{
	char *ret = des;
	assert(des != NULL);//断言，防传入空指针
	
	while((*des++ = *src++))
	{
		;
	}
	return ret;
}

char* my_strcat(char *des,char *src)
{
	char *ret = des;
	assert(des != NULL);
	assert(src != NULL);
	
	while(*des != '\0')//现将指针一道des尾部
	{
		des++;
	}
	
	while((*des++ = *src++))
	{
		;
	}
	
	return ret;
}



char *my_strstr(const char *str1,const char *str2)
{
	assert(str1);
	assert(str2);
	
	if(*str2 == '\0')
	{
		return NULL;
	}
	
	char *cp = (char*)str1;
	char *substr = (char*)str2;
	char *s1 = NULL;
	
	while(*cp)
	{
		s1 = cp;
		substr = str2;
		
		while(*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		
		if(*substr == ’\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;
}



int my_strcmp(const char* src,const char* des)
{
	assert(src);
	assert(des);
	
	while(*src == *des)
	{
		if(*src == '\0')
			return 0;
		src++;
		des++;
	}
	
	return *src - *des;
}

void test30()
{
	char arr[] = { "hello world" };
	strcat(arr, arr);
}
//}

void test31()
{
	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not");
	strncat(str1, str2, 9);
	puts(str1);
}

void test32()
{
	char str[][5] = { "R2D2", "C3PO", "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n<3; n++)
	if (strncmp(str[n], "R2xx", 2) == 0)
	{
		printf("found %s\n", str[n]);
	}
}

//方式一：计数
size_t my_strlen1(char * str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//方式二：不创建临时变量
size_t my_strlen2(char * str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen2(str+1);
}


//方式三：指针 - 指针
size_t my_strlen3(char * str)
{
	char * p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}


void test33()
{
	char *ptr = "hello world";
	printf("%d\n", my_strlen1(ptr));
}

#include<assert.h>

int my_strcmp(const char* src, const char* des)
{
	int ret = 0;
	assert(src);
	assert(des);

	while (*src == *des)
	{
		if (*src == '\0')
			return 0;
		src++;
		des++;
	}

	ret = *src - *des;

	if (ret < 0)
		return -1;
	return 1;
	
}

char *my_strstr(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	if (*str2 == '\0')
	{
		return NULL;
	}

	char *cp = (char*)str1;
	char *substr = (char*)str2;
	char *s1 = NULL;

	while (*cp)
	{
		s1 = cp;
		substr = (char*)str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}

		if (*substr == '\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;
}
//int main()
//{
//
//	//int ret = test19("hello world");
//
//	//printf("%d\n", ret);
//
//	char *p1 = "ppaaa";
//	char *p2 = "pp";
//	printf("%c\n", *(my_strstr(p1, p2)));
//	system("pause");
//	return 0;
//}


int main()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if (n>0) printf("'%s' is greater than 	'%s'.\n", buffer1, buffer2);
	else if (n<0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	system("pause");
	return 0;
}


