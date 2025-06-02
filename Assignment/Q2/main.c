#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0



// Defining a Dequeue

#define MAXDQUEUE 10

typedef  char  DqueueElement;


  typedef struct dqueue {
         DqueueElement items[MAXDQUEUE];
         int front;
         int rear;
         int count;
    } Dqueue;




//Creating the Dequeue

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





// Append an element to the front of the Dequeue.

void AppendFront(Dqueue *q,DqueueElement x)
{
    if(IsDqueueFull(q)){

        printf("Dequeue is Full\n");
        exit(1);

    }else{

        if (IsDqueueEmpty(q)){

              q->items[q->front] = x;
              q->rear++;}

            else{

                if (q->front ==0){

                		for (int i=q->rear; i >= q->front; i--)
                                q->items[i+1] = q->items[i];

                		q->rear++;
               		 q->items[q->front] = x;}

                    else
                        q->items[--(q->front)] = x;
                }
               q->count++;

               printf("Appended element to the front:%c\n",x);

    }
}




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
             printf("%c ", q->items[i]);
         }
         printf("\n");
    }




//Main program of the Dequeue

int main () {

    Dqueue DQ;

    CreateDqueue(&DQ);

    AppendFront(&DQ, 'M');

    AppendFront(&DQ, 'B');

    AppendFront(&DQ, 'L');

    AppendFront(&DQ, 'P');

    AppendFront(&DQ, 'C');

    AppendFront(&DQ, 'J');

    displayDqueue(&DQ);
}

