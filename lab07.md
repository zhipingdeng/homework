---
layout: default
title: 硬件编程-机器指令编程
---

# 实验报告链接
[硬件编程-机器指令编程.pdf](硬件编程-机器指令编程.pdf)
# 任务1：简单程序
## （1）打开网页 The PIPPIN User’s Guide ，然后输入 Program 1：Add 2 number
![fdgh](http://m.qpic.cn/psb?/V12ukENm2cNWAn/cTIAdmdDj54xqmKgvfe2sX0TNw14NSdV1biDQuw4tSo!/b/dDYBAAAAAAAA&bo=agKyAgAAAAADB*o!&rf=viewer_4)
![fdgh](http://m.qpic.cn/psb?/V12ukENm2cNWAn/o5u7XA.0uowOmzgYc2*NAwsizMIar2v36eIbkzDkeEs!/b/dFMBAAAAAAAA&bo=agKqAgAAAAADF*I!&rf=viewer_4)

## （2）点step after step。观察并回答下面问题：
1）PC，IR 寄存器的作用。

IR 指令寄存器，用来保存当前正在执行的一条指令。

PC 程序计数器，存放下一条要执行指令在内存中的地址。

2）ACC 寄存器的全称与作用。

全称：The accumulator(A register)，用于存放操作的数据和结果。

3）用“LOD #3”指令的执行过程，解释Fetch-Execute周期

从 RAM 获取指令及数据(LOD #3) -> IR寄存器 -> Decoder(Decode instruction(LOD #3)) -> 数字3存在MUX(数据选择器)中 -> Decoder将LOD指令传给ALU -> ALU从MUX得到数字3 -> 累加到ACC上 -> PC累加2，用于存放下一条指令的地址 

4）用“ADD W” 指令的执行过程，解释Fetch-Execute周期。

从 RAM 获取指令及数据(ADD W) -> IR寄存器 -> Decoder(Decode instruction(ADD W)) -> MUX(数据选择器)从 RAM 中获取W对应地址的内容，即数值3 -> Decoder将ADD指令传给ALU -> ALU从MUX得到数字3 -> 累加到ACC上 -> PC累加2，用于存放下一条指令的地址

5）“LOD #3” 与 “ADD W” 指令的执行在Fetch-Execute周期级别，有什么不同。

指令“LOD #3”在经过IR寄存器时，将数据3直接传给MUX，使ALU直接提取，给ACC赋值；指令“ADD W”在经过IR寄存器时，将ADD操作信号传给ALU，所以MUX还需再访问RAM获取W的内容，再使ALU提取，将W的值累加到ACC上。
## （3）点击“Binary”,观察回答下面问题
![fdgh](http://m.qpic.cn/psb?/V12ukENm2cNWAn/hutcNu.0vGuc.m5QoWCuX5hrJvzDcd7zgP3G1TaG*lU!/b/dFMBAAAAAAAA&bo=awKvAgAAAAADF*Y!&rf=viewer_4)
1）	写出指令 “LOD #7” 的二进制形式，按指令结构，解释每部分的含义。

LOD #7的二进制：0001 0100 0000 0111

第一个字节的含义：指令说明符中的操作码，对应LOD操作

第二个字节的含义：操作数说明符，此处为数值7的二进制码

2）	解释 RAM 的地址

RAM的地址被分为两部分，其中第一部分地址用来储存指令，包括指令说明符以及操作数说明符；第二部分地址用来标识变量的地址，具体存储变量的值。

3）	该机器CPU是几位的？（按累加器的位数）

8位

4）	写出该程序对应的 C语言表达

    #include<stdio.h>
    int main(){
	    int w=3;
	    w+=7;
	    return 0;
    }









# 任务2：简单循环
## （1）	输入程序Program 2，运行并回答问题：
![fdgh](http://m.qpic.cn/psb?/V12ukENm2cNWAn/ta1n2GT7u2iPg2Pr9gpkkffCRFEN*4azuRBpS2NqxTA!/b/dDQBAAAAAAAA&bo=bwKzAgAAAAADF.4!&rf=viewer_4)

1）用一句话总结程序的功能

给赋X一非零初值，进入循环，每次循环X减去1，直到X为1时ACC寄存器存着0，程序结束。

2）写出对应的 c 语言程序

    #include<stdio.h>
    int main(){
	    int x=3;
	    while((x-1)!=0){
	    	x--;
        }
	    return 0;
    }

## （2）修改该程序，用机器语言实现 10+9+8+..1 ，输出结果存放于内存 Y

![fdgh](http://m.qpic.cn/psb?/V12ukENm2cNWAn/PSSKsAb4L0QWyL46QFg1Ipgfq87oem*AQkbi6QiNqFM!/b/dDABAAAAAAAA&bo=bQKtAgAAAAADF*I!&rf=viewer_4)
![fdgh](http://m.qpic.cn/psb?/V12ukENm2cNWAn/7WyhVRiLusB4DXiPkS2N8VXhdK2yhQqh0P.s9aB2U8s!/b/dDYBAAAAAAAA&bo=bQJqAgAAAAADFzU!&rf=viewer_4)

1）写出 c 语言的计算过程

    #include<stdio.h>
    int main(){
        int x,y;
        for(x=10;(x-1)!=0;--x){
            y+=x;
        }
        y+=x;
        return 0;
    }

2） 写出机器语言的计算过程

对变量X和Y分别赋初值10和0，再用循环，每次先LOD Y，再ADD X然后将该值赋给Y，即STO Y ，然后X减去1，每次均设条件跳转JMZ 16语句判断ACC当前值是否为0，若为零，则跳出循环，此时Y即为结果，若不为零，则经过无条件跳转语句JMP 0回到LOD X那一步，直至X=1即ACC寄存器存着0时。

3）用自己的语言，简单总结高级语言与机器语言的区别与联系

区别：高级语言是编一些应用软件，与硬件不直接打交道的语言，比较直接，易懂。机器语言是计算机直接能够接受和应用的语言，一般人难以理解。

联系：高级语言从机器语言发展而来，高级语言最终都通过编译器转换成机器语言。
