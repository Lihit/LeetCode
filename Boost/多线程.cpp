//
// Created by wenshao on 18-3-30.
//
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include <mutex>

using namespace std;
int totalNum = 1000000000;
mutex mu;

void thread01(){
    for (int i = 0; i < 10; ++i) {
        cout << "Thread 01 is working ！" << endl;
        sleep(2);
    }
}
void thread02()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 02 is working ！" << endl;
        sleep(2);
    }
}
int main11(){

    thread task01(thread01);
    thread task02(thread02);
    task01.join();
    task02.join();

    for (int i = 0; i < 5; i++)
    {
        cout << "Main thread is working ！" << endl;
        sleep(2);
    }
    return 0;
}
/*
 * 两个子线程并行执行，join函数会阻塞主流程，所以子线程都执行完成之后才继续执行主线程。可以使用detach将子线程从主流程中分离，独立运行，不会阻塞主线程
 *
 */

int main22(){
    thread task01(thread01);
    thread task02(thread02);
    task01.detach();
    task02.detach();

    for (int i = 0; i < 5; i++)
    {
        cout << "Main thread is working ！" << endl;
        sleep(200);
    }
    system("pause");
    return 0;
}

//带参子线程
void thread03(int num1, int num2){
    for (int i = 0; i < 10; ++i) {
        cout << "Thread 01 is working ！" << num1<<num2<<endl;
        sleep(2);
    }
}
void thread04(int num1, int num2)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 02 is working ！" << num1<<num2<<endl;
        sleep(2);
    }
}
int main33(){
    thread task01(thread03, 5,2);  //带参数子线程
    thread task02(thread04, 4,5);
    task01.detach();
    task02.detach();

    for (int i = 0; i < 5; i++)
    {
        cout << "Main thread is working ！" << endl;
        sleep(200);
    }
    return 0;
}
//多个线程同时对同一变量进行操作的时候，如果不对变量做一些保护处理，有可能导致处理结果异常


void thread05()
{
    cout<<"thread05"<<endl;
    while (totalNum > 0)
    {
        mu.lock();
        cout << totalNum << endl;
        totalNum--;
        //sleep(1);
        mu.unlock();
    }
}
void thread06()
{
    cout<<"thread06"<<endl;
    while (totalNum > 0)
    {
        mu.lock();
        cout << totalNum << endl;
        totalNum--;
        //sleep(1);
        mu.unlock();
    }
}

/*
 * 有两个问题，一是有很多变量被重复输出了，而有的变量没有被输出；
 * 二是正常情况下每个线程输出的数据后应该紧跟一个换行符，但这里大部分却是另一个线程的输出。
 * 这是由于第一个线程对变量操作的过程中，第二个线程也对同一个变量进行各操作，
 * 导致第一个线程处理完后的输出有可能是线程二操作的结果。针对这种数据竞争的情况，
 * 可以使用线程互斥对象mutex保持数据同步。mutex类的使用需要包含头文件mutex：
 */
int main()
{
    thread task01(thread05);
    thread task02(thread06);
    task01.detach();
    task02.detach();
    return 0;
}
