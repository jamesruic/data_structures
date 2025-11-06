#pragma once

typedef struct queue_node {
    int val;
    struct queue_node* next;
} qNode;

typedef struct queue {
    qNode *front; //first Node
    qNode *back; //last Node
    int size;
} Queue;

qNode* CreateQNode(int val) {
    qNode* newNode = (qNode*)malloc(sizeof(qNode));
    if (newNode) {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

void initQueue(Queue **q) {
    *q = (Queue*)malloc(sizeof(Queue));
    if (*q) {
        (*q)->front = NULL;
        (*q)->back = NULL;
        (*q)->size = 0;
    }
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int val) {
    if (!q) return; //q is NULL

    qNode* newNode = CreateQNode(val);
    if (newNode) {
        if (isEmpty(q)) {
            q->front = q->back = newNode;
        }
        else {
            q->back->next = newNode;
            q->back = q->back->next;
        }
        q->size++;
    }
}

void dequeue(Queue *q) {
    if (!q || isEmpty(q)) return; //q is NULL

    qNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

int peek(Queue *q) {
    return (q && q->front) ? q->front->val : -1;
}

int length(Queue *q) {
    return q->size;
}

void printQueue(Queue* q) {
    if (!q || isEmpty(q)) return;

    qNode* curr = q->front;
    while (curr) {
        printf("%d, ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}