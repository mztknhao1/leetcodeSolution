#include <iostream>
#include <utility>
#include <thread>
#include <chrono>       // 时钟和计时器库
#include <functional>
#include <atomic>       // 原子操作,类似互锁
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <mutex>        // 与Mutex相关的定义都在此文件中
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/thread.hpp>
#include <stdexcept>

/*
1. std::mutex,最基本的Mutex累,提供了上锁和解锁操作,同事,基本的互斥量不允许某个线程在已获得
   互斥量的情况下重复对该互斥量进行上锁操作,所以重复上锁会导致死锁
2. std::recursive_mutex,递归Mutex类,与std::mutex功能基本相同,但允许互斥量的拥有者
    (通常是)某个线程,重复上锁不会产生死锁,但是必须保证上锁和解锁相同
3. std::time_mutex,定时Mutex类,与std::mutex功能基本相同,但提供了两个额外的定时上锁操作,
    try_lock_for和try_lock_until,即某个线程在规定的时间内对互斥量进行上锁操作,如果在
    规定时间内获得了锁则true,超时则返回false
4. std::recursive_timed _mutex,定时递归类,既提供了重复上锁功能,又提供了定时上锁特性

*/

/*
Lock类两种,两种相关的RAII技术:Resource Acquisition is Initialization,资源获取即初始化

1. std::lock_guard,与Mutex RAII相关,方便线程对互斥量上锁
2. std::unique_lock,与Mutex RAII相关,方便线程对互斥量上锁,但提供了更好的上锁和解锁控制

*/

/*
其他类
1. std::once_flag, call_once
2. std::adopt_lock_t ==> struct adopt_lock_t {} ==>空的标记类,
    该类型常量对象adopt_lock通常座位参数传递给unique_lock或lock_guard的构造函数
3. std::detongshifer_lock_t类似与std::adopt_lock_t
4. std::try_to_lock_t
*/

/*
辅助函数
std::try_lock() 同时对多个互斥量上锁
std::lock() ==>同时对多个互斥量上锁
std::call_once, 如果多个线程需要同时调用某个函数,call_once可以保证多个线程对该函数只调用一次
*/

// 注意lock()调用后的三种可能情况
// (1) 互斥量没有上锁,调用线程后上锁,直到调用unlock()解锁
// (2) 互斥量已被别的线程上锁,线程阻塞
// (3) 已上锁,又调用,死锁

// try_lock(),尝试锁住互斥量,如果互斥量被其他线程占有,当前线程也不会被阻塞,同样三种情况,就是不会阻塞


class counter
{
public:
    counter() : count(0) { }

    int add(int val) {
        boost::recursive_mutex::scoped_lock scoped_lock(mutex);
        count += val;
        return count;
    }   
    int increment() {
        boost::recursive_mutex::scoped_lock scoped_lock(mutex);
        return add(1);
    }

private:
    boost::recursive_mutex mutex;
    int count;
};

counter c;

void change_count(void*)
{
    std::cout << "count == " << c.increment() << std::endl;
}

// int main(int, char*[])
// {

//     std::thread threads[10];
//     // spawn 10 threads:
//     for (int i=0; i<10; ++i)
//         threads[i] = std::thread(change_count,(void*)0);

//     for (auto& th : threads) th.join();
   
//     return 0;
// }


/*
// std::time_mutex比std::mutex多了两个成员函数,try_lock_for(),try_lock_until()
// try_lock_for()表示在这一段时间内如果线程没获得锁则被阻塞住,与std::mutex的try_lock()不同,
// try_lock如果被调用时没获得锁则直接返回false,如果在此期间其他线程释放了锁,则该线程可以获得互斥量的锁
// 如果超时则返回false
// try_lock_until则接受一个时间点作为参考,在指定时间未到来之前线程如果没获得锁则被阻塞,如果在此期间其他
// 线程释放了锁,则获得锁,如果超时返回false

std::timed_mutex mtx_time;
void fireworks(){
    // waiting to get a lock:each thread prints "-" every 200ms;
    while(!mtx_time.try_lock_for(std::chrono::milliseconds(200))){
        std::cout << "-";
    }

    // got a lock! -wait for 1s,then this thread prints "*"
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*\n";
    mtx_time.unlock();
}

int main(){
    std::thread threads[10];
    for(int i=0;i<10;++i){
        threads[i] = std::thread(fireworks);
    }
    for(auto& th:threads) th.join();
    return 0;
}
*/


/*
// lock_guard()介绍,与Mutex RAII相关
// 我的理解是方法被调用起始的时候被上锁,资源释放的同时解锁,不需要手动管理lock()和unlock()

std::mutex mtx;
void print_even(int x){
    if(x%2==0) std::cout << x << "is even\n";
    else throw (std::logic_error("not even"));
}

void print_thread_id(int id){
    try{
        // using local lock_guard to lock mtx guarantees unlocking on destruction
        std::lock_guard<std::mutex> lck(mtx);
        print_even(id);
    }
    catch(std::logic_error&){
        std::cout << "[exception caugth]\n";
    }
}

int main()
{
    std::thread threads[10];
    for(int i=0;i<10;i++){
        threads[i] = std::thread(print_thread_id,i+1);
    }
    for(auto& th:threads) th.join();
    return 0;
}
*/


// unique_lock()与RAII相关,提供更好的上锁控制
std::mutex mtx;
void print_block(int n,char c){
    std::unique_lock<std::mutex> lck(mtx);
    for(int i=0;i<n;i++){
        std::cout << c;
    }
    std::cout << '\n';
}
int main(){
    std::thread th1(print_block,50,'*');
    std::thread th2(print_block,50,'$');
    th1.join();
    th2.join();
    return 0;
}