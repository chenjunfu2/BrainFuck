#pragma once
/*
�ַ�		����
>		ָ���һ
<		ָ���һ
+		ָ��ָ����ֽڵ�ֵ��һ
-		ָ��ָ����ֽڵ�ֵ��һ
.		���ָ��ָ��ĵ�Ԫ���ݣ�ASC���룩
,		�������ݵ�ָ��ָ��ĵ�Ԫ��ASC���룩
[		���ָ��ָ��ĵ�ԪֵΪ�㣬�����ת����Ӧ��]ָ��Ĵ�һָ�
]		���ָ��ָ��ĵ�Ԫֵ��Ϊ�㣬��ǰ��ת����Ӧ��[ָ��Ĵ�һָ�
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

class BrainFuckPtr//�Զ����ݵ�Ptrָ�룬����BrainFuck����
{
private:
	unsigned char *pBase;//����ַָ��
	size_t szIndex;//��ǰλ���±�
	size_t szSize;//�����ܴ�С
public:
	void Clean(void)//����
	{
		free(pBase);
		pBase = NULL;
		szIndex = 0;
		szSize = 0;
	}

	void Expand(void)//����
	{
		unsigned char *pNewBase = (unsigned char *)realloc(pBase, sizeof(*pBase) * szSize * 2);//����
		if (pNewBase == NULL)
		{
			Clean();
			printf("�ڴ�����ʧ��");
			exit(0);
		}
		//��λ�ã����Σ�����
		memset(&pBase[szSize + 1], 0, sizeof(*pBase) * szSize);
		szSize *= 2;
	}
public:
	BrainFuckPtr(const BrainFuckPtr &) = delete;//��ֹ����
	BrainFuckPtr &operator=(const BrainFuckPtr &) = delete;//��ֹ��ֵ

	BrainFuckPtr(size_t _szSize = 8) : pBase(NULL), szIndex(0), szSize(_szSize == 0 ? 1 : _szSize)//szSize��֤����Ϊ1
	{
		pBase = (unsigned char *)malloc(sizeof(*pBase) * szSize);
		if (pBase == NULL)
		{
			Clean();
			printf("�ڴ����ʧ��");
			exit(0);
		}
		memset(pBase, 0, sizeof(*pBase) * szSize);//����
	}

	~BrainFuckPtr(void)//����
	{
		Clean();
	}

	BrainFuckPtr &operator++(void)//ǰ׺++
	{
		if (++szIndex >= szSize)//��ֹ����Խ��
		{
			Expand();//Խ������
		}
		return *this;
	}

	BrainFuckPtr &operator--(void)//ǰ׺--
	{
		if (szIndex > 0)//��ֹǰ��Խ��
		{
			--szIndex;
		}
		return *this;
	}

	unsigned char &operator*(void)//������
	{
		return pBase[szIndex];//szIndex�������ط���֤��Խ�磬������
	}
}ptr;

void ConvertToCLanguage(void)
{
	//ת�����루brain fuck��ֱ�ӵ�c���Դ��룩
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
	//ת�����루brain fuck���궨�壩
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