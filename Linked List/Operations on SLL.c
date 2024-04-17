#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};


void append(struct Node**head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = new_node;
}


void insert(struct Node**head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = *head_ref;
    *head_ref = new_node;
}

void insert_at_any_position(struct Node* *head_ref, int new_data, int position)
{
        if(position <= 0)
    {
        printf("%d is an invalid position, linked list remains the same\n", position);
        return;
    }
    else if(position == 1)
    {
        insert(head_ref, new_data);
    }
    else
    {
    struct Node*curr = *head_ref;
     struct Node*temp = NULL;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    for(int i = 1; i <= position - 2  ; i++)
    {
        curr = curr -> next;
    }
    temp = curr -> next;
    curr -> next = new_node;
    // *head_ref = new_node;
    new_node -> next = temp;
    }
}

int get_size(struct Node*head_ref)
{
    int count = 0;
    while(head_ref)
    {
        count++;
        head_ref = head_ref -> next;
    }
    return count;
}

void insert_at_middle(struct Node* *head_ref, int new_data)
{
    int size = get_size(*head_ref);
    printf("%d", size);
    if(head_ref == NULL)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node = new_data;
        new_node -> next = NULL;
        head_ref = new_node;
    }
    else 
    {
        if(size % 2 == 0)
        {
            insert_at_any_position(head_ref , new_data , (size / 2) + 1);
        }
        else
        {
            insert_at_any_position(head_ref, new_data, (size + 1) / 2);
        }
    } 
}

void insert_at_the_end(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = new_node;
}

void display(struct Node* node)
 {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void delete(struct Node* *head_ref, int target) 
{
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp  && temp->data == target) {
        *head_ref = temp->next;
        printf("Deleted sucessfully");
        return; 
    }
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target not found in the list!\n");
        return;
    }
    else
    {
    prev->next = temp->next;
    }
    free(temp);
}

void delete_the_first_node(struct Node** head_ref) 
{
    if (*head_ref == NULL) {
        printf("Underflow!!\n");
        return;
    }

    struct Node* temp = *head_ref;  
    *head_ref = temp->next;         
    free(temp);                     
}

void delete_at_the_middle(struct Node** head_ref) 
{
    if (*head_ref == NULL) {
        printf("Linked list is empty, nothing to delete.\n");
        return;
    }
    struct Node* first_ptr = *head_ref;
    struct Node* second_ptr = *head_ref;
    struct Node* prev = NULL;
    while (second_ptr != NULL && second_ptr->next != NULL) 
    {
        prev = first_ptr;
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next->next;
    }

    if (prev != NULL) 
    {
        prev->next = first_ptr->next;
    } else 
    {
        *head_ref = first_ptr->next;
    }
    free(first_ptr);
}

void delete_at_the_end(struct Node** head_ref) 
{
    if (*head_ref == NULL) {
        printf("Underflow!!\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    while (current->next != NULL) 
    {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) 
    {
        prev->next = NULL;
    } else 
    {
        *head_ref = NULL;
    }
    free(current);
}

void delete_key(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("Linked list is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d is not present in the given linked list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

void reverse_the_linked_list(struct Node** head_ref) 
{
    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    struct Node* next = NULL;
    while (curr != NULL) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
    printf("The given linked list is now reversed successfully!!\n");
}

int searchElement (struct Node *head, int key)
{
  struct Node *current = head;	
  int index = 1;
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

void sort(struct Node** head_ref, int order) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
    {
        printf("The list is already sorted.\n");
        return;
    }

    struct Node* current = *head_ref;
    struct Node* index = NULL;
    int temp;

    while (current != NULL) 
    {
        index = current->next;

        while (index != NULL) 
        {
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
    struct Node* head = NULL; 
    int num_elements, data, choice, new_data, position, key;
    int order_choice;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &data);
        append(&head, data); 
    }   
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
        printf("9.Delte th given key value\n");
        printf("10.Reverse the linked list\n");
        printf("11.Search element\n");
        printf("12.Sort the elements\n");
        printf("13.Exit\n");
        scanf("%d", &choice);
        printf("Your selected option is: %d\n", choice);

        switch(choice)
        {
            case 1:
                printf("The linked list is: \n");
                display(head);
                break;

            case 2:
                printf("Enter a value to be insered: \n");
                scanf("%d", &new_data);
                insert(&head, new_data);
                printf("After inserting %d at the beginning, the linked list is: ", new_data);
                display(head);
                break;
                
            case 3:
                printf("Enter a value to be inserted at middle: ");
                scanf("%d", &new_data);
                insert_at_middle(&head, new_data);
                printf("After inserting %d at middle, the linked list is: ", new_data);
                display(head);
                break;
            
            case 4:
                printf("Enter a value to be inserted at the end: ");
                scanf("%d", &new_data);
                insert_at_the_end(&head, new_data);
                printf("After inserting %d at the end, the linked list is: ", new_data);
                display(head);
                break;

            case 5:
                printf("Enter a value to be inserted at any given position: ", new_data);
                scanf("%d", &new_data);
                printf("Enter the position where %d should be inserted: ", new_data);
                scanf("%d", &position);
                insert_at_any_position(&head, new_data, position);
                display(head);
                break;
            case 6:
                printf("The first node will be deleted in the linked list....\n");
                delete_the_first_node(&head);
                printf("After deleting the first node, the linked list is: ");
                display(head);
                break;
            
            case 7:
                printf("The node at the middle will be deleted...\n");
                delete_at_the_middle(&head);
                printf("After deleting the node at middle, the linked list is: ");
                display(head);
                break;

            case 8:
                printf("The node at the end will be deleted...\n");
                delete_at_the_end(&head);
                printf("After deleting the last node, the linked list is: ");
                display(head);
                break;

            case 9:
                printf("Give the key value to be deleted in then linked list: ");
                scanf("%d", &key);
                delete_key(&head, key);
                printf("After deleting %d from linked list, the resulting linked list is: ", key);
                display(head);
                break;
            
            case 10:
                reverse_the_linked_list(&head);
                 printf("The reversed linked list is: ");
                display(head);
                break;

            case 11:
                {
                    int idx = searchElement(head, 1);
                    if(!idx)
                    {
                        printf("Element not found");
                    }
                    else
                    {
                        printf("Element found at position: %d", idx);
                    }
                }
                break;
            
            case 12:
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
                    printf("Terminating the process...");
                    break;

            default:
            printf("Invalid option, please re-enter the option: ");
        }
    } 
    while (choice != 12);
    return 0;
}