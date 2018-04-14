#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#define N 100

typedef struct StudentNode
{
	char *name;
	char *surname;
	struct StudentNode *next;
	struct CourseNode *nextCourse;
}StudentNode;

typedef struct CourseNode
{
	char *name;
	int midterm;
	int final;
	struct CourseNode *next;
}CourseNode;

typedef struct StudentList
{
	struct StudentNode *head;
}StudentList;

typedef struct CourseList
{
	struct CourseNode *head;
}CourseList;

StudentNode *createStudentNode();
StudentList *createStudentList();
CourseNode *createCourseNode();
CourseList *createCourseList();
void addStudent(StudentList *listStudent, char *name, char *surname);
void addCourse(CourseList *listCourse, char *name);
void displayStudent(StudentList *listStudent);
void displayCourse(CourseList *listCourse);
char *input(char *s);

int main()
{
	system("color F");
	setlocale(LC_ALL, "Turkish");

	StudentList *studentList = createStudentList();
	CourseList *courseList = createCourseList();

	int choose = 0, count1 = 0, count2 = 0, midterm = 0, final = 0;
	char studentName[N][N], studentSurname[N][N], courseName[N][N];
	char findStudentName[N], findStudentSurname[N], findCourseName[N];

	do
	{
		printf("ÖÐRENCÝ OTOMASYONU\n");
		printf("---------------------------\n\n");
		printf("1) Öðrenci Ekleme\n");
		printf("2) Ders Ekleme\n");
		printf("3) Öðrenci Listesi\n");
		printf("4) Ders Listesi\n");
		printf("5) Öðrencinin Aldýðý Derslerin ve Notlarýnýn Listesi\n");
		printf("6) Dersi Alan Öðrencilerin Listesi\n");
		printf("\nHangi iþlemi yapmak istiyorsunuz:");
		scanf("%d", &choose);

		if (choose == 1)
		{
			system("cls");
			printf("ÖÐRENCÝ OTOMASYONU\n");
			printf("---------------------------\n\n");
			printf("1) Öðrenci Ekleme\n\n");
			printf("Öðrencinin adýný giriniz:");
			input(studentName[count1]);
			printf("Öðrencinin soyadýný giriniz:");
			input(studentSurname[count1]);

			addStudent(studentList, studentName[count1], studentSurname[count1]);

			count1++;

			printf("\nYeni iþlem yapmak için herhangi bir tuþa basýnýz:");
			_getch();
		}
		else if (choose == 2)
		{
			system("cls");
			printf("ÖÐRENCÝ OTOMASYONU\n");
			printf("---------------------------\n\n");
			printf("2) Ders Ekleme\n\n");
			printf("Öðrencinin adýný giriniz:");
			input(findStudentName);
			printf("Öðrencinin soyadýný giriniz:");
			input(findStudentSurname);

			StudentNode *iteratorStudent = studentList->head;

			while (iteratorStudent != NULL)
			{
				if (strcmp(iteratorStudent->name, findStudentName) == 0
					&& strcmp(iteratorStudent->surname, findStudentSurname) == 0)
				{
					printf("Dersin adýný giriniz:");
					input(courseName[count2]);
					printf("Vize notunu giriniz:");
					scanf("%d", &midterm);
					printf("Final notunu giriniz:");
					scanf("%d", &final);

					CourseNode *iteratorCourse = iteratorStudent->nextCourse;

					while (iteratorCourse->next != NULL)
						iteratorCourse = iteratorCourse->next;

					iteratorCourse->name = (char *)courseName[count2];
					iteratorCourse->midterm = midterm;
					iteratorCourse->final = final;
					iteratorCourse->next = createCourseNode();
					addCourse(courseList, courseName[count2]);
					count2++;
					break;
				}
				iteratorStudent = iteratorStudent->next;
			}

			printf("\nYeni iþlem yapmak için herhangi bir tuþa basýnýz:");
			_getch();
		}
		else if (choose == 3)
		{
			system("cls");
			printf("ÖÐRENCÝ OTOMASYONU\n");
			printf("---------------------------\n\n");
			printf("3) Öðrenci Listesi\n\n");

			displayStudent(studentList);

			printf("Yeni iþlem yapmak için herhangi bir tuþa basýnýz:");
			_getch();
		}
		else if (choose == 4)
		{
			system("cls");
			printf("ÖÐRENCÝ OTOMASYONU\n");
			printf("---------------------------\n\n");
			printf("4) Ders Listesi\n\n");

			displayCourse(courseList);

			printf("Yeni iþlem yapmak için herhangi bir tuþa basýnýz:");
			_getch();
		}
		else if (choose == 5)
		{
			StudentNode *iteratorStudent = studentList->head;

			system("cls");
			printf("ÖÐRENCÝ OTOMASYONU\n");
			printf("---------------------------\n\n");
			printf("5) Öðrencinin Aldýðý Derslerin ve Notlarýnýn Listesi\n\n");
			printf("Öðrencinin adýný giriniz:");
			input(findStudentName);
			printf("Öðrencinin soyadýný giriniz:");
			input(findStudentSurname);

			while (iteratorStudent != NULL)
			{
				if (strcmp(iteratorStudent->name, findStudentName) == 0
					&& strcmp(iteratorStudent->surname, findStudentSurname) == 0)
				{
					CourseNode *iteratorCourse = iteratorStudent->nextCourse;

					while (iteratorCourse->next != NULL)
					{
						printf("\n%s %d %d\n", iteratorCourse->name, iteratorCourse->midterm, iteratorCourse->final);
						iteratorCourse = iteratorCourse->next;
					}
				}
				iteratorStudent = iteratorStudent->next;
			}

			printf("\nYeni iþlem yapmak için herhangi bir tuþa basýnýz:");
			_getch();
		}
		else if (choose == 6)
		{
			StudentNode *iteratorStudent = studentList->head;

			system("cls");
			printf("ÖÐRENCÝ OTOMASYONU\n");
			printf("---------------------------\n\n");
			printf("6) Dersi Alan Öðrencilerin Listesi\n\n");
			printf("Dersin adýný giriniz:");
			input(findCourseName);

			while (iteratorStudent != NULL)
			{
				CourseNode *iteratorCourse = iteratorStudent->nextCourse;

				while (iteratorCourse != NULL)
				{
					if (strcmp(iteratorCourse->name, findCourseName) == 0)
					{
						printf("\n%s %s\n", iteratorStudent->name, iteratorStudent->surname);
					}
					iteratorCourse = iteratorCourse->next;
				}
				iteratorStudent = iteratorStudent->next;
			}

			printf("\nYeni iþlem yapmak için herhangi bir tuþa basýnýz:");
			_getch();
		}
		else
		{
			char exit = 'n';

			printf("Çýkmak istediðinize emin misiniz(y / n):");
			scanf("%s", &exit);

			if (exit == 'y')
				break;
		}
		system("cls");
	} while (1);

	return 0;
}

StudentList *createStudentList()
{
	StudentList *list = (StudentList *)malloc(sizeof(StudentList));

	StudentNode *newNode = createStudentNode();
	list->head = newNode;

	return list;
}

CourseList *createCourseList()
{
	CourseList *list = (CourseList *)malloc(sizeof(CourseList));

	CourseNode *newNode = createCourseNode();
	list->head = newNode;

	return list;
}

StudentNode *createStudentNode()
{
	StudentNode *newNode = (StudentNode *)malloc(sizeof(StudentNode));

	newNode->name = "";
	newNode->surname = "";
	newNode->next = NULL;
	newNode->nextCourse = createCourseNode();

	return newNode;
}

CourseNode *createCourseNode()
{
	CourseNode *newNode = (CourseNode *)malloc(sizeof(CourseNode));

	newNode->name = "";
	newNode->midterm = 0;
	newNode->final = 0;
	newNode->next = NULL;

	return newNode;
}

void addStudent(StudentList *listStudent, char *name, char *surname)
{
	StudentNode *iterator = listStudent->head;

	while (iterator->next != NULL)
		iterator = iterator->next;

	iterator->name = name;
	iterator->surname = surname;
	iterator->next = createStudentNode();
}

void addCourse(CourseList *listCourse, char *name)
{
	CourseNode *iterator = listCourse->head;

	while (iterator->next != NULL)
		iterator = iterator->next;

	iterator->name = name;
	iterator->next = createCourseNode();
}

void displayStudent(StudentList *listStudent)
{
	StudentNode *iterator = listStudent->head;

	while (iterator != NULL)
	{
		printf("%s %s\n", iterator->name, iterator->surname);
		iterator = iterator->next;
	}
}

void displayCourse(CourseList *listCourse)
{
	CourseNode *iterator = listCourse->head;

	while (iterator != NULL)
	{
		printf("%s\n", iterator->name);
		iterator = iterator->next;
	}
}

char *input(char *s)
{
	scanf("%99s", s);

	return s;
}