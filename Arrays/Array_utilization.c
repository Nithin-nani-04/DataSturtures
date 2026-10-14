
#include <stdio.h>

#define CAPACITY 10

int arr[CAPACITY];
int size = 0;

/* Display all elements */
void traverse(void) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Insert value at a given index */
void insert(int index, int value) {
    if (size == CAPACITY) {
        printf("Array is full.\n");
        return;
    }

    if (index < 0 || index > size) {
        printf("Invalid index.\n");
        return;
    }

    // Shift elements right to create space
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    size++;

    printf("Element inserted.\n");
}

/* Delete element at a given index */
void deleteAt(int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    // Shift elements left to fill the gap
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("Element deleted.\n");
}

/* Search for a value */
int search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}

/* Update an element */
void update(int index, int value) {
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    arr[index] = value;
    printf("Element updated.\n");
}

/* Display values and memory addresses */
void displayMemory(void) {
    printf("\nIndex   Value   Address\n");

    for (int i = 0; i < size; i++) {
        printf("%-7d %-7d %p\n",
               i, arr[i], (void *)&arr[i]);
    }
}

int main(void) {
    int choice, index, value;

    while (1) {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Display memory addresses\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter index and value: ");
                if (scanf("%d %d", &index, &value) != 2) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insert(index, value);
                break;

            case 2:
                printf("Enter index to delete: ");
                if (scanf("%d", &index) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                deleteAt(index);
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                index = search(value);
                if (index == -1)
                    printf("Element not found.\n");
                else
                    printf("Found at index %d.\n", index);
                break;

            case 5:
                printf("Enter index and new value: ");
                if (scanf("%d %d", &index, &value) != 2) {
                    printf("Invalid input.\n");
                    return 1;
                }
                update(index, value);
                break;

            case 6:
                displayMemory();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
