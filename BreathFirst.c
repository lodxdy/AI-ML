#include <stdio.h>
#include <stdlib.h>

// Define structure of tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Define structure of queue node
struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

// Define structure of queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct Node* node) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->node = node;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a node
void enqueue(struct Queue* queue, struct Node* node) {
    struct QueueNode* newQueueNode = createQueueNode(node);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

// Function to dequeue a node
struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;
    struct Node* tempNode = queue->front->node;
    struct QueueNode* tempQueueNode = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(tempQueueNode);
    return tempNode;
}

// Function to perform BFS on the tree
void bfs(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();

    // Enqueue the root node
    enqueue(queue, root);

    while (queue->front != NULL) {
        // Dequeue a node from the front
        struct Node* currentNode = dequeue(queue);

        // Print the data of the current node
        printf("%d ", currentNode->data);

        // Enqueue the left child
        if (currentNode->left != NULL)
            enqueue(queue, currentNode->left);

        // Enqueue the right child
        if (currentNode->right != NULL)
            enqueue(queue, currentNode->right);
    }

    // Free the queue memory
    free(queue);
}

int main() {
    // Create the tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Add more nodes to increase the depth to 5
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(11);
    root->right->left->left = createNode(12);
    root->right->left->right = createNode(13);
    root->right->right->left = createNode(14);
    root->right->right->right = createNode(15);

    // Further add nodes to make it depth 5
    root->left->left->left->left = createNode(16);
    root->left->left->left->right = createNode(17);
    root->left->left->right->left = createNode(18);
    root->left->left->right->right = createNode(19);
    root->left->right->left->left = createNode(20);
    root->left->right->left->right = createNode(21);
    root->left->right->right->left = createNode(22);
    root->left->right->right->right = createNode(23);
    root->right->left->left->left = createNode(24);
    root->right->left->left->right = createNode(25);
    root->right->left->right->left = createNode(26);
    root->right->left->right->right = createNode(27);
    root->right->right->left->left = createNode(28);
    root->right->right->left->right = createNode(29);
    root->right->right->right->left = createNode(30);
    root->right->right->right->right = createNode(31);

    // Perform BFS
    printf("BFS Traversal: ");
    bfs(root);
    printf("\n");

    return 0;
}
