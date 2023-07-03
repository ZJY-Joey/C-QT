### C-QT 一个C++与qt联合开发的计算器程序——大一下
增加了图形交互功能，能够处理逻辑运算符和算术运算符的混合运算，增加容错功能。 


------------------
##### 整体设计思路如下
<img width="1000" alt="image" src="https://github.com/ZJY-Joey/C-QT/assets/113656901/04fc1904-6a53-4b1c-aaec-1eaeb2114e5b">

------------------
##### 实验数据如下

（1）0|(2*3/2)&!(5/5-1)  =  1     用于测试算数运算符和逻辑运算符混合运算
（2）2*!6  =  0    ！！6  = 1   用于测试算数优先级
（3） 1！6  = ERROR            用于测试容错异常提醒
（4）&5 = 1    2+5 = 7           用于测试默认提示的文本0与不同起始符号的输出，避免01出现
（5）！3.14 +（6.28 / 3.12）*5.13  用于测试带小数点符号的计算
（6）清除键和清空键运行良好。

------------------
##### 主界面截图+计算结果测试截图（风格仿win10自带圆角风格）

<img width="700" alt="image" src="https://github.com/ZJY-Joey/C-QT/assets/113656901/2a1613e2-78ed-45f3-8a97-8aa7cbf2e306">

![image](https://github.com/ZJY-Joey/C-QT/assets/113656901/1290ce56-9773-4528-87c7-7b637ec335ea)

![image](https://github.com/ZJY-Joey/C-QT/assets/113656901/c35a5415-0416-46dc-81b2-4f6a6724fe99)


-------------------
##### 软件版本
QT 5.9.7版本 + visual studio开发

