#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int CountSort(int arr[],int len)
{
  //1,第一步计算范围,确定开辟数据大小
  int max = arr[0],min = arr[0];
  for(int i = 0; i < len ;i++)
  {
    if(arr[i]>max)
      max = arr[i];
    if(arr[i]<min)
      min = arr[i];
  }

  //开辟数组，开始计数
  int range = max - min + 1;
  int* tmp = (int*)malloc(sizeof(int)*range);
  memset(tmp,0,sizeof(int)*range);

  for(int i = 0; i<len;i++)
  {
    tmp[arr[i]-min]+=1;
  }

  //开始对元素进行回收排序
  int j = 0;
  for(int i = 0; i<len;i++)
  {
    while(tmp[i]--)
    {
      arr[j++]=i+min;
    }
  }

  free(tmp);
  tmp = NULL;
}

int main()
{
  int arr[]={1,4,3,6,9,7,8,2,5};
  CountSort(arr,9);
  for(int i = 0; i < 9;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
