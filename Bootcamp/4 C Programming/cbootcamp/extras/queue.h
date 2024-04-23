//Struct for individual nodes of queue
typedef struct node
{
	char* id; 			//ID for objects
	void* data; 		//Actual data
	struct node* next;	//Next queue block
	struct node* prev;	//Previous queue block
	int len;			//Length of data 
} node;

typedef struct boundary
{
	struct node* queue_pointer;
	struct boundary* other_bound;
} boundary;


//Cache functions for user
boundary* init_queue();
node* find_object(boundary* head, char* id);
int enqueue(boundary* head, char* id, void* data, int size);
int dequeue(boundary* head, void* return_data, int size);
void add_node(boundary* head, node* new_node);
void free_node(node* node);