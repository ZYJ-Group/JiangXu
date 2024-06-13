scanf连续获取字符时需要吸收垃圾字符
只有%c获取数据的情况下需要吸收垃圾字符
#include <stdio.h>
int main(int argc, const char *argv[])
{
    char c1,c2,c3;
    scanf("%c%c%c",&c1,&c2,&c3);
    printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);
    return 0;
}


#include <stdio.h>
int main(int argc, const char *argv[])
{
    char c1,c2,c3;
    //利用scanf严格控制格式的特点
 //终端输入的空格，会被双引号的空格格式吸收
    scanf("%c %c %c",&c1,&c2,&c3);
    printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);
    return 0;
}


在%c前面加空格
#include <stdio.h>
int main(int argc, const char *argv[])
{
    char c1,c2,c3;

    //在可能出现垃圾字符的位置放空格，空格会吸收掉所有的垃圾字符
    scanf("%c",&c1);
    scanf(" %c",&c2);
    scanf(" %c",&c3);
    printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);
    return 0;
}

通过抑制字符吸收
%*c:吸收一个字符但是不会获取给任何变量
不建议使用%*C,一定会吃掉一个字符
    
#include <stdio.h>
int main(int argc, const char *argv[])
{
    char c1,c2,c3;
    //利用scanf严格控制格式的特点
    scanf("%c%c%c",&c1,&c2,&c3);
    /*printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);*/

    //在可能出现垃圾字符的位置放空格，空格会吸收掉所有的垃圾字符
    /*scanf("%c",&c1);
    scanf(" %c",&c2);
    scanf(" %c",&c3);*/
    
    //通过抑制字符%*c吸收垃圾字符
    //scanf("%c%*c%c%*c%c",&c1,&c2,&c3);
    printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);
    return 0;
}

使用getchar吸收垃圾字符
#include <stdio.h>
int main(int argc, const char *argv[])
{
    char c1,c2,c3;
    //利用scanf严格控制格式的特点
    //scanf("%c%c%c",&c1,&c2,&c3);
    /*printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);*/

    //在可能出现垃圾字符的位置放空格，空格会吸收掉所有的垃圾字符
    /*scanf("%c",&c1);
    scanf(" %c",&c2);
    scanf(" %c",&c3);*/
    
    //通过抑制字符%*c吸收垃圾字符
    //scanf("%c%*c%c%*c%c",&c1,&c2,&c3);
    
    //使用getchar吸收垃圾字符
    //每用%c获取一个字符后，都加入一个getchar吸收掉空格、tab或者回车
    scanf("%c",&c1);
    getchar();
    scanf("%c",&c2);
    getchar();
    scanf("%c",&c3);
    printf("c1=%c\n",c1);
    printf("c2=%c\n",c2);
    printf("c3=%c\n",c3);
 


    return 0;
}

单个字符的输入函数getchar()
函数原型:
    int getchar(void);
    返回值:字符的ASCII码
    参数:(void),没有参数
功能:
    从终端获取单个字,并返回该字符ASCII码            


单个字符的输出函数putchar
函数原型:
    int putchar(int c);
    返回值:int
    参数:int c  ----->要输出的字符的ASCII码
功能:
    输出单个字符 
    putchar(10);  ---->\n换行   

#include <stdio.h>
int main(int argc, const char *argv[])
{
    char c1,c2;
    //使用getchar获取到的结果给c1赋值
 c1 = getchar();
    printf("%c",c1);
    //输出ascii为10的字符，\n
    putchar(10);
    putchar('a');
    putchar(10);
    return 0;
}

逻辑短路现象
逻辑与，如果左侧表达式结果为假，逻辑运算的结果为假，右侧的表达式不会执行
逻辑或，如果左侧表达式结果为真，逻辑运算的结果为真，右侧的表达式不会执行
#include <stdio.h>
int main(int argc, const char *argv[])
{
    int a=9,b=0;
    printf("%d\n",a+b&&b||b++);
    //--b没有执行
    printf("%d\n",a+b&&++b||--b);
    printf("%d\n",b);

    //前面b=2，!b=0  !a,b++不会执行 ,--a执行 a=8
    printf("%d\n",!b&&!a&&b++||--a);
    printf("a=%d\tb=%d\n",a,b);
    return 0;
}