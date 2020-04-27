#include<stdio.h>
#include<unistd.h>

void Swap(int* a,int* b)
{
  int temp = *a;
  *a = *b;
  *b =temp;
}

void InsertSort(int arr[],int len)
{
  //直接插入排序
  for(int i =1; i< len;i++)
  {
    int key = arr[i];
    int index = i -1;
    while(index>=0&&arr[index]>key)
    {
      arr[index +1]=arr[index];
      --index;
    }
    arr[index+1]=key;
  }
}

//左右指针法
int PartSort1(int arr[],int left,int right)
{
  //右边为基准值，左边先走；；防止越界
  int key = arr[right];//基准值
  int key_index = right;
  while(left < right)
  {
    while(left <right && arr[left]<=key)
    {
      ++left;
    }

    while(left < right && arr[right]>=key)
    {
      --right;
    }
    Swap(&arr[left],&arr[right]);
  }
  Swap(&arr[left],&arr[key_index]);
  return left;
}

//前后指针法
int PartSort3(int arr[],int left,int right)
{
  int cur = left;
  int prev = left-1;
  int key = arr[right];

  while(cur<right)
  {
    if(arr[cur]<key && ++prev!=cur)
    {
      //此时prev可定指向大于key的一个值，此时prev和cur之间的值都是大于key的
      Swap(&arr[cur],&arr[prev]);
    }
    ++cur;
  }
  ++prev;
  Swap(&arr[prev],&arr[right]);
  return  prev;
}



//挖坑法
int PartSort2(int arr[],int left,int right)
{
  int key =arr[right];//基准值
  while(left< right)
  {
    while(left<right && arr[left<=key])
    {
      ++left;
    }
    arr[right] = arr[left];
    while(left < right && arr[right]>=key)
    {
      --right;
    }
    arr[left] = arr[right];
  }
  arr[left] = key;
  return left;
}
void QuickSort(int arr[],int left,int right)
{
   if(left >= right)
     return;
   if((right-left+1)>10)
   {
   //int key_index = PartSort1(arr,left,right);
   //int key_index = PartSort3(arr,left,right);
   int key_index = PartSort2(arr,left,right);
   QuickSort(arr,left,key_index-1);
   QuickSort(arr,key_index+1,right);
    }
   else
   {
     //优化直接插入排序
     InsertSort(arr,(right-left)+1);
   }
}
int main()
{
  int arr[] = {1,5,4,8,9,5,6,7,2,3};
  int len = sizeof(arr)/sizeof(arr[0]);
  QuickSort(arr,0,len-1);
  for(int i = 0; i<len;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
