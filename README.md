# BrainFuck
关于BrainFuck语言的一些无聊的研究

项目介绍：

本项目包含两个源文件

1.Brainfuck.hpp

  用于表示bf语言关键字的宏定义
  
  用于支持从bf编译到cpp代码之后执行的类BrainFuckPtr
  
  以及用于从bf代码编译到c代码的转换函数（ConvertToCLanguage）或表示bf语言关键字的宏定义的转换函数（ConvertToDefine）
  
2.Brainfuck.cpp

  用于切换功能的宏定义：执行模式、转换bf到c代码、转换bf到宏定义

用法：

  请先在cpp文件顶部宏定义处切换模式位转换模式（两种转换都行，无所谓）
    
  然后编译执行程序后，把对应的bf代码粘贴到程序输入框内，或者通过命令行重新向标准io流将包含bf代码的文件作为输入，然后指定输出文件
    
  接着把输出文件内容，或者直接执行程序转换后的输出复制一下，直接粘贴到cpp内的Execute函数内部，并把顶部的宏定义切换为Execute模式

  然后编译执行，即可运行bf代码

说明：

  本bf编译器支持单行注释，以#开头，允许多行bf代码，自动忽略空白字符。

  为了输入回显方便，编译后的bf代码默认使用getchar，在用户换行后bf代码才会收到输入，
  
  如果需要bf代码自行处理回显之类的操作，请在hpp内修改编译器的默认转换行为，
  
  把getchar修改为getch（msvc下是_getch)，并在hpp顶部#include <conio.h>头文件，即可正常运行

