#include <stdio.h>
#include <stdlib.h>



// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Start with empty list

// Function to insert at the end
void insert(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf(" Inserted %d into the list.\n", value);
}

// Function to delete a node by value
void delete(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head needs to be deleted
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf(" Deleted %d from the list.\n", value);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf(" Element %d not found.\n", value);
        return;
    }

    // Unlink and delete
    prev->next = temp->next;
    free(temp);
    printf(" Deleted %d from the list.\n", value);
}

// Function to print the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf(" List is empty.\n");
        return;
    }

    printf(" Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    int choice, value, count;

    do {
        printf("\n===== Singly Linked List Menu =====\n");
        printf("1. Insert Multiple Elements\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(" How many elements do you want to insert? ");
                scanf("%d", &count);
                printf(" Enter %d values:\n", count);
                for (int i = 0; i < count; i++) {
                    scanf("%d", &value);
                    insert(value);
                }
                break;

            case 2:
                printf(" Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf(" Exiting program.\n");
                break;

            default:
                printf(" Invalid option. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
