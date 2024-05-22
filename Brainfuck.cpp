#include "Brainfuck.hpp"
//通过定义改变模式
//#define _Execute
#define _ConvertToCLanguage

//把要执行的代码放在这里面（宏定义版本或C版本）
void Execute(void)
{

}


int main(void)
{
	//测试用例：
	//输出hello world：++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.
	//加法，读入两个数a和b输出a加上b的结果：,>,>++++++[<-------->-]<[<+>-]<.
	//除法，读入两个数a和b输出a除以b的结果：,>,>++++++[-<--------<-------->>]<<[>[->+>+<<]>[-<<-[>]>>>[<[>>>-<<<[-]]>>]<<]>>>+<<[-<<+>>]<<<]>[-]>>>>[-<<<<<+>>>>>]<<<<++++++[-<++++++++>]<.

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