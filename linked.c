// C Std Libraries 
#include <stdio.h>
#include <stdlib.h>

// Create a node
typedef struct sllist
{
    int data;
    struct sllist* next;
}sllnode;

// Methods prototype 
sllnode* create(int);
void print(sllnode*);
sllnode* insert(sllnode*, int);
void destroy(sllnode* header);
int search(sllnode*, int);
sllnode* delete_node(sllnode*, int); 

int main(int argc,char** argv)
{
    // sanity check 
    if (argc != 1)
    {
        printf("Usage: ./linked\n");
        return 1;
    }
    
    // Main Program 
    sllnode* header = NULL;
    char input; 
    while(1)
    {
        printf("Enter Q To Exit.\n");
        
        if (header == NULL)
        {
            printf("Enter 1 To Create a linked list.\n");
        }
        printf("Enter 2 To insert an element to the linked list.\n");
        printf("Enter 3 To delete an element from the linked list.\n");
        printf("Enter 4 To search for an element in the linked list.\n");
        printf("Enter 5 to print the linked list\n");
        
        input = getc(stdin);
        
        if (input == '1' && header == NULL)
        {
            // prompt to enter a value to insert
            printf("Enter a value to insert: ");
            int value; 
            scanf("%d", &value);
            
            header = create(value);
        }
        else if (input == '1' && header != NULL)
        {
            printf("You already created a linked list.\n");
            continue; 
        }
        else if ((input == '2' || input == '3' 
                || input == '4' || input == '5') && header == NULL)
        {
            printf("You need to create a header first.\n");
            continue;
        }
        else if (input == '2' && header != NULL)
        {
            printf("Enter the value you want to insert: ");
            int value; 
            scanf("%d", &value);
            
            header = insert(header, value);
            if (header == NULL)
            {
                printf("Error while inserting\n");
                destroy(header);
                return 1;
            }
        }
        else if (input == '3' && header != NULL)
        {
            printf("Enter the value you want to delete from the linked list.\n");
            int value; 
            scanf("%d", &value);
            delete_node(header, value);
        }
        else if (input == '4' && header != NULL)
        {
            printf("Enter the key you are searching for: ");
            int value; 
            scanf("%d", &value);
            if (search(header, value))
            {
                printf("The element was found");
            }
            else 
            {
                printf("The element was not found");
            }
        }
        else if (input == '5' && header != NULL)
        {
            print(header);
        }
        else if(input == 'q')
        {
            break;
        }
        else 
        {
            printf("Invalid opition\n");
            continue;
        }
    }
    
    // free the linked list 
    destroy(header);
    

    

    return 0;
}

// Methods implementation 
sllnode* create(int value)
{
    // creating the head of the list 
    sllnode* linkedList = NULL;
    
    // creating first node 
    linkedList = malloc(sizeof(sllnode));
    if (linkedList == NULL)
    {
        return NULL;
    }
    
    linkedList->data = value;
    linkedList->next = NULL;
    
    // return the head of the list 
    return linkedList;
    
}
void print(sllnode* header)
{
    sllnode* pointer = header;
    
    while(pointer != NULL)
    {
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
    
}
sllnode* insert(sllnode* header, int value)
{
    sllnode* node = malloc(sizeof(sllnode));
    if (node == NULL)
    {
        return NULL;
    }
    
    node->data = value;
    node->next = header;
    
    header = node; 
    return header;
}
void destroy(sllnode* header)
{
    if (header == NULL)
    {
        return;
    }   
    
    sllnode* pointer = header->next;
    destroy(pointer);
    free(header);
}
int search(sllnode* header, int key)
{
    int flag = 0;
    sllnode* pointer = header; 
    
    while(pointer != NULL)
    {
        if (pointer->data == key)
        {
            flag = 1; 
            break;
        }
        else
        {
            pointer = pointer->next;   
        }
    }
    
    return flag;
}
sllnode* delete_node(sllnode* head, int key)
{
    sllnode* pointer = head;
    sllnode* deletePointer = head;
    
    // delete first node
    if (deletePointer->data == key)
    {
        head = head->next;
        free(deletePointer);
        return head;
    }
    
        
    // delete anyother element 
    else
    {
        deletePointer = head->next;
        while(deletePointer != NULL)
        {
            if (deletePointer->data == key)
            {
                pointer->next = deletePointer->next;
                free(deletePointer);
                break;
            }
            
            else 
            {
                // keep moving your pointers 
                deletePointer = deletePointer->next;
                pointer = pointer->next;
            }
        }
        return head;
    }
}
