#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node
{
    int data;
    struct Node* next;
};

// Function to append a new node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Initialize the new node with the given data and NULL next pointer
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node as the head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Traverse to the end of the linked list and append the new node
    struct Node* last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert(struct Node** head_ref, int new_data)
{
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Initialize the new node with the given data and point it to the current head
    new_node->data = new_data;
    new_node->next = *head_ref;
    // Make the new node as the head of the linked list
    *head_ref = new_node;
}

// Function to insert a new node at any given position in the linked list
void insert_at_any_position(struct Node** head_ref, int new_data, int position)
{
    // Check if the position is valid
    if (position <= 0)
    {
        printf("%d is an invalid position, linked list remains the same\n", position);
        return;
    }
    else if (position == 1)
    {
        // If position is 1, simply call the insert function to insert at the beginning
        insert(head_ref, new_data);
    }
    else
    {
        // Allocate memory for the new node
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        // Traverse to the node just before the specified position
        struct Node* curr = *head_ref;
        for (int i = 1; i <= position - 2; i++)
        {
            curr = curr->next;
        }
        // Insert the new node after the current node
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

// Function to get the size of the linked list
int get_size(struct Node* head_ref)
{
    int count = 0;
    // Traverse the linked list and count the number of nodes
    while (head_ref)
    {
        count++;
        head_ref = head_ref->next;
    }
    return count;
}

// Function to insert a new node at the middle of the linked list
void insert_at_middle(struct Node** head_ref, int new_data)
{
    // Get the size of the linked list
    int size = get_size(*head_ref);
    // Check if the linked list is empty
    if (*head_ref == NULL)
    {
        // If empty, create a new node with the given data and make it the head
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = NULL;
        *head_ref = new_node;
    }
    else
    {
        // Calculate the position to insert based on the size of the linked list
        int position = (size % 2 == 0) ? (size / 2) + 1 : (size + 1) / 2;
        // Insert the new node at the calculated position
        insert_at_any_position(head_ref, new_data, position);
    }
}

// Function to insert a new node at the end of the linked list
void insert_at_the_end(struct Node** head_ref, int new_data)
{
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node as the head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Traverse to the end of the linked list and append the new node
    struct Node* last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

// Function to display the elements of the linked list
void display(struct Node* node)
{
    // Traverse the linked list and print each node's data
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete a node with the given data from the linked list
void delete(struct Node** head_ref, int target)
{
    // If the target node is the head, delete the head node
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp && temp->data == target) {
        *head_ref = temp->next;
        printf("Deleted successfully");
        return;
    }
    // Traverse the linked list to find the target node
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }
    // If target node is not found, print a message
    if (temp == NULL) {
        printf("Target not found in the list!\n");
        return;
    }
    else
    {
        // Delete the target node by adjusting the previous node's next pointer
        prev->next = temp->next;
    }
    // Free the memory occupied by the target node
    free(temp);
}

// Function to delete the first node from the linked list
void delete_the_first_node(struct Node** head_ref)
{
    // If the linked list is empty, print a message
    if (*head_ref == NULL) {
        printf("Underflow!!\n");
        return;
    }

    // Store the current head node in a temporary variable
    struct Node* temp = *head_ref;
    // Update the head to point to the next node
    *head_ref = temp->next;
    // Free the memory occupied by the old head node
    free(temp);
}

// Function to delete the node at the middle of the linked list
void delete_at_the_middle(struct Node** head_ref)
{
    // If the linked list is empty, print a message
    if (*head_ref == NULL) {
        printf("Linked list is empty, nothing to delete.\n");
        return;
    }
    // Initialize two pointers to traverse the linked list
    struct Node* first_ptr = *head_ref;
    struct Node* second_ptr = *head_ref;
    struct Node* prev = NULL;
    // Traverse the linked list with the second pointer moving twice as fast as the first
    while (second_ptr != NULL && second_ptr->next != NULL)
    {
        prev = first_ptr;
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next->next;
    }
    // Delete the node at the middle by adjusting the previous node's next pointer
    if (prev != NULL)
    {
        prev->next = first_ptr->next;
    } else
    {
        *head_ref = first_ptr->next;
    }
    // Free the memory occupied by the node at the middle
    free(first_ptr);
}

// Function to delete the last node from the linked list
void delete_at_the_end(struct Node** head_ref)
{
    // If the linked list is empty, print a message
    if (*head_ref == NULL) {
        printf("Underflow!!\n");
        return;
    }
    // Initialize two pointers to traverse the linked list
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    // Traverse to the last node of the linked list
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    // Adjust the previous node's next pointer to delete the last node
    if (prev != NULL)
    {
        prev->next = NULL;
    } else
    {
        *head_ref = NULL;
    }
    // Free the memory occupied by the last node
    free(current);
}

// Function to delete a node with the given key value from the linked list
void delete_key(struct Node** head_ref, int key) {
    // If the linked list is empty, print a message
    if (*head_ref == NULL) {
        printf("Linked list is empty, nothing to delete.\n");
        return;
    }
    // Initialize two pointers to traverse the linked list
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    // If the key value matches the data of the head node, delete the head node
    if (temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }
    // Traverse the linked list to find the node with the given key value
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // If the key value is not found, print a message
    if (temp == NULL) {
        printf("Node with value %d is not present in the given linked list.\n", key);
        return;
    }
    // Delete the node with the given key value by adjusting the previous node's next pointer
    prev->next = temp->next;
    // Free the memory occupied by the node with the given key value
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Function to reverse the linked list
void reverse_the_linked_list(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    struct Node* next = NULL;
    // Reverse each link in the linked list
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Update the head pointer to point to the new head of the reversed linked list
    *head_ref = prev;
    printf("The given linked list is now reversed successfully!!\n");
}

// Function to search for an element in the linked list and return its position
int searchElement(struct Node* head, int key)
{
    struct Node* current = head;
    int index = 1;
    // Traverse the linked list to find the element with the given key
    while (current != NULL)
    {
        if (current->data == key)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return 0;
}

// Function to sort the elements of the linked list in ascending or descending order
void sort(struct Node** head_ref, int order) {
    // If the linked list is empty or contains only one node, it is already sorted
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        printf("The list is already sorted.\n");
        return;
    }

    // Traverse the linked list and perform bubble sort
    struct Node* current = *head_ref;
    struct Node* index = NULL;
    int temp;

    while (current != NULL)
    {
        index = current->next;

        while (index != NULL)
        {
            // Swap nodes if they are in the wrong order based on the sorting order
            if (order == 1)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
            else if (order == 2)
            {
                if (current->data < index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
            else
            {
                printf("Invalid order option.\n");
                return;
            }

            index = index->next;
        }

        current = current->next;
    }

    printf("The list has been sorted ");
    if (order == 1)
    {
        printf("in ascending order.\n");
    }
    else if (order == 2)
    {
        printf("in descending order.\n");
    }
    printf("Sorted linked list is: ");
    display(*head_ref);
}

int main() {
    // Initialize the head of the linked list to NULL
    struct Node* head = NULL;
    int num_elements, data, choice, new_data, position, key;
    int order_choice;

    // Get the number of elements in the linked list from the user
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    // Get the elements of the linked list from the user
    printf("Enter %d elements:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    // Display the menu and perform operations based on user choice
    do
    {
        printf("Select the required option:\n");
        printf("1.Display the linked list\n");
        printf("2.Insert at beginning\n");
        printf("3.Insert at middle\n");
        printf("4.Insert at the end\n");
        printf("5.Insert at any given position\n");
        printf("6.Delete at the beginning\n");
        printf("7.Delete at middle\n");
        printf("8.Delete at the end\n");
        printf("9.Delete the given key value\n");
        printf("10.Reverse the linked list\n");
        printf("11.Search element\n");
        printf("12.Sort the elements\n");
        printf("13.Exit\n");
        scanf("%d", &choice);
        printf("Your selected option is: %d\n", choice);

        switch(choice)
        {
            // Handle each menu option
            case 1:
                // Display the linked list
                printf("The linked list is: \n");
                display(head);
                break;

            case 2:
                // Insert at the beginning
                printf("Enter a value to be inserted: \n");
                scanf("%d", &new_data);
                insert(&head, new_data);
                printf("After inserting %d at the beginning, the linked list is: ", new_data);
                display(head);
                break;

            case 3:
                // Insert at the middle
                printf("Enter a value to be inserted at middle: ");
                scanf("%d", &new_data);
                insert_at_middle(&head, new_data);
                printf("After inserting %d at middle, the linked list is: ", new_data);
                display(head);
                break;

            case 4:
                // Insert at the end
                printf("Enter a value to be inserted at the end: ");
                scanf("%d", &new_data);
                insert_at_the_end(&head, new_data);
                printf("After inserting %d at the end, the linked list is: ", new_data);
                display(head);
                break;

            case 5:
                // Insert at any given position
                printf("Enter a value to be inserted at any given position: ");
                scanf("%d", &new_data);
                printf("Enter the position where %d should be inserted: ", new_data);
                scanf("%d", &position);
                insert_at_any_position(&head, new_data, position);
                display(head);
                break;

            case 6:
                // Delete at the beginning
                printf("The first node will be deleted in the linked list....\n");
                delete_the_first_node(&head);
                printf("After deleting the first node, the linked list is: ");
                display(head);
                break;

            case 7:
                // Delete at the middle
                printf("The node at the middle will be deleted...\n");
                delete_at_the_middle(&head);
                printf("After deleting the node at middle, the linked list is: ");
                display(head);
                break;

            case 8:
                // Delete at the end
                printf("The node at the end will be deleted...\n");
                delete_at_the_end(&head);
                printf("After deleting the last node, the linked list is: ");
                display(head);
                break;

            case 9:
                // Delete the given key value
                printf("Give the key value to be deleted in then linked list: ");
                scanf("%d", &key);
                delete_key(&head, key);
                printf("After deleting %d from linked list, the resulting linked list is: ", key);
                display(head);
                break;

            case 10:
                // Reverse the linked list
                reverse_the_linked_list(&head);
                printf("The reversed linked list is: ");
                display(head);
                break;

            case 11:
                // Search for an element
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int idx = searchElement(head, key);
                if (idx != 0)
                {
                    printf("Element found at position: %d\n", idx);
                }
                else
                {
                    printf("Element not found\n");
                }
                break;

            case 12:
                // Sort the elements
                printf("Select sorting order:\n");
                printf("1. Ascending Order\n");
                printf("2. Descending Order\n");
                scanf("%d", &order_choice);
                if (order_choice == 1)
                {
                    sort(&head, 1);
                }
                else if (order_choice == 2)
                {
                    sort(&head, 2);
                }
                else
                {
                    printf("Invalid order option.\n");
                }
                break;

            case 13:
                // Exit the program
                printf("Terminating the process...\n");
                return 0;
                break;

            default:
                // Handle invalid option
                printf("Invalid option, please re-enter the option: ");
        }
    }
    while (1);
    return 0;
}
