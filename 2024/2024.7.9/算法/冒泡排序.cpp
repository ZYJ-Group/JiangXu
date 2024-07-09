/*相邻数据两两比较，比较出大小关系后，再进行交换
第一个元素和第二个元素比较，如果第一个元素更大，交换顺序；
第二个元素和第三个元素比较，如果第二个元素更大，交换*/
#include <iostream>
using namespace std;
int main()
{
    int arr[]={10,89,79,5};
    int len=sizeof(arr)/sizeof(arr[0]);//数组的长度 int len=sizeof(arr)/sizeof(int);
    int i,j;//中间变量
    int temp;//外层循环控制排序的趟数
    
    for(i=1;i<len;i++)
    {
        //内层循环控制比较次数
        //j<len-i 为了防止数组越界
        for(j=0;j<len-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //遍历数组测试排序是否成功
    for(i=0;i<len;i++)
    {
     cout<<"arr[i]="<<arr[i]<<endl;
    }
    return 0;
}