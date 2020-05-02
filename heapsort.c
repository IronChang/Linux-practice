//二叉堆这种数据结构一般的使用场景：
//1、TOP k  问题
//2、优先级队列
//3、利用堆求中位数
//4、堆排序---排升序，建小堆，排降序，建大堆
#include<stdio.h>
#include<stdlib.h>


void Swap(int* a,int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;

}

void AdjustDown(int* arr,int len,int parent)
{
  //建小堆
  //left child = parent * 2 + 1;
  //right child = parent * 2 + 2;
  //小堆的特点：根节点值小于左右孩子的值
  //1、先找左右孩子中最小的哪一个
  int child = parent*2+1;
  
  //2、开始向下调整
  while(child<len)
  {
  if(child+1<len && arr[child+1] < arr[child])
  {
    child++;
  }
    if(arr[parent]>arr[child])
    {
      Swap(&arr[child],&arr[parent]);
      parent = child;
      child = parent *2+1;
    }
    else
    {
      break;
    }
  }

}
void Heapsort(int* arr,int len)
{
  //parent = child -1/2;
  //建堆
  for(int i = (len-2)/2;i>=0;i--)
  {
    AdjustDown(arr,len,i);
  }

  //进行排序
  int end = len -1;
  while(end>0)
  {
    Swap(&arr[0],&arr[end]);
    AdjustDown(arr,end,0);
    --end;
  }
}
int main()
{
  int arr[]={1,4,3,5,2,7,9,6,8};
  Heapsort(arr,sizeof(arr)/sizeof(arr[0]));
  for(int i = 0; i < 9;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
