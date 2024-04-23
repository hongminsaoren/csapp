/* 
	@file Student-Queue.c 
	@brief This file maintains all the functions you will need to implement a generic queue
	@date 2023.11.18
	@author Richard Li Enty520
*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	@brief Creates the initial queue by creating two encompassing blocks and initializing all the values
	@param none
	@return Pointer to the head of the queue
*/
boundary* init_queue(void)
{
	//TODO: Create Head and Tail Nodes and initialize all default values
	boundary* head = malloc(sizeof(boundary));
    if(head == NULL)
    {
        printf("Error: malloc failed in init_queue\n");
        return NULL;
    }
    boundary* tail = malloc(sizeof(boundary));
    if(tail == NULL)
    {
        printf("Error: malloc failed in init_queue\n");
        return NULL;
    }
    head->queue_pointer = NULL;
    head->other_bound = tail;
    tail->queue_pointer = NULL;
    tail->other_bound = head;
    return head;
}

/*
	@brief Finds the requested data inside the queue using linear search
	@param head - Start of Queue
	@param id - id of data you are looking for
	@return Pointer to object containing data if found, NULL otherwise
*/
node* find_object(boundary* head, char* id)
{	
	head = head;
	id = id;
	//TODO: Check any invariants and return NULL if failure
    if (head == NULL)
    {
        printf("Error: head is NULL in find_object\n");
        return NULL;
    }
	//TODO: Init queue rover
    node* rover = head->queue_pointer;
	//TODO: Linear Search through all nodes until end of cache to find ID
    while (rover != NULL)
    {
        if (strcmp(rover->id, id) == 0)
        {
            break;
        }
        rover = rover->next;
    }
    return rover;
}

/*
	@brief Adds an element to the queue
	@param id - Character buffer containing the id
	@param data - pointer to generic data
	@param size - size of generic data
	@return Status Value - 0 for success, non-zero for error
*/
int enqueue(boundary* head, char* id, void* data, int size)
{
	head = head;
	id = id;
	data = data;
	size = size;
	//TODO: Check any invariants and return status code if failure
    if (head == NULL)
    {
        printf("Error: head is NULL in enqueue\n");
        return -1;
    }
	//TODO: Create a new node and fill in relevant information
	//You can use built-in functions to copy data. 
	//Hint: strcpy, memcpy, strlen
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in enqueue\n");
        return -1;
    }
    new_node->id = malloc(strlen(id) + 1);
    if (new_node->id == NULL)
    {
        printf("Error: malloc failed in enqueue\n");
        return -1;
    }
    strcpy(new_node->id, id);
    new_node->data = malloc(size);
    if (new_node->data == NULL)
    {
        printf("Error: malloc failed in enqueue\n");
        return -1;
    }
    memcpy(new_node->data, data, size);
    new_node->len = size;
	//TODO: Add individual entry to the queue
	//Hint: Are there any edge cases you need to worry about?
    if (head->queue_pointer != NULL)
    {
        add_node(head, new_node);
    }
    else
    {
        head->queue_pointer = new_node;
        head->other_bound->queue_pointer = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
	//TODO: Are all the functions you used safe? Is there a better way to implement this? 
	//Feel free to modify the function header to whatever you want to do it, if you have time.
    return 0;
}

/*
	@brief Removes element from the queue
	@param head - Pointer to start of queue
	@param return_data - buffer pre allocated by user that is large enough for data
	@param size - Amount of bytes that the user expects to be returned in buffer
	@return Status Value - 0 for success, non-zero for error
*/
int dequeue(boundary* head, void* return_data, int size)
{
	head = head;
	return_data = return_data;
	size = size;
	//TODO: Check any invariants and return status code if failure
    if (head == NULL)
    {
        printf("Error: head is NULL in dequeue\n");
        return -1;
    }
	//TODO: Remove the node at the start of the queue and splice
	//together the rest of the nodes
	//Hint: Are there any edge cases you need to worry about?
    node* return_node = head->queue_pointer;
    if (return_node == NULL)
    {
        printf("Error: queue is empty in dequeue\n");
        return -1;
    }
    if (size < return_node->len)
    {
        printf("Error: size is too small in dequeue\n");
        return -1;
    }
    while (return_node->next != NULL)
    {
        return_node = return_node->next;
    }
    if (return_node->prev != NULL)
    {
        return_node->prev->next = NULL;
        head->queue_pointer = return_node->prev;
    }
    else
    {
        head->queue_pointer = NULL;
        head->other_bound->queue_pointer = NULL;
    }
	//TODO: Make sure to clean up any resources that were allocated by this library!
    free_node(return_node);
	return 0;
}

/*
	@brief Internal function that adds node to the queue by actually manipulating the pointers
	@param head - Pointer to the start of the queue
	@param new_node - Pointer to the new node previously initialized 
	@return void
*/
void add_node(boundary* head, node* new_node)
{
	head = head;
	new_node = new_node;
	//TODO: Splice the pointers to insert the new_node into the queue
	//Hint: Where should the new node go?
    if (head == NULL)
    {
        printf("Error: head is NULL in add_node\n");
        return;
    }
    boundary* tail = head->other_bound;
    tail->queue_pointer->next = new_node;
    new_node->next = NULL;
    new_node->prev = tail->queue_pointer;
    tail->queue_pointer = new_node;
}

/*
	@brief Internal helper function that frees all allocated parts of the nodes
	@param node - Node to be freed
*/
void free_node(node* node)
{
	node = node;
	//TODO: Memory Cleanup
    if (node == NULL)
    {
        printf("Error: node is NULL in free_node\n");
        return;
    }
    free(node->id);
    free(node->data);
    free(node);
}
