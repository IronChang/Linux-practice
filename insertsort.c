//插入排序：直接插入排序或者是shell排序
//filename:insertsort
//author:TC

#include<stdio.h>

//时间最差O(N^2)  最好O(N)   
//空间O(1) 没有使用额外的空间
//稳定性：稳定的
//使用场景：数据量小，且接近有序的情况下直接插入排序效果还是OK的
void InsertSort(int arr[],int len)
{
  for(int i=1;i<len;i++)
  {
    int key = arr[i];
    int index = i-1;
    while(index >= 0 && arr[index]>key)
    {
      arr[index+1] = arr[index];
      index--;
    }
    arr[index+1] =key;
  }
}

//时间最差O(N^1.3~N^2)
//空间O(1) 没有使用额外的空间
//稳定性：不稳定
//使用场景：数据量大且较复杂
void ShellSort(int arr[],int len)
{
  //思路:利用增量gap进行预排序,gap大于1时，相当于预排序，当gap=1是就行当与直接插入排序
  int gap =len;
  while(gap > 1)
  {
  gap = gap/3+1;
  for(int i=0;i<len;i++)
  {
    int key = arr[i];
    int index = i-gap;
    while(index >= 0 && arr[index]>key)
    {
      arr[index+gap] = arr[index];
      index-=gap;
    }
    arr[index+gap] =key;
  }
 }
}
int main()
{
  int arr[] =  {3,6,9,7,8,2,1,4,5};
  int len = sizeof(arr)/sizeof(arr[0]);
 // InsertSort(arr,len);
    ShellSort(arr,len);
  for(int i = 0 ; i < len ;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
