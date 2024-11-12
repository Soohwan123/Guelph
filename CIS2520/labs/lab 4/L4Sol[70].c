/*****************************************Question 4*****************************************/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

// Define a structure 'Person'
typedef struct {
    char name[50];
    int grade;
} Person;

// Define the Queue structure
typedef struct {
    Person queue[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to add a structure to the queue
void enqueue(Queue* q, Person p) {
    q->rear++;
    q->queue[q->rear] = p;
    q->size++;
}

// Function to print the queue contents
void printQueue(Queue* q) {
    printf("Queue contents:\n");
    for (int i = 0; i < q->size; i++) {
        int index = i;
        printf("Name: %s, Grade: %d\n", q->queue[index].name, q->queue[index].grade);
    }
}

int main() {
    Queue q;
    initializeQueue(&q);

    // Add 5 Person structures to the queue
    Person p1 = {"Alice", 64};
    Person p2 = {"Bob", 79};
    Person p3 = {"Charlie", 86};
    Person p4 = {"David", 99};
    Person p5 = {"Eva", 34};

    enqueue(&q, p1);
    enqueue(&q, p2);
    enqueue(&q, p3);
    enqueue(&q, p4);
    enqueue(&q, p5);

    // Print queue contents
    printQueue(&q);

    return 0;
}

/*****************************************Question 5*****************************************/

// #include <stdio.h>
// #include <string.h>

// #define MAX_SIZE 10

// // Define a structure 'Person'
// typedef struct {
//     char name[50];
//     int grade;
// } Person;

// // Define the Queue structure
// typedef struct {
//     Person queue[MAX_SIZE];
//     int front;
//     int rear;
//     int size;
// } Queue;

// // Function to initialize the queue
// void initializeQueue(Queue* q) {
//     q->front = 0;
//     q->rear = -1;
//     q->size = 0;
// }

// // Function to add a structure to the queue
// void enqueue(Queue* q, Person p) {
//     q->rear++;
//     q->queue[q->rear] = p;
//     q->size++;
// }

// // Function to remove the front item from the queue
// void dequeue(Queue* q) {
//     printf("Removing: Name: %s, Grade: %d\n", q->queue[q->front].name, q->queue[q->front].grade);
//     q->front++;
//     // printf("size: %d", q->size);
//     q->size--;
// }

// // Function to print the queue contents
// void printQueue(Queue* q) {   
//     for (int i = q->front; i < q->rear + 1; i++) {
//         int index = i;
//         printf("Name: %s, Grade: %d\n", q->queue[index].name, q->queue[index].grade);
//     }
// }

// int main() {
//     Queue q;
//     initializeQueue(&q);

//     // Add 5 Person structures to the queue
//     Person p1 = {"Alice", 64};
//     Person p2 = {"Bob", 79};
//     Person p3 = {"Charlie", 86};
//     Person p4 = {"David", 99};
//     Person p5 = {"Eva", 34};

//     enqueue(&q, p1);
//     enqueue(&q, p2);
//     enqueue(&q, p3);
//     enqueue(&q, p4);
//     enqueue(&q, p5);

//     // Print the queue before removal
//     printf("Queue before removal:\n");
//     printQueue(&q);
//     printf("\n\n");

//     // Remove the first two items
//     dequeue(&q);  // Remove the first item
//     dequeue(&q);  // Remove the second item
//     printf("\n");

//     // Print the queue after removal
//     printf("\nQueue after removing first two items:\n");
//     printQueue(&q);

//     return 0;
// }

/*****************************************Question 6*****************************************/

// #include <stdio.h>
// #include <string.h>

// #define MAX_SIZE 10

// // Define a structure 'Person'
// typedef struct {
//     char name[50];
//     int grade;
// } Person;

// // Define the Queue structure
// typedef struct {
//     Person queue[MAX_SIZE];
//     int front;
//     int rear;
//     int size;
// } Queue;

// // Function to initialize the queue
// void initializeQueue(Queue* q) {
//     q->front = 0;
//     q->rear = -1;
//     q->size = 0;
// }

// // Function to check if the queue is full
// int isFull(Queue* q) {
//     return q->size == MAX_SIZE;
// }

// // Function to add a structure to the queue (with a check for full queue)
// void enqueue(Queue* q, Person p) {
//     if (isFull(q)) {
//         printf("Error: Queue is full, cannot add item: Name: %s, Grade: %d\n", p.name, p.grade);
//         return;
//     }
//     q->rear++;
//     q->queue[q->rear] = p;
//     q->size++;
//     printf("Added: Name: %s, Grade: %d\n", p.name, p.grade);
// }

// // Function to print the queue contents
// void printQueue(Queue* q) {   
//     for (int i = 0; i < q->size; i++) {
//         int index = i;
//         printf("Name: %s, Grade: %d\n", q->queue[index].name, q->queue[index].grade);
//     }
// }

// int main() {
//     Queue q;
//     initializeQueue(&q);

//     // Add 11 Person structures to the queue
//     Person p1 = {"Alice", 64};
//     Person p2 = {"Bob", 79};
//     Person p3 = {"Charlie", 86};
//     Person p4 = {"David", 99};
//     Person p5 = {"Eva", 34};
//     Person p6 = {"Frank", 65};
//     Person p7 = {"Grace", 100};
//     Person p8 = {"Henry", 21};
//     Person p9 = {"Ivy", 78};
//     Person p10 = {"Jack", 51};
//     Person p11 = {"Katy", 89};  // 11th person to cause error

//     // Enqueue 11 people
//     enqueue(&q, p1);
//     enqueue(&q, p2);
//     enqueue(&q, p3);
//     enqueue(&q, p4);
//     enqueue(&q, p5);
//     enqueue(&q, p6);
//     enqueue(&q, p7);
//     enqueue(&q, p8);
//     enqueue(&q, p9);
//     enqueue(&q, p10);

//     // This 11th addition should trigger the "Queue is full" error
//     enqueue(&q, p11);

//     // Print the queue contents
//     printf("\nFinal queue state:\n");
//     printQueue(&q);

//     return 0;
// }

/****************************************Question 7*****************************************/
// 
// #include <stdio.h>
// #include <string.h>
// 
// #define MAX_SIZE 10
// 
// // Define a structure 'Person'
// typedef struct {
//     char name[50];
//     int grade;
// } Person;
// 
// // Define the Queue structure
// typedef struct {
//     Person queue[MAX_SIZE];
//     int front;
//     int rear;
//     int size;
// } Queue;
// 
// // Function to initialize the queue
// void initializeQueue(Queue* q) {
//     q->front = 0;
//     q->rear = -1;
//     q->size = 0;
// }
// 
// // Function to check if the queue is empty
// int isEmpty(Queue* q) {
//     return q->size == 0;
// }
// 
// // Function to add a structure to the queue
// void enqueue(Queue* q, Person p) {
//     q->rear++;
//     q->queue[q->rear] = p;
//     q->size++;
// }
// 
// // Function to remove the front item from the queue (with a check for empty queue)
// void dequeue(Queue* q) {
//     if (isEmpty(q)) {
//         printf("Error: Queue is empty, cannot dequeue.\n");
//         return;
//     }
//     printf("Removed: Name: %s, Grade: %d\n", q->queue[q->front].name, q->queue[q->front].grade);
//     q->front++;
//     q->size--;
// }
// 
// // Function to print the queue contents
// void printQueue(Queue* q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty.\n");
//         return;
//     }
// 
//     for (int i = 0; i < q->rear + 1; i++) {
//         int index = (q->front + i) % MAX_SIZE;
//         printf("Name: %s, Grade: %d\n", q->queue[index].name, q->queue[index].grade);
//     }
// }
// 
// int main() {
//     Queue q;
//     initializeQueue(&q);
// 
//     // Add 1 Person structure to the queue
//     Person p1 = {"Alice", 64};
//     enqueue(&q, p1);
// 
//     // Print the queue before removal
//     printf("\nQueue before removal:\n");
//     printQueue(&q);
//     printf("\n");
// 
//     // Remove the first item
//     dequeue(&q);  // This should successfully remove the only item in the queue
//     printf("\n");
// 
//     // Attempt to remove another item from the empty queue, which should print an error
//     dequeue(&q);  // This should print an error as the queue is now empty
// 
//     // Print the queue after attempting removal
//     printf("\nQueue after attempting to remove two items:\n");
//     printQueue(&q);
// 
//     return 0;
// }