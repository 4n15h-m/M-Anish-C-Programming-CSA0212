#include <stdio.h>

#define MAX 40
#define SUBJECTS 3
#define ASSESSMENTS 2

typedef struct
{
    int id;
    char section;
    int marks[ASSESSMENTS][SUBJECTS];
    int total;
    float average;
} Student;

Student students[MAX];
int count = 4;

char *subjectNames[SUBJECTS] =
{
    "Physics", "Chemistry", "Maths"
};

/* Recursive sum */
int recursiveSum(int a[], int n)
{
    if(n == 0)
        return 0;
    return a[n - 1] + recursiveSum(a, n - 1);
}

/* Calculate student result */
void calculateResult(Student *s)
{
    int i, j;
    int values[ASSESSMENTS * SUBJECTS];
    int k = 0;

    for(i = 0; i < ASSESSMENTS; i++)
    {
        for(j = 0; j < SUBJECTS; j++)
        {
            values[k++] = s->marks[i][j];
        }
    }

    s->total = recursiveSum(values, k);
    s->average = s->total / (float)k;
}

/* Display individual result */
void displayResult(Student s)
{
    int i, j;

    printf("\nStudent ID: %d\n", s.id);
    printf("Section: %c\n", s.section);

    for(i = 0; i < ASSESSMENTS; i++)
    {
        printf("Assessment %d: ", i + 1);
        for(j = 0; j < SUBJECTS; j++)
        {
            printf("%d ", s.marks[i][j]);
        }
        printf("\n");
    }

    printf("Total: %d\n", s.total);
    printf("Average: %.2f\n", s.average);
}

/* Search student */
void searchStudent(int id)
{
    int i, found = 0;

    for(i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            displayResult(students[i]);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nStudent ID not found.\n");
}

/* Sort students by total in descending order */
void sortStudents()
{
    int i, j;
    Student temp;

    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(students[j].total <
               students[j + 1].total)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

/* Display merit list */
void displayMeritList()
{
    int i, rank = 1;

    printf("\nCONSOLIDATED MERIT LIST\n");

    for(i = 0; i < count; i++)
    {
        if(i > 0 &&
           students[i].total != students[i - 1].total)
        {
            rank = i + 1;
        }

        printf("Rank %d | ID: %d | Section: %c | "
               "Total: %d | Average: %.2f\n",
               rank,
               students[i].id,
               students[i].section,
               students[i].total,
               students[i].average);
    }
}

/* Subject-wise highest marks */
void subjectToppers()
{
    int i, j, a;
    int max, id;

    printf("\nSUBJECT-WISE TOPPERS\n");

    for(j = 0; j < SUBJECTS; j++)
    {
        max = -1;
        id = -1;

        for(i = 0; i < count; i++)
        {
            for(a = 0; a < ASSESSMENTS; a++)
            {
                if(students[i].marks[a][j] > max)
                {
                    max = students[i].marks[a][j];
                    id = students[i].id;
                }
            }
        }

        printf("%s: Student %d - %d marks\n",
               subjectNames[j], id, max);
    }
}

/* Main function */
int main()
{
    int i;

    /* Section A */
    students[0].id = 101;
    students[0].section = 'A';
    int a[2][3] =
    {
        {80, 75, 90},
        {85, 80, 95}
    };

    /* Section A */
    students[1].id = 102;
    students[1].section = 'A';
    int b[2][3] =
    {
        {70, 80, 75},
        {75, 85, 80}
    };

    /* Section B */
    students[2].id = 201;
    students[2].section = 'B';
    int c[2][3] =
    {
        {90, 85, 80},
        {90, 90, 85}
    };

    /* Section B */
    students[3].id = 202;
    students[3].section = 'B';
    int d[2][3] =
    {
        {75, 75, 75},
        {80, 80, 80}
    };

    for(i = 0; i < 2; i++)
    {
        int j;
        for(j = 0; j < 3; j++)
        {
            students[0].marks[i][j] = a[i][j];
            students[1].marks[i][j] = b[i][j];
            students[2].marks[i][j] = c[i][j];
            students[3].marks[i][j] = d[i][j];
        }
    }

    /* Calculate results */
    for(i = 0; i < count; i++)
        calculateResult(&students[i]);

    printf("SMART EXAMINATION SYSTEM\n");

    printf("\nINDIVIDUAL STUDENT RESULTS\n");
    for(i = 0; i < count; i++)
        displayResult(students[i]);

    /* Search */
    printf("\nSEARCHING STUDENT ID 102\n");
    searchStudent(102);

    /* Subject toppers */
    subjectToppers();

    /* Sorting and ranking */
    sortStudents();
    displayMeritList();

    return 0;
}
