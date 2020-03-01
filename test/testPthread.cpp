#include <iostream>
#include <utility>
#include <thread>
#include <chrono>       // 时钟和计时器库
#include <functional>
#include <atomic>       // 原子操作,类似互锁
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <mutex>

std::mutex iomutex;
using namespace std;

#define NUM_TREADS 5

void f1(int n){
    for(int i=0;i<5;++i){
        std::cout<< "Thread" << n << "executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}

void f2(int& n){
    for(int i=0;i<5;++i){
        std::cout<< "Thread" << n << "executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void thread_task(int n){
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout<< "hello tread" 
            << std::this_thread::get_id()           //获取线程的id
            << "\npause" << n << "seconds" << std::endl;
}

void foo(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void independentThread(){
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}

void threadCaller(){
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<< "Exiting thread caller.\n";
}

void bar(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void f(int num){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sched_param sch;
    int policy;
    pthread_getschedparam(pthread_self(),&policy,&sch);
    std::lock_guard<std::mutex> lk(iomutex);
    std::cout << "Thread " << num << "is executing at priority"
            << sch.__sched_priority << '\n';
}

void *printHello(void *threadid){
    // 对传入的参数进行强制类型转换,由无类型指针变为整形指针再读取
    int tid = *((int*)threadid);
    cout << "hello world! 线程 ID," << tid << endl;
    pthread_exit(NULL);
}

typedef struct{
    int threadid;
    char* message;
}thread_data;

void *printHello2(void *threadarg){
    thread_data *my_data;
    my_data = (thread_data*)threadarg;
    cout << "线程Id:" << my_data->threadid;
    cout << my_data->message << endl;
    pthread_exit(NULL);
}

void *wait(void *t){
    int i;
    long tid;
    tid = (long)t;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Sleeping in thread" << endl;
    cout << "Thread with id:" << tid << "  ...exiting" << endl;
    pthread_exit(NULL);
}

int main(){
    



    /**************************************************************************************
     * [1] 子线程的创建和赋值
    int n=0;
    std::thread t1; //t1 is not a thread
    std::thread t2(f1,n+1); //pass by value
    std::thread t3(f2,std::ref(n)); // pass by reference,如果要给子线程函数传递引用的参数,则需要使用std::ref(attri)
    std::thread t4(std::move(t3));  //t4 is now running f2().t3 is no longer a thread,使用move进行赋值
    // join()是阻塞线程,主线程在这里等待t2线程结束后再运行下一句,如果不加这个,且t2的属性是detech的
    // 则主线程可先行退出子线程被挪到后台继续运行
    // 判断一个线程能否join使用t2.joinable()方法
    t2.join();
    t4.join();
    std::cout << "Final value of n is:" << n << "\n";
    ***************************************************************************************/
   
   /********************************************************************
   // [2] 多个子线程的创建
   std::thread threads[5];
   std::cout << "Spawning 5 threads...\n";
   for(int i=0;i<5;i++){
       threads[i] = std::thread(thread_task,i+1);
   }
   std::cout << "Done spawning threads!Now wait for them to join\n";
   for(auto& t: threads){
       t.join();
   }
   std::cout << "All threvoads joined.\n";
   return EXIT_SUCCESS;
   ********************************************************************/

  /******************************************************************
  std::thread t;                    // 默认构造函数不能join
  std::cout << "before starting, joinable:" << t.joinable() << '\n';

  t = std::thread(foo);             // 现在可以join了
  std::cout << "after starting, joinable:" << t.joinable() << '\n';
  t.join();
  ******************************************************************/

    /*********************************************************************
     // [3] detach 线程,将当前线程对象所代表的执行实例与该线程对象分离,使得该线程可以单独
    // 执行,调用.detach函数后,*this不再代表任何线程执行实例

    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));   
    **********************************************************************/

    /*******************************************************************
    // [4] 交换线程底层句柄 swap
    std::thread t1(foo);
    std::thread t2(bar);

    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    std::swap(t1,t2);

    std::cout << "after swap(t1,t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.swap(t2);

    std::cout << "after t1.swap(t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.join();
    t2.join();
    *********************************************************/

   /*******************************************************************************
   // [5]  设置优先级
    std::thread t1(f,1),t2(f,2);
    sched_param sch;
    int policy;
    pthread_getschedparam(t1.native_handle(),&policy,&sch);
    sch.__sched_priority = 20;
    if(pthread_setschedparam(t1.native_handle(),SCHED_FIFO,&sch)){
        std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
    }
    t1.join();
    t2.join();

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << "concurrent threads are supported.\n";
    *******************************************************************************/

   // [6] 向线程传递单个参数
//    pthread_t threads[NUM_TREADS];
//    int indexs[NUM_TREADS];
//    int rc;
//    int i;
//    for(i = 0;i<NUM_TREADS;i++){
//        cout << "main():创建线程 ," << i << endl;
//        indexs[i] = i;
//        rc = pthread_create(&threads[i],NULL,printHello,(void*)&(indexs[i]));
//        if(rc){
//            cout << "Error:无法创建线程," << rc << endl;
//            exit(-1);
//        }
//    }
//    pthread_exit(NULL);

    // // [7] 向线程传递多个参数,使用结构体的方式
    // pthread_t threads[NUM_TREADS];
    // thread_data td[NUM_TREADS];
    // int rc;
    // int i;
    // for(i=0;i<NUM_TREADS;i++){
    //     cout << "main(): creating thread, " << i << endl;
    //     td[i].threadid = i;
    //     td[i].message = (char*)"This is message";
    //     rc = pthread_create(&threads[i],NULL,printHello2,(void*)&td[i]);
    //     if(rc){
    //         cout << "Error:unable to create thread," << rc << endl;
    //         exit(-1);
    //     }
        
    // }
    // pthread_exit(NULL);

//     // [8] 设置线程属性为joinable,删除属性pthread_attr_destroy
//     int rc;
//     int i;
//     pthread_t threads[NUM_TREADS];
//     pthread_attr_t attr;
//     void* status;

 
//    // 初始化并设置线程为可连接的（joinable）
//    pthread_attr_init(&attr);
//    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
//    for( i=0; i < NUM_TREADS; i++ ){
//       cout << "main() : creating thread, " << i << endl;
//       rc = pthread_create(&threads[i], NULL, wait, (void *)&i );
//       if (rc){
//          cout << "Error:unable to create thread," << rc << endl;
//          exit(-1);
//       }
//    }
 
//    // 删除属性，并等待其他线程
//    pthread_attr_destroy(&attr);
//    for( i=0; i < NUM_TREADS; i++ ){
//       rc = pthread_join(threads[i], &status);
//       if (rc){
//          cout << "Error:unable to join," << rc << endl;
//          exit(-1);
//       }
//       cout << "Main: completed thread id :" << i ;
//       cout << "  exiting with status :" << status << endl;
//    }
 
//    cout << "Main: program exiting." << endl;
//    pthread_exit(NULL);
}

