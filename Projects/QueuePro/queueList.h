#ifndef queueList
#define queueList
struct student{
	int id;
	struct student *next;
};

typedef struct student Student;

student *enque(student *root, int id);
student *deque(student *root);
void printQueue(student *root);

#endif
