#include<stdio.h>
#define MAX 5

int front=-1,rear =-1;
int queue[MAX];



void enqueue(int data){
  //queue is empty
    if(front ==-1){
        front = rear = 0;
        //take input
        queue[rear]=data;
      }
  //queue is full
    else if(rear==MAX-1){
      printf("\nQueue is full , cannot take input");}
  //queue is semi full
    else{
        rear = rear + 1;
        queue[rear]=data;
      }
  }

  void dequeue(){
    //take place from front
    //if queue is empty
    if(front == -1){
      printf("\nThe queue is empty cannot dequeue");
    }
    //if last element of the queue
    else if(front == MAX-1){
      printf("\nDequeued [%d] from queue.",queue[front]);
      front = rear =-1;
    }
    //if the queue is semi empty
    else{
      if(front ==0){
        printf("\nDequeued [%d] from queue.",queue[front]);
        front = front+1;
      }else{
        printf("\nDequeued [%d] from queue.",queue[front]);
        front=front+1;
      }
    }
  }

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  // enqueue(60);
  for(int i = 0; i<5;i++){
    dequeue();
  }
  return 0;
}