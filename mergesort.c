#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//归并排序--时间复杂度O(NlgN)
//空间复杂度O(N)
//稳定性：不稳定
void _MergeSort(int arr[],int left,int right,int* tmp)
{
  //先分解，在合并
  
  if(left == right)
    return ;

  int mid = (right-left)/2 + left;
  _MergeSort(arr,left,mid,tmp);
  _MergeSort(arr,mid+1,right,tmp);

  
  //开始合并
  int begin1 = left,end1 = mid;
  int begin2 = mid+1,end2 = right;
  int i = left;

  while(begin1<=end1 && begin2<=end2)
  {
    if(arr[begin1]<arr[begin2])
    {
      tmp[i++]=arr[begin1++];
    }
    else
    {
      tmp[i++]=arr[begin2++];
    }

  }

  while(begin1<=end1)
  {
    tmp[i++]=arr[begin1++];
  }

  while(begin2<=end2)
  {
    tmp[i++]=arr[begin2++];
  }

  memcpy(arr+left,tmp+left,sizeof(int)*(i-left));
}


void MergeSort(int* arr,size_t len)
{
  int* tmp = (int*)malloc(sizeof(int)*len);
  _MergeSort(arr,0,len-1,tmp);
  free(tmp);
}


int main()
{
  int arr[]={1,3,5,7,2,8,4,6,9};
  MergeSort(arr,sizeof(arr)/sizeof(arr[0]));
  for(int i = 0; i<9;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
