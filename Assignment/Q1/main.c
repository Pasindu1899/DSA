#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0



//Implementation of a circular Queue


//Defining a circular queue

#define MAXQUEUE 10

typedef  int  QueueElement;

  typedef struct queue {
         QueueElement items[MAXQUEUE];
         int front;
         int rear;
         int count;
    } Queue;

//Creating the circular queue

void CreateQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}



//Empty condition check for circular queue

int IsQueueEmpty(const Queue*q)
{
    return(q->count==0);
}



//Full condition check for circular queue

int IsQueueFull(const Queue*q)
{
   return(q->count==MAXQUEUE);
}



// Append an element to the circular queue

void Append(Queue *q,QueueElement x)
{
    if(IsQueueFull(q))
    {
        printf("Queue Full\n");
        exit(1);
    }
    else
    {
        q->rear = (q->rear+1)%MAXQUEUE;
        q->items[(q->rear)]=x;
        q->count++;

        printf("Appended element:%d\n",x);
    }
}



// Serve an element from the circular queue
void Serve(Queue *q, QueueElement *x)
{
if (IsQueueEmpty(q))
    {
        printf("queue is empty, underflow\n");
        exit(1);
    }
    else
    {
        *x=q->items[(q->front)];
        q->front = (q->front+1) % MAXQUEUE;
        q->count--;
        printf("served item:%d \n",*x);
    }

}



//size of the circular queue

//int QueueSize(const Queue *q)
//{
//    return (q->count);
//}




//Display the circular queue.

void displayQueue(const Queue *q)
    {
        if(IsQueueEmpty(q))
        {
            printf("Circular Queue is empty\n");
            return;
        }
        printf("\nCircular Queue Element:");
         for (int i = q-> front;i <= q-> rear; i++)
         {
             printf("%d ", q->items[i]);
         }
         printf("\n");
    }


//implementation of a double-ended queue

// Defining a Dequeue

#define MAXDQUEUE 10

typedef  int  DqueueElement;


  typedef struct dqueue {
         DqueueElement items[MAXDQUEUE];
         int front;
         int rear;
         int count;
    } Dqueue;




//Creating a Dequeue

void CreateDqueue(Dqueue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}




//Empty condition check for dequeue

int IsDqueueEmpty(Dqueue*q)
{
    if(q->rear<q->front)
        return(TRUE);
    else
        return(FALSE);
}




//Full condition check for dequeue

int IsDqueueFull(Dqueue*q)
{
    if(q->rear==MAXDQUEUE-1)
        return(TRUE);
    else
        return(FALSE);
}



// Append an element to the rear of the Dequeue.

void AppendRear(Dqueue *q,DqueueElement x)
{
    if(IsDqueueFull(q))
    {
        printf("Dequeue is Full\n");
        exit(1);
    }
    else
    {
        q->items[++(q->rear)]=x;
        q->count++;

        printf("Appended element to the rear:%d\n",x);
    }
}




// Append an element to the front of the Dequeue.

/*void AppendFront(Dqueue *q,DqueueElement x)
{
    if(IsDqueueFull(q))
    {
        printf("Dequeue is Full\n");
        exit(1);
    }
    else
    {
        if (IsDqueueEmpty(q))
        {
              q->items[q->front] = x;
              q->rear++;

        }
            else
            {
                if (q->front ==0)
                {

                		for (int i=q->rear; i >= q->front; i--)
                                q->items[i+1] = q->items[i];

                		q->rear++;
               		 q->items[q->front] = x;

                }
                    else
                        q->items[--(q->front)] = x;


            }
               q->count++;

    }
}*/




// Serve an element from the front of the Dequeue.

void ServeFront(Dqueue *q, DqueueElement *x)
{
if (IsDqueueEmpty(q))
    {
        printf("Dqueue is empty, underflow\n");
        exit(1);
    }
    *x=q->items[(q->front)++];
    q->count--;
    printf("served element from front:%d \n",*x);
}




// Serve an element from the rear of the Dqueue.

/*void ServeRear(Dqueue *q, DqueueElement *x)
{
if (IsDqueueEmpty(q))
    {
        printf("Dqueue is empty, underflow\n");
        exit(1);
    }
    *x=q->items[(q->rear)--];
    q->count--;
    printf("served item from rear:%d \n",*x);
}*/



//Display the Dequeue

void displayDqueue(const Dqueue *q)
    {
        if(IsDqueueEmpty(q))
        {
            printf("Dequeue is empty\n");
            return;
        }
        printf("\nDequeue Element:");
         for (int i = q-> front;i <= q-> rear; i++)
         {
             printf("%d ", q->items[i]);
         }
         printf("\n");
    }




//Main program of the Dequeue

int mainDQ (){

    Dqueue DQ;

    DqueueElement D_item;

    CreateDqueue(&DQ);

     AppendRear (&DQ, 75);

     AppendRear (&DQ, 110);

     AppendRear (&DQ, 125);

     ServeFront (&DQ,&D_item);

     AppendRear (&DQ, 50);

    displayDqueue(&DQ);

}



//Main Program of the circular queue

int mainCQ (){

    Queue CQ;

    QueueElement C_item;

    CreateQueue(&CQ);

    Append (&CQ, 85) ;

    Append (&CQ, 120) ;

    Append (&CQ, 135) ;

    Serve (&CQ,&C_item);

    Append (&CQ, 60)  ;


    displayQueue(&CQ);

}


int main() {

    printf("***** Dequeue Operations *****\n\n");
    mainDQ();  // Run DQ main program

    printf("\n***** Circular Queue Operations *****\n\n");
    mainCQ();  // Run CQ main program

    return 0;
}
