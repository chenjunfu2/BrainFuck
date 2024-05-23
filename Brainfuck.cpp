#include "Brainfuck.hpp"
//通过定义改变模式
#define _Execute
//#define _ConvertToDefine
#define _ConvertToCLanguage

//把要执行的代码放在这里面（宏定义版本或C版本）
void Execute(void)
{
/*
#测试用例：

#输出hello world
++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.
#加法，读入两个数a和b输出a加上b的结果
,>,>++++++[<-------->-]<[<+>-]<.
#除法，读入两个数a和b输出a除以b的结果
,>,>++++++[-<--------<-------->>]<<[>[->+>+<<]>[-<<-[>]>>>[<[>>>-<<<[-]]>>]<<]>>>+<<[-<<+>>]<<<]>[-]>>>>[-<<<<<+>>>>>]<<<<++++++[-<++++++++>]<.
#读入两个数，输出左边比右边的大小：
	,>,		#read char to [0] [1]
	>		#goto [2]
	[-]+	#[2]=1
	>>[-]	#[4]=0
	<<		#goto [2]
	[		#while([2]!=0)
		>[-]+	#[3]=1
		<<<		#goto [0]
		[		#while([0]!=0)
			[->>>>+<<<<]	#move [0] to [4]
			>>>[-]			#[3]=0
			<<<				#goto [0]
		]		#while([0]!=0)
		>>>		#goto [3]
		[		#while([3]!=0)
			<[-]	#[2]=0
			>[-]	#[3]=0
		]		#while([3]!=0)
		>-[-<<<<+>>>>]		#--[4] and move [4] to [0]
		<[-]+	#[3]=1
		<<		#goto [1]
		[			#while([1]!=0)
			[->>>+<<<]		#move [1] to [4]
			>>[-]			#[3]=0
			<<				#goto [1]
		]			#while([1]!=0)
		>>		#goto [3]
		[		#while([3]!=0)
			<[-]	#[2]=0
			>[-]	#[3]=0
		]		#while([3]!=0)
		>-[-<<<+>>>]		#--[4] and move [4] to [1]
		<<		#goto [2]
	]		#while([2]!=0)
	+		#[2]=1
	<<+		#++[0]
	[		#while([0]!=0)
		[-]>>[-]		#[0]=[2]=0
		#now at [2] do something and goto [0]
		>++++++++[>++++++++<-]>--.<<		#write '>'
		<<		#goto [0]
	]		#while([0]!=0)
	>>		#goto [2]
	[		#while([2]!=0)
		[-]+	#[2]=1
		<+		#++[1]
		[		#while([1]!=0)
			[-]>[-]		#[1]=[2]=0
			#now at [2] do something and goto [1]
			>++++++++[>++++++++<-]>----.<<		#write '<'
			<		#goto [1]
		]		#while([1]!=0)
		>		#goto [2]
		[		#while([2]!=0)
			#now at [2] do something and goto [2]
			>++++++++[>++++++++<-]>---.<<		#write '='
			[-]		#[2]=0
		]		#while([2]!=0)
	]		#while([2]!=0)
*/
	*ptr = getchar(); ++ptr; *ptr = getchar();
	++ptr;
	while (*ptr)
	{
		-- *ptr;
	}++ *ptr;
	++ptr; ++ptr; while (*ptr)
	{
		-- *ptr;
	}
	--ptr; --ptr;
	while (*ptr)
	{
		++ptr; while (*ptr)
		{
			-- *ptr;
		}++ *ptr;
		--ptr; --ptr; --ptr;
		while (*ptr)
		{
			while (*ptr)
			{
				-- *ptr; ++ptr; ++ptr; ++ptr; ++ptr; ++ *ptr; --ptr; --ptr; --ptr; --ptr;
			}
			++ptr; ++ptr; ++ptr; while (*ptr)
			{
				-- *ptr;
			}
			--ptr; --ptr; --ptr;
		}
		++ptr; ++ptr; ++ptr;
		while (*ptr)
		{
			--ptr; while (*ptr)
			{
				-- *ptr;
			}
			++ptr; while (*ptr)
			{
				-- *ptr;
			}
		}
		++ptr; -- *ptr; while (*ptr)
		{
			-- *ptr; --ptr; --ptr; --ptr; --ptr; ++ *ptr; ++ptr; ++ptr; ++ptr; ++ptr;
		}
		--ptr; while (*ptr)
		{
			-- *ptr;
		}++ *ptr;
		--ptr; --ptr;
		while (*ptr)
		{
			while (*ptr)
			{
				-- *ptr; ++ptr; ++ptr; ++ptr; ++ *ptr; --ptr; --ptr; --ptr;
			}
			++ptr; ++ptr; while (*ptr)
			{
				-- *ptr;
			}
			--ptr; --ptr;
		}
		++ptr; ++ptr;
		while (*ptr)
		{
			--ptr; while (*ptr)
			{
				-- *ptr;
			}
			++ptr; while (*ptr)
			{
				-- *ptr;
			}
		}
		++ptr; -- *ptr; while (*ptr)
		{
			-- *ptr; --ptr; --ptr; --ptr; ++ *ptr; ++ptr; ++ptr; ++ptr;
		}
		--ptr; --ptr;
	}
	++ *ptr;
	--ptr; --ptr; ++ *ptr;
	while (*ptr)
	{
		while (*ptr)
		{
			-- *ptr;
		}++ptr; ++ptr; while (*ptr)
		{
			-- *ptr;
		}

		++ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; while (*ptr)
		{
			++ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; --ptr; -- *ptr;
		}++ptr; -- *ptr; -- *ptr; putchar(*ptr); --ptr; --ptr;
		--ptr; --ptr;
	}
	++ptr; ++ptr;
	while (*ptr)
	{
		while (*ptr)
		{
			-- *ptr;
		}++ *ptr;
		--ptr; ++ *ptr;
		while (*ptr)
		{
			while (*ptr)
			{
				-- *ptr;
			}++ptr; while (*ptr)
			{
				-- *ptr;
			}

			++ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; while (*ptr)
			{
				++ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; --ptr; -- *ptr;
			}++ptr; -- *ptr; -- *ptr; -- *ptr; -- *ptr; putchar(*ptr); --ptr; --ptr;
			--ptr;
		}
		++ptr;
		while (*ptr)
		{

			++ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; while (*ptr)
			{
				++ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; ++ *ptr; --ptr; -- *ptr;
			}++ptr; -- *ptr; -- *ptr; -- *ptr; putchar(*ptr); --ptr; --ptr;
			while (*ptr)
			{
				-- *ptr;
			}
		}
	}
}


int main(void)
{
	
	
#if defined _Execute
	Execute();
#elif defined _ConvertToCLanguage
	ConvertToCLanguage();
#elif defined _ConvertToDefine
	ConvertToDefine();
#else
	return 114514;
#endif
	return 0;
}