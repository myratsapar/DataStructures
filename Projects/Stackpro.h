#ifndef stackpro
#define stackpro

struct student{
	int id;
	char *name;
	struct student *next;
};

typedef struct student Student;

student *pushStudent(student *root, int id, char *name);
int popStudent(student *root);
void printStack(student *root);

#endif
