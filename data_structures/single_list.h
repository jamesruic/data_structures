#pragma once

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* CreateNode(int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node) {
        node->data = val;
        node->next = NULL;
    }
    return node;
}

void insertHead(Node** node, int val) {
    if (!node) return;
    if (!*node) {
        *node = CreateNode(val);
        return;
    }

    Node* newNode = CreateNode(val);
    newNode->next = *node;
    *node = newNode;
}

void insertTail(Node** node, int val) {
    if (!node) return;
    if (!*node) {
        *node = CreateNode(val);
        return;
    }
    
    Node* newNode = CreateNode(val);
    if (newNode) { // if allocate newNode success
        Node *tail = *node;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void removeHead(Node** node) {
    if (!node || !*node) return; // If the list is empty, do nothing

    if (!(*node)->next) {
        // Only one node in the list
        free(*node);
        *node = NULL;
    }
    else {
        Node* temp = *node;
        *node = (*node)->next;
        free(temp);
    }
}

void removeTail(Node** node) {
    if (!node || !*node) return; // If the list is empty, do nothing

    if (!(*node)->next) {
        // Only one node in the list
        free(*node);
        *node = NULL;
    }
    else {
        Node *curr = *node, *prev = NULL;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
}

void printList(Node *node) {
    while (node) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
}