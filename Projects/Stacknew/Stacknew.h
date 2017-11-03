#ifndef stacknew
#define stacknew
struct student{
	int id;
	struct student *next;
};
typedef struct student Student;
student *pushStack(student *root, int id);
student *popStack(student *root);
void printStack(student *root);
#endif
