/*1) Write a Menu driven C program to accomplish the following functionalities in single
linked list.
a) Create a single linked list.
b) Display the elements of a single linked list.
c) Insert a node at the beginning of a single linked list.
d) Insert a node at the end of a single linked list.
e) Insert a node before a given node of a single linked list.
f) Insert a node after a given node of a single linked list.
g) Delete a node from the beginning of a single linked list.
h) Delete a node from the end of a single linked list.
i) Delete a node after a given node of a single linked list.
j) Delete the entire single linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Head pointer for the linked list
struct Node* head = NULL;

// Create a single linked list
void createLinkedList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display the elements of the single linked list
void displayLinkedList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert a node at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end
void insertAtEnd(int value) {
    createLinkedList(value);
}

// Insert a node before a given node
void insertBeforeNode(int target, int value) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (head->data == target) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Target node not found.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert a node after a given node
void insertAfterNode(int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node not found.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Delete a node from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}

// Delete a node after a given node
void deleteAfterNode(int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Target node or next node not found.\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node after %d deleted.\n", target);
}

// Delete the entire linked list
void deleteEntireList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Entire linked list deleted.\n");
}

// Main function with menu
int main() {
    int choice, value, target;

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the elements of the single linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire single linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to create: ");
                scanf("%d", &value);
                createLinkedList(value);
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                printf("Enter value to insert before %d: ", target);
                scanf("%d", &value);
                insertBeforeNode(target, value);
                break;
            case 6:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                printf("Enter value to insert after %d: ", target);
                scanf("%d", &value);
                insertAfterNode(target, value);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                deleteAfterNode(target);
                break;
            case 10:
                deleteEntireList();
                break;
            case 11:
                printf("Exiting...\n");
                deleteEntireList();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


/*2) Write a Menu driven C program to accomplish the following functionalities in circular
linked list.
a) Create a circular linked list.
b) Display the elements of a circular linked list.
c) Insert a node at the beginning of a circular linked list.
d) Insert a node at the end of a circular linked list.
e) Delete a node from the beginning of a circular linked list.
f) Delete a node from the end of a circular linked list.
g) Delete a node after a given node of a circular linked list.
h) Delete the entire circular linked list.*/

/*#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the circular linked list
struct Node* last = NULL;

// Function to create a circular linked list
void createCircularLinkedList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    if (last == NULL) {
        newNode->next = newNode; // Point to itself
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

// Function to display elements of a circular linked list
void displayCircularLinkedList() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to start)\n");
}

// Function to insert a node at the beginning of a circular linked list
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

// Function to insert a node at the end of a circular linked list
void insertAtEnd(int value) {
    createCircularLinkedList(value);
}

// Function to delete a node from the beginning of a circular linked list
void deleteFromBeginning() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last == temp) { // Only one node in the list
        free(temp);
        last = NULL;
    } else {
        last->next = temp->next;
        free(temp);
    }
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end of a circular linked list
void deleteFromEnd() {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last == temp) { // Only one node in the list
        free(temp);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
    printf("Node deleted from the end.\n");
}

// Function to delete a node after a given node of a circular linked list
void deleteAfterNode(int target) {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        if (temp->data == target) {
            struct Node* delNode = temp->next;
            if (delNode == temp) { // Only one node
                last = NULL;
            } else {
                temp->next = delNode->next;
                if (delNode == last) {
                    last = temp;
                }
            }
            free(delNode);
            printf("Node after %d deleted.\n", target);
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
    printf("Node with value %d not found.\n", target);
}

// Function to delete the entire circular linked list
void deleteEntireList() {
    if (last == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    struct Node* temp = last->next;
    while (temp != last) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(last);
    last = NULL;
    printf("Entire circular linked list deleted.\n");
}

// Main function with menu
int main() {
    int choice, value, target;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display elements of the circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                createCircularLinkedList(value);
                break;
            case 2:
                displayCircularLinkedList();
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter the value of the node after which to delete: ");
                scanf("%d", &target);
                deleteAfterNode(target);
                break;
            case 8:
                deleteEntireList();
                break;
            case 9:
                printf("Exiting...\n");
                deleteEntireList();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
*/

 /*1) Write a Menu driven C program to accomplish the following functionalities in doubly
linked list.
a) Create a doubly linked list.
b) Display the elements of a doubly linked list.
c) Insert a node at the beginning of a doubly linked list.
d) Insert a node at the end of a doubly linked list.
e) Insert a node before a given node of a doubly linked list.
f) Insert a node after a given node of a doubly linked list.
g) Delete a node from the beginning of a doubly linked list.
h) Delete a node from the end of a doubly linked list.
i) Delete a node after a given node of a doubly linked list.
j) Delete the entire doubly linked list.*/

/*#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer for the doubly linked list
struct Node* head = NULL;

// Create a doubly linked list
void createDoublyLinkedList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Display the elements of the doubly linked list
void displayDoublyLinkedList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert a node at the beginning of the doubly linked list
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Insert a node at the end of the doubly linked list
void insertAtEnd(int value) {
    createDoublyLinkedList(value);
}

// Insert a node before a given node
void insertBeforeNode(int target, int value) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node not found.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
}

// Insert a node after a given node
void insertAfterNode(int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node not found.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Delete a node from the beginning of the doubly linked list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Delete a node from the end of the doubly linked list
void deleteFromEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Delete a node after a given node
void deleteAfterNode(int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Target node or next node not found.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != NULL) {
        delNode->next->prev = temp;
    }
    free(delNode);
    printf("Node after %d deleted.\n", target);
}

// Delete the entire doubly linked list
void deleteEntireList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Entire doubly linked list deleted.\n");
}

// Main function with menu
int main() {
    int choice, value, target;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display the elements of the doubly linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire doubly linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to create: ");
                scanf("%d", &value);
                createDoublyLinkedList(value);
                break;
            case 2:
                displayDoublyLinkedList();
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter value to insert before %d: ", target);
                scanf("%d", &value);
                insertBeforeNode(target, value);
                break;
            case 6:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter value to insert after %d: ", target);
                scanf("%d", &value);
                insertAfterNode(target, value);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter target node value: ");
                scanf("%d", &target);
                deleteAfterNode(target);
                break;
            case 10:
                deleteEntireList();
                break;
            case 11:
                printf("Exiting...\n");
                deleteEntireList();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}*/


/*2) Write a Menu driven C program to accomplish the following functionalities in circular
doubly linked list.
a) Create a circular doubly linked list.
b) Display the elements of a circular doubly linked list.
c) Insert a node at the beginning of a circular doubly linked list.
d) Insert a node at the end of a circular doubly linked list.
e) Delete a node from the beginning of a circular doubly linked list.
f) Delete a node from the end of a circular doubly linked list.
g) Delete a node after a given node of a circular doubly linked list.
h) Delete the entire circular doubly linked list.*/  

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

// Function prototypes
void createList();
void displayList();
void insertAtBeginning();
void insertAtEnd();
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterNode();
void deleteEntireList();

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular doubly linked list\n");
        printf("2. Display the elements of the list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: displayList(); break;
            case 3: insertAtBeginning(); break;
            case 4: insertAtEnd(); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: deleteAfterNode(); break;
            case 8: deleteEntireList(); break;
            case 9: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void createList() {
    int n, data, i;
    Node *newNode, *temp;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            temp = head->prev;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }
    printf("Circular doubly linked list created.\n");
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertAtBeginning() {
    int data;
    Node* newNode;

    printf("Enter data for the new node: ");
    scanf("%d", &data);

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd() {
    int data;
    Node* newNode;

    printf("Enter data for the new node: ");
    scanf("%d", &data);

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
    printf("Node inserted at the end.\n");
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        Node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* tail = head->prev;

    if (head->next == head) {
        head = NULL;
    } else {
        Node* secondLast = tail->prev;
        secondLast->next = head;
        head->prev = secondLast;
    }
    free(tail);
    printf("Node deleted from the end.\n");
}

void deleteAfterNode() {
    int key;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the node data after which deletion should occur: ");
    scanf("%d", &key);

    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* target = temp->next;
            if (target == head) {
                printf("Cannot delete, as it would break the circularity.\n");
                return;
            }
            temp->next = target->next;
            target->next->prev = temp;
            free(target);
            printf("Node deleted after %d.\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node with data %d not found.\n", key);
}

void deleteEntireList() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    Node* current = head;
    Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);

    head = NULL;
    printf("Entire list deleted.\n");
}
