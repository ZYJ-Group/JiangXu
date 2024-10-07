


## 这就是python中的while循环 while 条件 ：

```py
while condition<10:
   print(condition)
   conditiom=conditiom+1
```
  >：号表示这是一个函数等语句 他的函数体范围是下面缩进（4）的部分
## 会依次输出上面的值这就是python中的for循环

```py
condition_list=[1,2,3,45,66,554,454,454,2,2]
for i in condition_list:
    print(i)
    
#或者 会输出1~9（不会到10）
for i in range(1,10):
   print(i)
for i in range(1,20,2):       #其中（1，20，2）表示循环一次的步长是2 从1开始到19结束
   print(i)

```
## if语句 

```py
x=1
y=2
if x<y:
   print('x比y小')
   
## if else语句
if x<y :
  print()
else:
  print()
  
#if elif else语句
if x<1:
   print()
elif x>1:
   print()
else:
  print()
```
## def定义函数
```py
def sum（a，b）：
 sum=a+b;
 print（'和是'，sum） 
 return sum
```
```py
如果想输出函数返回的值print（sum（1，2））
```
> 定义函数时用def 后面有：调用函数的时候没有：


## 全局 局部变量

> 在函数之内的变量是局部变量 之外的是全局变量
```py
A=100 #A是一个全局便量
def sum（a，b）：
 sum=a+b;  #a b是一个局部变量
 print（'和是'，sum） 
```
## 文件读写（操作后要关闭）
**写文件**
```py
my_file=open('file.txt','w')#以write的形式打开(创建)文件保存至my_file中
my_file=open('file.txt','r')#以read的形式打开文件
text='在这里加入这段话：\n天行健君子以自强不息' #创建一个文字
my_file.write(text)   #把text的文本加入到file.txt中
my_file.close()  #关闭文件
```
```py
> 追加文本
append_text='\n追加的文字'
my_file=open('file.txt','a')#以append（追加）的形式打开文件
my_file.write(append_text)
my_file.close()
```
**读文件**
> 使用read（num）去读取文件，num是读多少个字节，如果没有传入num，就直接读取整个文件的数据

```py
file=open(‘my_file.txt’,'r')           #以读的形式打开文件
content=file.read()                    #读一个文件
content=file.readlines()               #读所有的行
first_content=file.readline()          #读第一行 每次操作只读一行
second_content=file.readline()         #读第二行
print(content)
print(content，first_content)
print(content，second_content)
```

**文件相关操作**`with open('文件名','模式') as 新名字 `
```py
import os                                   #导入系统模块 使用自带的文件操作指令
os.rename('my_file.txt','your_file.txt')    #文件的重命名
os.remove('my_file.txt')                    #删除文件
os.mkdir('data')                            #创建文件夹 data
os.getcwd()                                 #获取当前的目录
os.chdir(‘../’)                             #改变路径

```

## 类class
> **定义类**
```py
class Students:
 total_count=100                 #类属性（类变量） 所有的实例都可以共享(不可以不写可以用pass避免报错)
 def __init__(self,age,name):    #初始化函数
    self.age=age                 #普通实例变量 用self关键字可以对实例变量进行赋值
    self.name=name
 def person_grade(self,grade):   #普通函数
    self.grade=grade
```
> **类的使用**
```py
s1=Students(20，‘xiaoming’)       #会自己调用类初始化函数对实例变量进行赋值
s2=Students(19，‘xiaoli’)
s1.person_grade(100)
print(Students.total_count)       #可以对类属性进行访问
print(s1.name,s2.age)
Students.total_count=50           #可以对类属性进行修改

```

> **类的继承**
```py
class Mammal:                     #定义一个父类
     def __init__(self,name,sex): #初始化类
         self.name=name
         self.sex=sex
         self.num_eyes=2
         
     def breath(self):
         print(self.name+'在呼吸')
        
     def poop(self):
         print(self.name+'在拉屎')
    
class Human(Mammal):              #定义一个子类可以继承父类 class 子类(父类)
     def read(self):
         print(self.name+'在阅读') #如果子类没有初始化函数就会调用父类的初始化函数获得self.name
         
class Cat(Mammal):  
     def scratch_sofa(self):
         print(self.name+'在抓沙发')#如果子类没有初始化函数就会调用父类的初始化函数获得self.name
     def poop(self):
         print(self.name+'在猫沙上拉屎')
         
cat1=Cat('jiujiu','男')            #子类没有初始化函数就会调用父类的初始化函数获得self.name =‘jiuiju’ 
cat1.poop()                        #如果子类没有poop函数(同名方法)就会调用父类的poop函数(同名方法)显示jiujiu在拉屎
                                   #这里cat类有poop函数显示jiujiu在猫沙上拉屎   
```
> ==super（） ：子类中调用父类的构造函数或其他方法（这样可以在定义子类属性的同时又拥有父类的属性）==
```py
class Human(Mammal):              #定义一个子类可以继承父类 class 子类(父类)
     def __init__(self,name,sex):
         super().__init__(name,sex) #调用父类的构造函数
         self.has_tail=False 
     def read(self):
         print(self.name+'在阅读')
         
class Cat(Mammal):  
     def __init__(self,name,sex):
         super().__init__(name,sex)
         self.has_tail=True
     def scratch_sofa(self):
         print(self.name+'在抓沙发')#如果子类没有初始化函数就会调用父类的初始化函数获得self.name
     def poop(self):
         print(self.name+'在猫沙上拉屎')     
```


## input

> input()  是一个内置函数，用于从用户获取输入 `variable = input(prompt)`==返回值是string==
```py
name = input("请输入你的名字：")   #显示请输入你的名字 随后输入内容会存储在name中
print("你的名字是"，  name)
```
```py
name = input("请输入你的名字：")
if name==str(1):                 #因为返回值是string所以进行判断时也是string或‘’
   print('yes')                  
elif name=='2':
   print('no')
else:
  print()
```
>if name==1:这是错的因为返回值不是整数  如果想用整数去进行判断就要进行类型转换
>==name=int(input('请输入你的名字：'))==
## 元组 tuple   列表list
> 都是用来存储一组数据的数据结构

> **元组（tuple）不可更改的容器**

1.  定义与表示：
    -   元组是用小括号 “()” 括起来的一组元素，元素之间用逗号分隔。`my_tuple = (1, 'apple',   3.14)`
2.  特点：
    -   ==不可变==：一旦创建，元组的元素就不能被修改、添加或删除。这使得元组在某些情况下更加安全，特别是当你不希望数据被意外修改时
    -   通常用于存储不同类型的数据集合，或者需要一组固定的数据时
   ```py
my_tuple=(1,2,'xiaoqing',3.14)
for content in my_tuple:
       print(content)                    #按顺序输出元组里的值
```

>   **列表（list）有序可更改的容器**

1.  定义与表示：
    -   列表是用方括号 “[]” 括起来的一组元素，元素之间也用逗号分隔。`my_list = [1, 'apple', 3.14]`
2.  特点：
    -   ==可变==：可以随时修改、添加或删除列表中的元素。这使得列表在需要动态修改数据的情况下非常有用 可以通过索引的方式去访问操作列表里的元素值
    -   提供了许多方便的方法来操作数据，==如`append()`添加元素、`insert()`插入元素、`remove()`删除元素、`sort()`排序等==
```py
my_list=[1,2,'xiaoqing',3.14]
for content in my_list:
    print(content)                      #按顺序输出列表里的值
```
```py
my_list[0]=3                            #可以通过索引去更改列表里的值
my_list[-1]=100                         #list[-1]表示列表里最后一个元素
print(my_list[0:3])                     #my_list[0:3]表示从第零位到第三位（只打印到第二位）
print(my_list[:3])                      #[:3]表示从最开始到第三位（也只打印到第二位）
                                        #[3:]从第三位到最后一位 [-3:-1]从倒数第三位到最后一位
for index in range(len(my_list)):       #range（len(my_list)）是以列表长度的整数序列值赋给index
                                        #然后执行循环去遍历列表 用my_list[index]去访问列表元素
   print('索引'，index，‘对应的值是’，my_list[index])
    
```
```py
my_list=[43,2,'xiaoqing',3.14]
my_list.append(0)                   #append会在列表的后面增添一个值
my_list.insert(1,'me')              #inser会在列表的第1个位置前插入字符串me变成 43 me 2 xiaoqing 3.14
my_list.remove(2)                   #remove会在列表里删除第一次出现的2这个值
print(my_list.index('xiaoqing'))    #会返回列表中第一次出现值xiaoqing的索引
print(my_list.count(3.14))          #会返回列表中值3.14出现的次数
print(my_list.sort())               #会从小到大重新排序列表中的元素
print(my_list.sort(reverse=true))   #会从大到小把列表里的元素排序
```

> **`sorted(对象名, key=None, reverse=False)`**
> **`key`**：可选参数，用于指定一个函数，从每个元素中提取比较的键（就是在元组或者列表时按照那个元素进行排序）
> **`reverse`**：默认从小到大
```py
pairs = [(1, 'one'), (2, 'two'), (3, 'three')]    #包含元组的列表
sorted_pairs = sorted(pairs, key=lambda x: x[1])  # 根据元组的第二个元素排序(如果是字符串就比较每个字母的顺序) lambda是定义简单函数的 x[1]就是元组的第二个元素
print(sorted_pairs)                               # 输出: [(1, 'one'), (3, 'three'), (2, 'two')]
```


## 多维列表

> 一般使用numpy的库去处理矩阵 import numpy

```py
multi_dim_list=[[1,2,3],           #定义一个多维列表
                [4,5,6],
                [7,8,9]]
print（multi_dim_list[0][1]）      #输出第零行第一列的元素值2
```
## 字典dictionary无序可更改的容器

> {‘键’：值}

> 1.  键(名字)的唯一性：字典中的键必须是唯一的。如果尝试使用相同的键多次，后面的值会覆盖前面的值
>2.  无序性：字典中的键值对没有特定的顺序 不能依赖于字典中元素的顺序去执行一些操作
>3.  可变：可以随时添加、修改或删除字典中的键值对
```py
my_dict = {'name': 'jiangxu', 'age': 22, 'city': 'Hang Zhou'} 
print(my_dict[name])            #字典支持以键名去访问值
my_dict['weight']=126.5         #可以添加键值对
print(my_dict.get('gender',unknown))#使用get（）去访问字典中不存在的键会返回unknown， 避免报错
del my_dict['weight']           #删除键对

for key in my_dict:             #遍历键
    print（key）
for key in my_dict.keys():
    print(key)
    
for value in my_dict.values(): #遍历值
    print(value)
    
for key,value in my_dict.items()：#遍历所有键值对
   print(key,value)  
```
## 导入模块

```py
import numy                     #导入numpy模块
import numpy as np              #如果模块名太长就可以给他导入并重命名
np.array()                      #把数据转化为ndarry

from numpy import numy，arry    #把所需要的功能导入就可以不用写成numpy.arry()这种形式了 这样方便别入阅读代码
arry()

from numpy import *             #表示把numpy里的所有功能都导入 也可以简化形式
arry（）
```

> 也可以导入自己的模块确保和当前文件在同一个目录下
```py
def sum (a,b):                  #自己实现某个功能的脚本 命名为me.py
    sum=a+b
    return sum
```
```py
import me                       #导入自己的模块
a=me.sum(2,3)                   #调用自己编写代码的功能
```
## continue break
```py
a=true                          #这是一个普通的改变判断值而终止循环的代码
while a:
    b=input('请输入答案')
    if b==str(100):             #只有输入100时才停止继续输入
       a=false
    else:
       pass
    print(b，‘ is error’)        #当输入100时还是会显示100 is error 因为下一次循环时才会判断循环条件
print('This is true')
```
```py
while true:
    b=input('请输入答案')
    if b==str(100):             
       break                     #直接跳出循环 循环体后面的内容都不执行
    else:
       pass
    print(b，‘ is error’)
print('This is true')
```
```py
while true:
    b=input('请输入答案')
    if b==str(100):             
       continue                  #直接跳过continue后面的内容 执行下一次循环
    else:
       pass
    print(b，‘ is error’)
print('This is true')
```
## try-else语句（处理错误信息）
> `try-else`在try块中放入可能引发异常的代码 如果没有发生异常则执行else中的代码
```py
try:
   file=open('my_file','r')       #以只读形式打开文件my_file
   except  *** as e:              #如果出现错误***就命名为e 并执行下面的代码
        file=open('my_file','w')  #创建一个名叫my_file的文件
else:
   pass                           #如果这个文件存在就不执行任何操作
   
```
## zip lambda map
> `zip()`可以把多个可迭代的元素（列表、元组等）打包成一个元组 他的返回是一个迭代器 可以用`list()`转换成列表显示

**返回是迭代器的意思是函数的返回时一个可以逐一访问的元素而不是元素的集合**（==所以要显示集合要 list（）==）

```py
a=[1,2,3]
b=[4,5,6]
print(list(zip(a,b)))                    #输出[(1,4),(2,5),(3,6)]
print(list(zip(a,a,b)))                  #输出[(1,1,4),(2,2,5),(3,3,6)]
```
> `lambda`用来定义简单的函数 正常用def来定义 `lambda 参数：函数体`
```py
add=lambda x,y:x+y
result=add(2,3) 


pairs = [(1, 'one'), (2, 'two'), (3, 'three')]     #定义一个包含元组的列表
sorted_pairs = sorted(pairs, key=lambda x: x[1])   #根据元组的第二个元素排序
print(sorted_pairs)                                #输出: [(1, 'one'), (3, 'three'), (2, 'two')]
```

> 1.`map()`用于将指定函数应用于可迭代对象（如列表、元组等）中的每个元素，并返回一个迭代器（查看结果用list（））
> 2.`map(function,对象)`函数应用于后面的元素
```py
list1 = [1, 2, 3]
list2 = [4, 5, 6]
sum=map(lambda x,y:x+y ,list1,list2) # 对应元素相加
result = list(sum)
print(result)                        # 输出: [5, 7, 9]
```
**只能遍历一次**：一旦迭代器被消耗（例如通过遍历），就不能再次使用，除非重新创建。
```py
list1 = [1, 2, 3]
list2 = [4, 5, 6]
sum=map(lambda x,y:x+y ,list1,list2) # 对应元素相加
result = list(sum)
print(result)                        # 输出: [5, 7, 9]
for i in sum:                        #sum是一个迭代器所以只能被遍历一次
    print(i)                         #再次遍历sum不会有输出
```
## shallow copy   & deepcopy
```py
a=[1,2,3]
b=a
print(id(a))                         #id()是index()
print(id(b))                         #会发现a和b的索引是一致的改变其一的某个元素另一个也会改变
```
```py
import copy
a=[1,2,3,[5,6]]
b=a
c=copy.copy(b)
print(id(a))                         
print(id(b)) 
print(id(c))                         #会发现c的索引和a b不一样 改变c中的某个元素a b 不会发生改变
print(id(c[3][0]))                   #会发现c的第四个元素的第一个数的索引和a的一致
print(id(a[3][0]))                   #这就是普通(shallow)复制的弊端
```
> 1.如果列表中的元素也是列表则又会发生存储的内存空间一致的情况——>使用deepcopy
> 2.`c=copy.deepcopy(a)`这样复制的新变量就会存储在一个新的存储空间
## threading 多线程
> 多个目标函数放入多个线程以提高计算速度

**添加线程**
```py
import threading

def thread_job():                       #定义线程功能函数
     print('hellow word')               
def main():
    added_thread=threading.Thread(target=thread_job,name='first') #创建线程added_thread(程序中管理线程的变量名) 线程名叫‘first’并放入功能thread_job
    added_thread.start()                #运行线程
    print(threading.active_count())     #查看已经激活的线程有几个
    print(threading.current_thread())   #查看当前运行的线程
    added_thread.join()                 #因为线程与程序是并行的想要等某个线程运行完用join()
    print()                             #只有当added_thread(first)这个线程运行完才会执行print
``` 
**time**
*在多线程程序中，可以使用 `time.sleep()` 让某个线程暂时挂起，从而允许其他线程有机会执*
```py
import threading
import time
time.sleep(1)                          #延时1s
```
**queue**
*在线程之间传递数据（线程不能自动返回值给主线程或其他线程）*
```py
import threading
from queue import Queue

def thread_job(q):                     #定义功能函数把结果放入队列 以供主线程读取
    result=100
    q.put(result)                      #把结果放入队列
    
q=queue.Queue()                        #创建一个队列并赋值给q
thread1=threading.Thread(target=thread_job,name='T1')  #创建线程放入要执行的函数并命名
thread1.start()                        #开始执行线程threa1
thread1.join()                         #等待线程thread1执行结束
result=q.get()                         #从队列中获取结果
```
## pickle存放数据
> `pickle`是Python的一个模块，用于序列化和反序列化Python对象。序列化是将对象转换为字节流的过程，以便存储或传输；反序列化则是将字节流恢复为原始对象。

 - **模型保存与加载：**   把训练好的模型权重和结构序列化，可以在训练后将模型保存为`.pkl`之后通过`pickle.load()`加载模型
 - **数据集存储：**  把数据集（训练数据、标签等）序列化，便于快速加载和使用（处理大规模数据时）
```py
import pickle
import tensorflow as tf
#假设一个模型
model=tf.keras.Sequential([...])                #定义模型
model.fit(x_train,y_train)                      #训练模型
#保存模型
with open('model.pkl','wb') as f:               #wb 以二进制模式创建一个文件 并命名为f
     pickle.dump(model,f)                       #把深度学习模型（对象）写入到（打开的）文件中
#加载模块
with open('model.pkl','rb') as f:               #rb 以二进制模式读一个文件 并命名为f
     loaded_model=pickle.load(f)                #加载
```
## set

***用来存储唯一的数据（重复会自动删除） 与数学中的集合类似可以实现并集 交集 差集 对称差集***
```py
list=[1,1,2]
print(set(list))                                #输出{1,2}
set1={1,2,3}
set2={2,3,4}
union=set1|set2                                 #并集 {1,2,3,4}
intersection=set1&set2                          #交集 {2,3} 
difference=set1-set2                            #差集 {1}
difference2=set1^set2                           #对称差集{1，4}
```

> 1.去重数据  构建数据集时存储在set中以确保标签的唯一
```py
lables=['cat','dog','bird','cat']
unique_lables=set(lables)                       #{'cat','dog','bird'}
```
> 2.模型评估时用set计算交集和并集 例如计算准确率等

```py
true_postive=len(true_lables&predicted_lables)  #交集操作 len()返回交集元素的个数
```

##  **深度学习-数据模块**

>==打开图片并转换成灰度图==`img=Image.open(img_path).convert('L')`
```py
**当模型是3通道而输入灰度图时 对输入数据经行转化**
#定义转换
transform = transforms.Compose([  
    transforms.Resize((256, 256)),  # 调整图像大小  
    transforms.Grayscale(num_output_channels=3),  # 转换为三通道  
    transforms.ToTensor()  # 转换为张量  
])  
  
# 加载数据集
train_dataset = ImageFolder(root='data', transform=transform)  
train_loader = DataLoader(dataset=train_dataset, batch_size=32, shuffle=True)
```
```py
 class COVID19Dataset(Dataset):   #定义一个继承torch.utils.data.Dataset的数据集类
            """
            获取数据集的根目录、标签路径、预处理的方法
            """
        def __init__(self, root_dir, txt_path, transform=None):
            self.root_dir = root_dir
            self.txt_path = txt_path
            self.transform = transform                 #数据增强
            self.img_info = []                         #初始化一个空列表，存储图片路径和标签
            self.label_array = None                    #初始化一个标签数组
            self._get_img_info()                       #调用类方法 读取图片路径和标签信息

            """
            输入标量index, 从硬盘中读取数据，并预处理，to Tensor
            """
        def __getitem__(self, index):                  #定义一个获取数据集元素的方法
            path_img, label = self.img_info[index]     #根据索引获取图片路径和标签
            img = Image.open(path_img).convert('L')    #打开图片并转化为灰度图片

            if self.transform is not None:             #如果有数据处理的方法就进行数据处理
                img = self.transform(img)

            return img, label                          #返回预处理的图片和标签

        def __len__(self):                             #定义获取数据集长度的方法
            if len(self.img_info) == 0:
               raise Exception('检查文件路径')           #如果图片信息列表为空，抛出异常并提示错误信息
            return len(self.img_info)
            
            """
            实现数据集的读取，将硬盘中的数据路径，标签读取进来，存在一个list中，供__getitem__函数使用
            """
        def _get_img_info(self):
            with open(self.txt_path, "r") as f:         #读取txt，解析txt
                txt_data = f.read().strip()             #读取文件内容并去除首尾空白字符。
                txt_data = txt_data.split("\n")         #按行分割文件内容
            self.img_info = [(os.path.join(self.root_dir, i.split()[0]), int(i.split()[2]))
                             for i in txt_data]         #解析每行数据 把图片路径和标签组合起来存入
```

```py
import os                                #系统库文件操作
import cv2                               
import numpy as np  
import torch    
from utils import *  
from torch.utils.data import Dataset  
from utils import *  
from torchvision import transforms  
from heatmap_label import *  
transform=transforms.Compose([  
    transforms.ToTensor()  
])  
  
'''  
（导入）代码以确保单通道的灰度图能够在三通道的网络上运行  
'''  
from torchvision.datasets import ImageFolder  
from torch.utils.data import DataLoader  
from PIL import Image  
  
class MyDataset(Dataset):  
    def __init__(self,path):  
        self.path=path  
        f=open(path)  
        self.dataset=f.readlines()  
  
    def __len__(self):  
        return len(self.dataset)  
  
    def __getitem__(self, index):  
        data=self.dataset[index]  
        img_path=data.split(' ')[0]  #以空格符把数据集（字符串）分隔成多个部分 取第一个部分[0]为文件路径
        image=Image.open(img_path).resize((256,256)) #使用Image.open打开这个图像路径对应的图像，并将图像大小调整为(256, 256)`
        
        points=data.split(' ')[1:-2]  再次以空格分割数据样本字符串，取除了第一个元素和最后两个元素之外的部分作为坐标点信息，存储在`points`列表中
        
        points=[float(i.rstrip("\n"))*0.5 for i in points]  #遍历points列表中的每个元素，去除元素末尾的换行符，将其转换为浮点数，并乘以 0.5(图像缩小一半对应标签点坐标也要缩小一半)，更新points列表
        label=[]          #初始化一个空列表用于存储热图标签
        for i in range(0,len(points),2):  #遍历points列表，每次取两个元素作为一个坐标点对
            heatmap=CenterLabelHeatMap(256,256,points[i],points[i+1],5) #每个坐标点对(points[i], points[i+1])为中心的二维热图大小由输入的图像宽度和图像高度决定，半径sigma
            label.append(heatmap) #生成的热图添加到label列表中 （一次只能生成一个点）
        label=np.stack(label)     #把画出的点的张量都拼接起来（6个点）
        return transform(image),torch.Tensor(label)
       
        # 定义转换(后加)  
transform = transforms.Compose([  
    transforms.Resize((256, 256)),  # 调整图像大小  
    transforms.Grayscale(num_output_channels=3),  # 转换为三通道  
    transforms.ToTensor()  # 转换为张量  
])  
  
# 加载数据集(后加)  
train_dataset = ImageFolder(root='data', transform=transform)  
train_loader = DataLoader(dataset=train_dataset, batch_size=32, shuffle=True)  
  
  
if __name__ == '__main__':  
    data=MyDataset('TG_1.txt')  
    print(data[5][0].shape)  
    print(data[5][1].shape)  
    for i in data:  
        print(i[1].shape)  #看一下得到的图像的形状 空间尺寸 维度（一个点一个维度）
```

 
# train模块

```py
import os                                    #系统模块用于文件操作
  
from torch import nn,optim                   #导入经典网络 优化函数
import torch                                 #导入torch其他库
from torch.utils.data import DataLoader      #从utils工具库导入数据加载器
from data import *                           #从自己写的data中导入class Dataset(DataLoader)类
from net import *                            #从net中导入Unet的定义
from torchvision.utils import save_image     #从utils工具库导入save_image保存图像 
  
device=torch.device('cuda' if torch.cuda.is_available() else 'cpu')  #如果cuda可用就cuda否则就cpu
weight_path='params/unet.pth'                #定义权重文件路径  
data_path=r'TG_1.txt'                        #定义数据(标签)的路径(这里没有打开路径写不写r无所谓) 
                                             #"C:\Users\Documents\file.txt"这么写是错的因为要 /
                                             # r"C:\Users\Documents\file.txt"这么表试文件路径
save_path='train_image'                      #定义图片保存路径

if __name__ == '__main__':                   #主函数
    data_loader=DataLoader(MyDataset(data_path),batch_size=2,shuffle=True)  
                                             #使用自定义的Dataset类加载数据DataLoader类批量处理数据
                                             #分批 打乱顺序加载数据
    net=UNet().to(device)                    #初始化UNet网络并指定到设备device(cuda cpu)
    
    if os.path.exists(weight_path):          #检查是否存在预训练权重
        net.load_state_dict(torch.load(weight_path)) #net是个实例如 net = MyModel() torch.load(weight_path)是一个函数负责从磁盘中加载权重文件`.pth  .pt`
        print('successful load weight！')   
    else:  
        print('not successful load weight')  
  
    opt=optim.Adam(net.parameters())         #定义优化器使用Adam优化算法
    loss_fun=nn.BCELoss()                    #定义损失函数使用二进制交叉熵损失
  
    epoch=1                                  #经行一次前向传播和反向传播
    while True:                              #无限循环训练会一直进行只到手动停止
        for i,(image,segment_image) in enumerate(data_loader):  #遍历数据加载器获得批量图像和分割图像
            image, segment_image=image.to(device),segment_image.to(device)  #把两种图像交给设备
  
            out_image=net(image)             #把输入图像给网络得到输出图像
            train_loss=loss_fun(out_image,segment_image)#计算损失  
  
            opt.zero_grad()                  #清除优化器的梯度 循环执行之前的梯度会累计的下一次反向清除
            train_loss.backward()            #根据损失函数的值计算模型参数的梯度为后续参数更新做好准备
            opt.step()                       #更新参数
  
            if i%5==0:                       #每五个批次打印一次损失
                print(f'{epoch}-{i}-train_loss===>>{train_loss.item()}')  
                                             #train_loss()是张量tensor(0.004)
                                             #train_loss.item()是浮点数0.004 item是把标量 张量转成float int
  
            if i%1==0:                       #每个批次保存一次图像 
                _image=image[0]              #取第一个图像
                _segment_image=segment_image[0]  #取第一个分割图像
                _out_image=out_image[0]      #取第一个输出图像
                img=torch.stack([_segment_image[0],_segment_image[1],_segment_image[2],_segment_image[3],_segment_image[4],_out_image[0],_out_image[1],_out_image[2],_out_image[3],_out_image[4]],dim=0)  
                                             #把上面的图像堆叠在一起
                img=torch.unsqueeze(img,dim=1)   #增加一个维度
                save_image(img,f'{save_path}/{i}.png',nrow=5)  #保存图像 包含索引
        if epoch%5==0:  
            torch.save(net.state_dict(),weight_path)  #每五次保存一次模型权重
            print('保存成功')  
        epoch+=1
```
## DataLoader
> **DataLoader**是一个类把数据集包装成一个可迭代的对象 可以进行按批量（batch）加载数据 以及打乱顺序（shuffle）加载
> **作用**：`DataLoader`负责将数据集拆分多个小批次，在训练模型时逐批送入神经网络进行训练。



## `stack cat` 拼接函数

> **`stack `** 沿着一个新的维度对输入张量序列进行拼接 拼接的序列张量形状必须相同 dim的值不能超过原有的维度
```py
a1=[5,9]
a2=[3,6]
torch.stack([a1,a2],dim=0)       '''[5，9] 原本是一个0维张量给他增加了一个维度（列）在这个维度上进行拼接
                                    [3, 6]'''
```
> `cat`会把张量序列在已有维度上拼接 形状也必须相同
```py
a1=[5,9]
a2=[3,6]
torch.cat([a1,a2],dim=0)       '''[5,9,3,6] 会在原有的维度上进行拼接'''
```
## unsqueeze
> `torch.unsqueeze(input,dim)`input输入张量 dim要插入维度的位置
```py
import torch
a=torch.tensor([1,2,3])
b=torch.unsqueeze(a,dim=0)
print(a)
print(b)
print(b.shape)
'''输出
[1,2,3]
[[1,2,3]]
[1,3]  在0维插入一个维度（列）变成了一行三列
'''
```
```py
import torch
a=torch.tensor([1,2,3])
b=torch.unsqueeze(a,dim=1)
print(a)
print(b)
print(b.shape)
'''输出
[1,2,3]

[[1],
[2],
[3]]

[3,1]  在1维插入一个维度（行）变成了一行三列
'''
```
