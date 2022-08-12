#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;

void taskA()
{
    for(int i=1;i<=10;i++)
    {
        sleep(1);
        printf("TaskA : %d\n",i);
        fflush(stdout);  // used to clear the buffer and to move the buffered data to console(stdout) or disk(file output stream)
    }
}

void taskB()
{
    for(int i=1;i<=10;i++)
    {
        sleep(1);
        printf("TaskB : %d\n",i);
        fflush(stdout);
    }
}

int main()
{
    thread t1(taskA);
    thread t2(taskB);


    //Without these join functions the main thread will exit and both the threads t1 and t2 will unexpectedly abort 
    t1.join();
    t2.join();
    return 0;
}