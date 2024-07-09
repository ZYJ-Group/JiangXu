/*每次从待排序序列中，找出最小/最大一个数，和待排序序列中的第一个元素交换*/
#include <iostream>
using namespace std;

int main()
{
    int arr[]={23,90,5,31,7};
    int len=sizeof(arr)/sizeof(arr[0]);
    int i,j,temp;
    //定义一个变量，保存最小值的下标
    int index=0;
    
    //外层循环控制排序次数
    for(i=1;i<len;i++)
    {
        //每次让假定的最小值是待排序中的第一个数
        //保证每一次进入内层循环时，index是新的值
        index=i-1;
        //内层循环找剩余序列的最小值
        for(j=i-1;j<len;j++)
        {
            //选择排序，找下标
            if(arr[index]>arr[j])
            {
                //更新最小值的下标
                index = j;
            }
        }

        //找到最小值，跟第一个元素交换
        if(index!=i-1)
        {
            
            temp = arr[index];
            arr[index] = arr[i-1];
            arr[i-1] = temp;
        }
    }

    for(i=0;i<len;i++)
    {
     cout<<arr[i]<<endl;
    }
    return 0;
}