#include<iostream>
#include <string>

using namespace std;

class LoopQueue
{
public:
 LoopQueue(int c = 10);
 ~LoopQueue();
 bool isEmpty();        //队列的判空
 int size();            //队列的大小
 bool push(string t);        //入队列
 bool pop();            //出队列
 string front();            //队首元素

private:
 int capacity;
 int begin;
 int end;
 string *queue;
};


LoopQueue::LoopQueue(int c) :capacity(c), begin(0), end(0) {
 queue = new string[capacity];
}

LoopQueue::~LoopQueue() {
 delete[] queue;
}

bool LoopQueue::isEmpty() {
 if (begin == end)
  return true;
 return false;
}

int LoopQueue::size() {
 return (end - begin + capacity) % capacity;
}

bool LoopQueue::push(string t) {
 if ((end + 1) % capacity == begin) {
  cout << "队列满了" << endl;
  return false;
 }
 queue[end] = t;
 end = (end + 1) % capacity;
}

bool LoopQueue::pop() {
 if (end == begin) {
  cout << "空队列" << endl;
  return false;
 }
 begin = (begin + 1) % capacity;
}

string LoopQueue::front() {
 if (end == begin) {
  return "空队列";
 }
 return queue[begin];
}

int main()
{
 LoopQueue queue(6);
 queue.push("one");
 queue.push("two");
 queue.push("three");
 queue.push("four");
 queue.push("five");
 cout << "队列长度" << queue.size() << endl;
 while (!queue.isEmpty())
 {
  cout << queue.front() << endl;
  queue.pop();
 }
 //getchar();
 //system("pause");
 return 0;
}