#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"
#include "queue.h"
#include "stack.h"
#include "hash_table.h"

void test_single_list() {
    Node* list = NULL;
    printf("====== testing single List... ======");
    removeHead(&list);
    removeTail(&list);
    printList(list); //nothing

    insertTail(&list, 10);
    printList(list); // 10,
    removeHead(&list);

    insertHead(&list, 100);
    printList(list); // 100,
    removeTail(&list);

    insertTail(&list, 9);
    insertTail(&list, 10);
    insertTail(&list, 11);
    insertHead(&list, 2);
    insertHead(&list, 1);
    insertHead(&list, 0);
    printList(list); // 0, 1, 2, 9, 10, 11,
    printf("====== testing single List Done ======");
}

void test_queue() {
    Queue* q = NULL;
    printf("====== testing Queue... ======\n");
    enqueue(q, 100);
    dequeue(q);
    initQueue(&q);
    dequeue(q);
    
    isEmpty(q) ? printf("Queue is empty\n") : printf("Queue is not empty\n");
    printQueue(q); // nothing

    enqueue(q, 10);
    printQueue(q);  // 10,
    enqueue(q, 20);
    printQueue(q);  // 10, 20,
    enqueue(q, 30);
    printQueue(q);  // 10, 20, 30,
    printf("peek = %d\n", peek(q)); // 10
    printf("length of queue = %d\n", length(q)); // 3

    dequeue(q);
    printf("peek = %d\n", peek(q)); // 20
    dequeue(q);
    printf("peek = %d\n", peek(q)); // 30
    enqueue(q, 50);
    printQueue(q);  // 30, 50,

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);  //nothing

    printf("====== testing Queue Done ======\n");
}

void test_stack() {
    Stack* st = NULL;

    printf("====== testing Stack... ======\n");
    printf("top = %d\n", top(st)); // -1
    pop(st); // nothing
    printStack(st); // nothing

    initStack(&st);
    printf("top = %d\n", top(st)); // -1
    pop(st); //nothing
    printStack(st); // nothing

    push(st, 10);
    push(st, 20);
    push(st, 30);
    printf("top = %d\n", top(st)); // 30
    printStack(st); // 30, 20, 10

    pop(st);
    printf("top = %d\n", top(st)); // 20

    push(st, 50);
    printStack(st); // 50, 20, 10

    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    printStack(st);

    printf("====== testing Stack Done ======\n");
}

void test_hash() {
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));
    int age = 0;
    initHash(map);

    existHash(map, "James") ? printf("James exist\n") : printf("James doesn't exist\n"); // James doesn't exist

    insertHash(map, "James", 27);
    insertHash(map, "Amy", 22);
    insertHash(map, "Tom", 40);
    printHash(map);
    /*
    "James", 27
    "Amy", 22
    "Tom", 40 */

    existHash(map, "James") ? printf("James exist\n") : printf("James doesn't exist\n"); // James exist

    getHash(map, "Amy", &age);
    printf("Amy age = %d\n", age); // Amy age = 22

    insertHash(map, "Amy", 30);
    getHash(map, "Amy", &age);
    printf("Amy age = %d\n", age); // Amy age = 30

    existHash(map, "Tom") ? printf("Tom exist\n") : printf("Tom doesn't exist\n"); // Tom exist
    removeHash(map, "Tom");
    existHash(map, "Tom") ? printf("Tom exist\n") : printf("Tom doesn't exist\n"); // Tom doesn't exist

    removeHash(map, "Allen"); // nothing
    removeHash(map, "James");
    removeHash(map, "Amy");

    getHash(map, "Amy", &age);
    printf("Amy age = %d\n", age); // Amy age = -1

    printHash(map);
    if (map) free(map);
}

int main(void) {
    //test_single_list();
    //test_queue();
    //test_stack();
    test_hash();
    return 0;
}