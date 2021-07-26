#include<iostream>
using namespace std;

struct Node{
 int val;
 Node *next,*prev;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList();
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index);
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val);
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val);
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val);
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index);
 
private:
 int size;
 Node *root;
};

MyLinkedList::MyLinkedList(){
 size = 0;
 root->next=NULL;
 root->prev=NULL;
 root->val=0;
}

int MyLinkedList::get(int index){
 Node *ptemp = root->next;
 for(int i=0; i<indx; i++){
  ptemp=ptemp->next;
 }
 return ptemp->val;
}

void MyLinkedList::addAtHead(int val){
 if(size!=0){
  Node *addNode = new Node;
  
  size++;
  addNode->val=val;
  
  addNode->prev=root->next->prev;
  addNode->next=root->next;
  root->next->prev->next=addNode;
  root->next->prev=addNode;
 }
 else{
  Node *addNode = new node;
  
  size++;
  addNode->val=val;
  
  root->next=addNode;
  addNode->next=addNode;
  addNode->prev=addNode;
 }
}

void MyLinkedList::addAtTail(int val){
  if(size!=0){
  Node *addNode = new Node;
  
  size++;
  addNode->val=val;
  
  addNode->prev=root->next->prev;
  addNode->next=root->next;
  
  root->next->prev->next=addNode;
  root->next->prev=addNode;
 }
 else{
  Node *addNode = new node;
  
  size++;
  addNode->val=val;
  
  root->next=addNode;
  addNode->next