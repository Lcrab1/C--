#include<iostream>
#include<thread>


void DoWorker()
{
    std::cout << "Working" << std::endl;
}

int main()
{
    std::thread worker(DoWorker);
    
    worker.join();
    system("pause");
}