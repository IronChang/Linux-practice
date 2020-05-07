#include<iostream>
#include<queue>
#include<stdio.h>
#include<pthread.h>

#define MAX_CAPA 10
class Queue
{
  public:
    Queue(int num=MAX_CAPA):capacity(num)
  {
    pthread_cond_init(&cond_customer,NULL);
    pthread_cond_init(&cond_productor,NULL);
    pthread_mutex_init(&mutex,NULL);
  }
    ~Queue()
    {
      pthread_cond_destroy(&cond_customer);
      pthread_cond_destroy(&cond_productor);
      pthread_mutex_destroy(&mutex);
    }

    bool QueuePush(int &data)
    {
      pthread_mutex_lock(&mutex);
      while(_queue.size()==capacity)
      {
        pthread_cond_wait(&cond_productor,&mutex);
      }
      _queue.push(data);
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&cond_customer);
  return true;
    }

    bool QueuePop(int &data)
    {
      pthread_mutex_lock(&mutex);
      while(_queue.empty())
      {
        pthread_cond_wait(&cond_customer,&mutex);
      }
      data = _queue.front();
      _queue.pop();
      pthread_mutex_unlock(&mutex);
      __gthrw_pthread_cond_signal(&cond_productor);
      return true;
    }
private:
  std::queue<int>_queue;
  size_t capacity;
  pthread_cond_t cond_customer;
  pthread_cond_t cond_productor;
  pthread_mutex_t mutex;
};


void* customer(void* arg)
{
  Queue* queue = (Queue*)arg;
  while(1)
  {
    int data;
    queue->QueuePop(data);
    printf("get a data:%d\n",data);

  }
  return NULL;
}
void* productor(void* arg)
{
  int i = 0;
  Queue* queue = (Queue*)arg;
  while(1)
  {
    queue->QueuePush(i);
    printf("put a data:%d\n",i++);
  }
  return NULL;
}

#define MAX_THR 4
int main()
{
  Queue queue;
  pthread_t customer_tid[MAX_THR];
  pthread_t productor_tid[MAX_THR];
  for(int i = 0; i < MAX_THR; i++)
  {
    int ret = pthread_create(&customer_tid[i],NULL,customer,(void*)&queue);
    if(ret != 0)
    {
      std::cerr<<"pthread_create errori\n";
      return -1;
    }
  }
  for(int i = 0; i < MAX_THR; i++)
  {
    int ret = pthread_create(&productor_tid[i],NULL,productor,(void*)&queue);
    if(ret != 0)
    {
      std::cerr<<"pthread_create errori\n";
      return -1;
    }
  }


  for(int i = 0 ; i < MAX_THR ; i++)
  {
    pthread_join(customer_tid[i],NULL);
    pthread_join(productor_tid[i],NULL);
  }
  return 0;
}

