#include <iostream>//和c一样在使用输入输出时必须引入头文件stdio.h
using namespace std;

int main()
{
 cout<<"hellow ixu"<<endl;//输出一行字符串（所以是“ ”） hellow ixu  cout 理解成c++输出 <<表示出
 cout<<"请输入姓名"<<endl;
 string name;//定义一个字符串变量用来保存输入的数据
 cin>>name;//把输入的数据赋给name >>表示入(插入运算符)
 cout<<"你的名字是"<<name<<endl;//在一行中显示 你的名字是name（敲进去的名字） 直到遇到endl时自动换行即可以 cout<<"123";
 cin.get();//等待键盘输入
 cin.get();//如果不加上则在cin>>name时检测到回车在上一个cin.get就退出执行了
}
/*主函数这么复杂可以把里面的东西定义成一个函数 我们在主函数中调用即可把其中的提示性输出以及输入的语句定义成函数
 与c一样如果函数的定义是在其他文件或主函数之后则我们需要在调用函数之前（预编译指令之后）
 对函数进行声明如void welcome（）；告诉编译器我们调用的函数长什么样