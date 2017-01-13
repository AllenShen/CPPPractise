#include <iostream>  
#include <thread>  
#include <future>  
#include "BlockingQueue.hpp"
using namespace std;

int main(int argc ,char* argv[]){
    BlockingQueue<int> q;
    auto t1 = std::async(std::launch::async,[&q](){
            for(int i = 0;i < 10;i++){
                q.put(i);
                std::cout << i << " put " << endl;
            }
    });

    auto t2 = std::async(std::launch::async,[&q](){
            while(q.Size() > 0){
            std::cout << q.Take() << " take in t2 " << std::endl;
            }
    });

    auto t3 = std::async(std::launch::async,[&q](){
            while(q.Size() > 0){
            std::cout << q.Take() << " take in t3 " <<  std::endl;
            }
    });

   t1.wait();
   cout << "first end " << endl;
   t2.wait();
   cout << "second end " << endl;
   t3.wait();

    return 0;

}
