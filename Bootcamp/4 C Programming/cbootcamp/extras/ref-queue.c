/* 
	@file ref-queue.c 
	@brief  This file is a reference implementation of a queue
			that you can use if you get stuck. Please do not 
			look at this until you have put a serious effort
			into attempting the task. Cachelab will require a 
			non-trivial amount of C coding, and it is important
			that you re-familiarize yourself with C.
	
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
boundary* init_queue()
{
	//Create Head and Tail Nodes and initialize all default values
	boundary* head = malloc(sizeof(boundary));
	boundary* tail = malloc(sizeof(boundary));

	head->other_bound = tail;
	tail->other_bound = head;

	head->queue_pointer = NULL;
	tail->queue_pointer = NULL;
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
	//If queue is malformed, return NULL
	if(head == NULL)
		return NULL;
	//Init rover and output variables
	node* rover = head->queue_pointer; //Guaranteed to be non-null
	
	//Linear Search through all nodes until end of queue to find ID
	while(rover != NULL)
	{
		if(strcmp(rover->id, id) == 0)
		{
			return rover;
		}
		rover = rover->next;
	}
	return NULL;
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
	//If the queue is malformed, or somehow a request violates the invariants,
	//return with error
	if(head == NULL)
		return -1;

	//Create new node and fill in information
	node* new_node = malloc(sizeof(node));	
	new_node->id = malloc(strlen(id)+1); //Don't forget null terminator!
	strcpy(new_node->id, id);
	new_node->data = malloc(size);
	new_node->len = size;
	memcpy(new_node->data, data, size);

	//Add individual entry to the queue while checking special case that the
	//new node is the first into the queue
	if(head->queue_pointer != NULL)
		add_node(head, new_node);
	else
	{
		head->queue_pointer = new_node;
		head->other_bound->queue_pointer = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
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
	//Splice nodes
	node* return_node = head->queue_pointer;

	//Verify return buffer is large enough - Better way is to allocate this 
	//for the user
	if(size < return_node->len)
		return -1;

	//Check edge case that we dequeue the last node
	if(return_node->next != NULL)
	{
		head->queue_pointer = head->queue_pointer->next;
		return_node->next->prev = NULL;
	}
	else
	{
		head->queue_pointer = NULL;
		head->other_bound->queue_pointer = NULL;
	}

	//Copy over data
	memcpy(return_data, return_node->data, return_node->len);
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
	//Splice nodes
	boundary* tail = head->other_bound;
	tail->queue_pointer->next = new_node;
	new_node->prev = tail->queue_pointer;
	new_node->next = NULL;
	tail->queue_pointer = new_node;
}

/*
	@brief Internal helper function that frees all allocated parts of the nodes
	@param node - Node to be freed
*/
void free_node(node* node)
{
	free(node->id);
	free(node->data);
	free(node);
}
