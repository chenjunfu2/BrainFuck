#pragma once
/*
字符		含义
>		指针加一
<		指针减一
+		指针指向的字节的值加一
-		指针指向的字节的值减一
.		输出指针指向的单元内容（ASCⅡ码）
,		输入内容到指针指向的单元（ASCⅡ码）
[		如果指针指向的单元值为零，向后跳转到对应的]指令的次一指令处
]		如果指针指向的单元值不为零，向前跳转到对应的[指令的次一指令处
*/

/*
Brainfuck	C
>			++ptr;
<			--ptr;
+			++*ptr;
-			--*ptr;
.			putchar(*ptr);
,			*ptr=getch();
[			while (*ptr) {
]			}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R /*>*/ ++ptr;			
#define L /*<*/ --ptr;			
#define A /*+*/ ++*ptr;			
#define S /*-*/ --*ptr;			
#define P /*.*/ putchar(*ptr);			
#define G /*,*/ *ptr=getch();			
#define W /*[*/ while (*ptr) {			
#define M /*]*/ }

class BrainFuckPtr//自动扩容的Ptr指针，用于BrainFuck语言
{
private:
	unsigned char *pBase;//基地址指针
	size_t szIndex;//当前位置下标
	size_t szSize;//数组总大小
public:
	void Clean(void)//清理
	{
		free(pBase);
		pBase = NULL;
		szIndex = 0;
		szSize = 0;
	}

	void Expand(void)//扩容
	{
		unsigned char *pNewBase = (unsigned char *)realloc(pBase, sizeof(*pBase) * szSize * 2);//二倍
		if (pNewBase == NULL)
		{
			Clean();
			printf("内存扩容失败");
			exit(0);
		}
		//新位置（后半段）置零
		memset(&pBase[szSize + 1], 0, sizeof(*pBase) * szSize);
		szSize *= 2;
	}
public:
	BrainFuckPtr(const BrainFuckPtr &) = delete;//禁止拷贝
	BrainFuckPtr &operator=(const BrainFuckPtr &) = delete;//禁止赋值

	BrainFuckPtr(size_t _szSize = 8) : pBase(NULL), szIndex(0), szSize(_szSize == 0 ? 1 : _szSize)//szSize保证至少为1
	{
		pBase = (unsigned char *)malloc(sizeof(*pBase) * szSize);
		if (pBase == NULL)
		{
			Clean();
			printf("内存分配失败");
			exit(0);
		}
		memset(pBase, 0, sizeof(*pBase) * szSize);//置零
	}

	~BrainFuckPtr(void)//析构
	{
		Clean();
	}

	BrainFuckPtr &operator++(void)//前缀++
	{
		if (++szIndex >= szSize)//防止后向越界
		{
			Expand();//越界扩容
		}
		return *this;
	}

	BrainFuckPtr &operator--(void)//前缀--
	{
		if (szIndex > 0)//防止前向越界
		{
			--szIndex;
		}
		return *this;
	}

	unsigned char &operator*(void)//解引用
	{
		return pBase[szIndex];//szIndex在其他地方保证不越界，无需检查
	}
}ptr;

void ConvertToCLanguage(void)
{
	//转换代码（brain fuck到直接的c语言代码）
	int c;
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case'>':
			printf("++ptr;");
			break;
		case'<':
			printf("--ptr;");
			break;
		case'+':
			printf("++*ptr;");
			break;
		case'-':
			printf("--*ptr;");
			break;
		case'.':
			printf("putchar(*ptr);");
			break;
		case',':
			printf("*ptr=getchar();");
			break;
		case'[':
			printf("while(*ptr){");
			break;
		case']':
			printf("}");
			break;
		case '\n':
			printf("\n");
			break;
		default:
			printf("\n\'%c\'[ASCII:%d] is unknow!\n", c, c);
			break;
		}
	}
}

void ConvertToDefine(void)
{
	//转换代码（brain fuck到宏定义）
	int c;
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case'>':
			printf("R ");
			break;
		case'<':
			printf("L ");
			break;
		case'+':
			printf("A ");
			break;
		case'-':
			printf("S ");
			break;
		case'.':
			printf("P ");
			break;
		case',':
			printf("G ");
			break;
		case'[':
			printf("W ");
			break;
		case']':
			printf("M ");
			break;
		case '\n':
			printf("\n");
			break;
		default:
			printf("\n\'%c\'[ASCII:%d] is unknow!\n", c, c);
			break;
		}
	}
}