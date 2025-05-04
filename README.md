# BrainFuck
关于BrainFuck语言的一些无聊的研究。

### 项目介绍：

本项目包含两个源文件。

1.Brainfuck.hpp

  用于表示bf语言关键字的宏定义（用于直接编写，不过受限于cpp编译器，没办法使用bf原生符号作为宏定义）。
  
  用于支持从bf编译到c代码之后等效执行的类BrainFuckPtr。
  
  用于支持从bf代码编译到c代码的转换函数（ConvertToCLanguage）或表示bf语言关键字的宏定义的转换函数（ConvertToDefine）。
  
2.Brainfuck.cpp

  用于切换功能的宏定义：执行模式、转换bf到c代码、转换bf到宏定义。

  用于放入bf转换为c后的代码的执行函数Execute。

  主函数main，根据文件开头的宏定义选择程序最终行为。

### 用法：

  请先在cpp文件顶部宏定义处切换模式位转换模式_ConvertToDefine或_ConvertToCLanguage（两种转换都行，无所谓）。
    
  在转换模式下编译程序后有两种选择：
    
    1.执行程序，把对应的bf代码粘贴到程序输入框内后回车转换。
    
    2.通过命令行重新向标准io流，将包含bf代码的文件作为输入，然后指定输出文件（比如在cmd中：Brainfuck.exe < input.bf > output.c）。
    
  接着把程序输出内容（或转换后输出的文件内容）复制一下，直接粘贴到Brainfuck.cpp中的Execute函数内部，并把顶部的宏定义切换为_Execute模式。

  然后让cpp编译器编译并执行程序，即可运行cpp等效的bf代码。

### 说明：

  本bf编译器支持单行注释，以#开头，允许多行bf代码，自动忽略空白字符。

  为了用户输入回显方便，编译bf后的c代码默认使用getchar获得用户输入，在用户换行后bf代码才会收到输入，
  
  如果需要bf代码自行处理回显之类（或无缓冲区输入等）的操作，请在Brainfuck.hpp内的转换函数ConvertToCLanguage中，
  
  把函数里所有的printf里的getchar改了，然后在文件开头附近找到宏定义，把#define G /\*,\*/ \*ptr=getchar();里的getchar也改了，

  一般是把getchar修改为getch，但是如果你用的编译器是msvc，则修改为_getch，
  
  最后在上面#include <conio.h>头文件，即可正常运行。
