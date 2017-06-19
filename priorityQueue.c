// Complete the implementations for init(),full(), empty() and dequeue() functions - refer slides and notes of your own
// Also update the main function to test the queue ADT implementation

#include<stdio.h>
#define SIZE 10
void isort(int d[], int size)
{
    int i,k,l;
    int temp;
    for(k=1;k<size;k++){        // insert elements starting from 2nd
        for(i=0;i<k && d[i]<=d[k];i++);     // find where to insert - ith place
        temp=d[k];                          // copy kth element to temp
        for(l=k;l>i;l--) d[l]=d[l-1];       // shift to make room to insert at ith
        d[i]=temp;                          //insert kth element to ith place
    }                           // huh... all done :-)
}
struct queue { 	int head, tail;
		int data[SIZE]; 	};

int increment(int ind)  {   return ++ind==SIZE?0:ind; }
int init(struct queue* q){ q->head=q->tail=0; } 	// set head and tail
int full(struct queue* q){ return increment(q->tail)==q->head; }			// returns 1 if full
int empty(struct queue* q){return q->head==q->tail; }  			// returns 1 if empty

void enqueue(struct  queue *q, int item){    q->data[q->tail]=item;
                                             q->tail=increment(q->tail);
                                             isort(q->data,q->tail-q->head); }
int dequeue(struct queue*q){    int temp=q->data[q->head];
                                q->head=increment(q->head);
                                return temp;}

void main(void){		// this is the main function we used to test the stack ADT - change this to test the above queue
struct queue stk1;
int i=0;
int data[]={59,21,45,71,2,69,13,85,34,25,49};
init(&stk1);
while(!full(&stk1)) enqueue(&stk1,data[i++]);			// may need to execute the two lines from here more than once.
while(!empty(&stk1))printf("\n%i",dequeue(&stk1));		// Enqueueing till full and dequeueing will not circulate the queue via
}							// the array!
