#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 10

// Declare the structure of the node
typedef struct Node {
    int data;
    struct Node *next;
} StackNode;

StackNode *top; // initialize a gloabl stackNode pointer variable that points to the top of the stack
// Function prototypes
void push(int v, StackNode **top); // takes a pointer to a pointer
int pop(StackNode **top);
int is_empty(StackNode *top); // takes the pointer as is

// Since top is the only global variable,
// to prevent race conditions, we need to add mutex locks to
// all the sections that make changes to access "top"

// Push function
void push(int v, StackNode **top)
{
    StackNode *new_node;
    printf("Thread is running Push() operation for value: %d\n", v);
    new_node = (StackNode *)malloc(sizeof(StackNode));
    new_node->data = v;
    new_node->next = *top;
    *top = new_node;
}

// Pop function
int pop(StackNode **top)
{
	StackNode *temp;
    if (is_empty(*top)) {
        printf("Stack empty \n");
        return 0;
	}
    else {
        int data = (*top)->data;
        printf("Thread is running Pop() operation and value is: %d\n",data);
		temp = *top;
        *top = (*top)->next;
		free(temp);
        return data;
    }
}

//Check if top is NULL (reads from top, doesnt do any writing, does it still need the mutex lock?)
int is_empty(StackNode *top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

// Thread's push function ?? (would these need any mutex locks?)
void* thread_push(void *args) // add mutex here or within the push and pull cause thats where the shared data (stack) is actually manipulated by each thread
{
	int i; // where does this get used? 
    int *threadId = (int *)args;
    push(*threadId + 1,&top);
    return NULL;
}

// Thread's pop function 
void* thread_pop(){ // add mutex here?
    pop(&top);
    return NULL;
}

// main function 
int main(void)
{
    StackNode *top = NULL;
    // two pthread_t arrays for pushing and popping
    pthread_t threads_push[NUM_THREADS]; 
    pthread_t threads_pop[NUM_THREADS];

    int thread_args[NUM_THREADS];
    int i, j;


// race condition possibilites are from this section, starts here 
    // Creating push threads
    for(i=0;i<NUM_THREADS;i++){
	    thread_args[i] = i;
	    pthread_create(&threads_push[i],NULL,thread_push, (void *)&thread_args[i]);
	}

	// Create Pop Threads
	for(i=0;i<NUM_THREADS;i++){
        thread_args[i] = i;
	    pthread_create(&threads_pop[i],NULL,thread_pop, NULL);
	}
// race condition possibilites ends here

	// Join Push Threads
	for(j = 0; j < NUM_THREADS; j++)
	{
	pthread_join(threads_push[j],NULL);
	}

    // Join Pop Threads
	for(j = 0; j < NUM_THREADS; j++)
	{
	pthread_join(threads_pop[j],NULL);
	}

    pthread_exit(NULL);
	return 0;
}
