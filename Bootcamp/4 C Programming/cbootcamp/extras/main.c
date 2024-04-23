/* 
	@file Main.c
	@brief This file has a few test cases to verify your program. 
		   Feel free to add more test cases for individual functions
	@date <Fill this In>
	@author <Name> <Andrew ID>
*/


#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief Represents the size of the data we are testing the queue with**/
#define SIZE (sizeof(int))

int main()
{
	//Node 1
	boundary* queue = init_queue();
	printf("Testing Enqueue ...\n");
	char* id = "A";
	int* data = malloc(SIZE);
	*data = 15213;
	printf("Inserting the following element into queue: %d\n", *data);
	enqueue(queue, id, data, SIZE);
	node* check_node = find_object(queue, id);
	printf("Verifying element in queue:");
	if (check_node != NULL)
		printf("PASS\n");
	else
	{
		printf("FAIL\n");
		exit(1);
	}
	printf("Verifying correct data: %d\n", (*(int*)(check_node->data)));

	//Node 2
	char* id2 = "B";
	int* data2 = malloc(SIZE);
	*data2 = 15122;

	printf("Inserting the following element into queue: %d\n", *data2);
	enqueue(queue, id2, data2, SIZE);
	check_node = find_object(queue, id2);
	printf("Verifying element in queue:");
	if (check_node != NULL)
		printf("PASS\n");
	else
	{
		printf("FAIL\n");
		exit(1);
	}
	printf("Verifying correct data: %d\n", (*(int*)(check_node->data)));
	

	//Dequeue and verify queue behavior
	printf("Testing Dequeue ...\n");
	int* q_data = malloc(SIZE);
	dequeue(queue, q_data, SIZE);
	printf("Verifying correct data after dequeue:");
	if (*q_data == *data)
		printf("PASS\n");
	else
	{
		printf("FAIL: Expected(%d) Received(%d)\n", *data, *q_data);
		exit(1);
	}
	check_node = find_object(queue, id);
	printf("Verifying element not in queue:");
	if (check_node == NULL)
		printf("PASS\n");
	else
	{
		printf("FAIL\n");
		exit(1);
	}

	dequeue(queue, q_data, SIZE);
	printf("Verifying correct data after dequeue:");
	if (*q_data == *data2)
		printf("PASS\n");
	else
	{
		printf("FAIL: Expected(%d) Received(%d)\n", *data2, *q_data);
		exit(1);
	}
	check_node = find_object(queue, id);
	printf("Verifying element not in queue:");
	if (check_node == NULL)
		printf("PASS\n");
	else
	{
		printf("FAIL\n");
		exit(1);
	}
}
