#include<stdio.h>


void Swap(int* a,int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
//直接选择排序
void SelectSort(int arr[],int len)
{
  //情况一：一次性选择一个最大的或者是最小的，放在序列的开始或末尾
  for(int i = 0; i<len-1;i++)
  {
    int maxpos = i;
    for(int j = i + 1;j<len;j++)
    {
      if(arr[j]>arr[maxpos])
        maxpos = j;
    }
  Swap(&arr[i],&arr[maxpos]);
  } 
}

void SelectSortOP(int arr[],int len)
{
  //情况二：一次性选择两个，提高效率
  int begin = 0;
  int end = len -1;
  while(begin <= end)
  {
    int maxpos = begin;
    int minpos = begin;

    for(int i = begin; i <= end ; i++)
    {
      if(arr[i]>arr[maxpos])
        maxpos = i;
      if(arr[i]<arr[minpos])
        minpos = i;
    }
    Swap(&arr[begin],&arr[minpos]);
    if(maxpos == begin)
      maxpos = minpos;
    Swap(&arr[end],&arr[maxpos]);
    begin++;
    end--;
  }
}
int main()
{
  int arr[] = {7,9,8,1,2,5,6,4,3};
  int len = sizeof(arr)/sizeof(arr[0]);
  //SelectSort(arr,len);
  SelectSortOP(arr,len);
  for(int i = 0; i < len;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
