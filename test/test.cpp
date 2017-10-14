#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h>  
  
void* task1(void*);  
void* task2(void*);  
void usr();  
int p1,p2;  
  
int main()  
{  
    usr();  
    getchar();  
    return 1;  
}  
  

void usr()  
{  
    pthread_t pid1, pid2;  
    pthread_attr_t attr;  
    void *p;  
    int ret=0;  
    pthread_attr_init(&attr);         //初始化线程属性结构  
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);   //设置attr结构为分离  
    pthread_create(&pid1, &attr, task1, NULL);         //创建线程，返回线程号给pid1,线程属性设置为attr的属性，线程函数入口为task1，参数为NULL  
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);  
    pthread_create(&pid2, &attr, task2, NULL);  
//前台工作  
  
    ret=pthread_join(pid2, &p);         //等待pid2返回，返回值赋给p  
    printf("after pthread2:ret=%d,p=%d\n", ret,(int)p);            
  
}  
  
void* task1(void *arg1)  
{  
    printf("task1\n");  
//艰苦而无法预料的工作，设置为分离线程，任其自生自灭  
    pthread_exit( (void *)1);  
  
}  
  
void* task2(void *arg2)  
{  
    int i=0;  
    printf("thread2 begin.\n");  
    //继续送外卖的工作  
    pthread_exit((void *)2);  
}  