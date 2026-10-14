
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
int size = 0;

/* Create a new node */
Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/* Access element by index */
Node *getNode(int index) {
    if (index < 0 || index >= size)
        return NULL;

    Node *temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp;
}

/* Insert at index */
void insert(int index, int value) {
    if (index < 0 || index > size) {
        printf("Invalid index.\n");
        return;
    }

    Node *newNode = createNode(value);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *prev = getNode(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    size++;
    printf("Inserted successfully.\n");
}

/* Delete at index */
void deleteAt(int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    Node *temp;

    if (index == 0) {
        temp = head;
        head = head->next;
    } else {
        Node *prev = getNode(index - 1);
        temp = prev->next;
        prev->next = temp->next;
    }

    free(temp);
    size--;

    printf("Deleted successfully.\n");
}

/* Update at index */
void update(int index, int value) {
    Node *temp = getNode(index);

    if (temp == NULL) {
        printf("Invalid index.\n");
        return;
    }

    temp->data = value;
    printf("Updated successfully.\n");
}

/* Search value */
int search(int value) {
    Node *temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == value)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}

/* Display elements */
void display(void) {
    Node *temp = head;
    int index = 0;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Index : Value\n");

    while (temp != NULL) {
        printf("%5d : %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
}

/* Display actual node addresses */
void displayMemory(void) {
    Node *temp = head;
    int index = 0;

    printf("\nIndex  Data  Node address  Next address\n");

    while (temp != NULL) {
        printf("%5d  %4d  %p  %p\n",
               index,
               temp->data,
               (void *)temp,
               (void *)temp->next);

        temp = temp->next;
        index++;
    }
}

/* Release all allocated nodes */
void freeList(void) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    size = 0;
}

int main(void) {
    int choice, index, value;

    while (1) {
        printf("\n--- LINKED-LIST ARRAY ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Access by index\n");
        printf("4. Update\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Display memory addresses\n");
        printf("8. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter index and value: ");
                if (scanf("%d %d", &index, &value) != 2)
                    goto done;
                insert(index, value);
                break;

            case 2:
                printf("Enter index to delete: ");
                if (scanf("%d", &index) != 1)
                    goto done;
                deleteAt(index);
                break;

            case 3: {
                printf("Enter index: ");
                if (scanf("%d", &index) != 1)
                    goto done;

                Node *temp = getNode(index);

                if (temp == NULL)
                    printf("Invalid index.\n");
                else
                    printf("Value = %d\n", temp->data);
                break;
            }

            case 4:
                printf("Enter index and new value: ");
                if (scanf("%d %d", &index, &value) != 2)
                    goto done;
                update(index, value);
                break;

            case 5:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1)
                    goto done;

                index = search(value);

                if (index == -1)
                    printf("Not found.\n");
                else
                    printf("Found at index %d.\n", index);
                break;

            case 6:
                display();
                break;

            case 7:
                displayMemory();
                break;

            case 8:
                goto done;

            default:
                printf("Invalid choice.\n");
        }
    }

done:
    freeList();
    return 0;
}
