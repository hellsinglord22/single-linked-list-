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
    int input = 9;
    int value = 0;

    while(input != 0)
    {
    	printf("Choose an opition\n");
    	if (header == NULL)
    	{
    		printf("1. Create new head.\n");
    	}
    	printf("2. Insert new value.\n");
    	printf("3. Search for a value.\n");
    	printf("4. Delete a value.\n");
    	printf("5. Print the linked list.\n");
		printf("Enter 0 to exit\n");
    	// read the input 
    	scanf("%d", &input);

    	// first read the input 
    	switch(input)
    	{
    		case 1:
    			printf("Input: ");
    			scanf("%d", &value);
    			header = create(value);
    			break;

			case 2: 
				printf("Input: ");
				scanf("%d", &value);
				header = insert(header, value);
				break;				

			case 3: 
				printf("Input: ");
    			scanf("%d", &value);
    			if (search(header, value))
    				{
    					printf("Found\n");
    				}
    				else 
    				{
    					printf("Not Found\n");
    				}
				break;
			case 4:
				printf("Input: ");
    			scanf("%d", &value);
    			header = delete_node(header, value);
    			break;

    		case 5:
    			print(header);
    			break;

			default:
			{
				continue;
			}

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
