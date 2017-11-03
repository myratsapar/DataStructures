#ifndef marc
#define marc
struct student{
	int id;
	char *name;
	student *next;
};

typedef struct student Student;

void printList(student *root);
student *insertStudent(student *root, int id, char *name);
student *delStudent(student *root, int id, char *name);

#endif


