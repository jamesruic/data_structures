#pragma once

typedef struct stackNode {
    int val;
    struct stackNode *next;
} stNode;

typedef struct stack {
    stNode *top;
    int size;
} Stack;

stNode* createStackNode(int val) {
    stNode* newNode = (stNode*)malloc(sizeof(stNode));
    if (newNode) {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

void initStack(Stack **st) {
    if (!st) return;

    *st = (Stack*)malloc(sizeof(Stack));
    if (*st) {
        (*st)->top = NULL;
        (*st)->size = 0;
    }
}

int isStackEmpty(Stack* st) {
    return st->top == NULL;
}

void push(Stack *st, int val) {
    if (!st) return;

    stNode *temp = NULL, *newNode = createStackNode(val);
    if (!newNode) return;

    if (!isStackEmpty(st)) {
        newNode->next = st->top;
    }
    st->top = newNode;
    st->size++;
}

void pop(Stack *st) {
    if (!st || isStackEmpty(st)) return;

    stNode* temp = st->top;
    st->top = st->top->next;
    free(temp);
}

int top(Stack *st) {
    return (st && !isStackEmpty(st)) ? st->top->val : -1;
}

int lengthStack(Stack *st) {
    return (st) ? st->size : -1;
}

void printStack(Stack *st) {
    if (!st || isStackEmpty(st)) return;

    stNode* curr = st->top;
    while (curr) {
        printf("%d, ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}