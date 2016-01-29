/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void mystrcpy1(char *dst, const char *src)
{
while(*dst++=*src++);
}
struct student ** topKStudents(struct student *students, int len, int K) {
	int i,j;struct student temp;
	if(students==NULL||len<=0)
        return NULL;
    else
    {   struct student** ret=(student**)malloc(sizeof(student));
        for(i=0;i<K;i++)
        {
            for(j=0;j<len-i-1;j++)
            {
                if(students[j].score<students[j+1].score)
                {
                    mystrcpy1(temp.name,students[j].name);
                    //while(*(temp.name)++=*(students[j].name)++);
                    temp.score =students[j].score;
                    //student[j].name=(char*)malloc(sizeof(student[j+1].name)+1)
                    mystrcpy1((students[j].name),(students[j+1].name));
                    students[j].score= students[j+1].score;
                    mystrcpy1(students[j+1].name ,temp.name);
                    students[j+1].score = temp.score;
                }
            }
            mystrcpy1(ret[i]->name,students[i].name);
            ret[i]->score=students[i].score;
        }
        return ret;
    }

}
int main()
{
    struct student students[3] = { { "stud1", 70 }, { "stud2", 60 }, { "stud3", 50 } };
    int i;
    struct student **ans;
    ans=topKStudents(students, 3, 2);
    for(i=0;i<2;i++)
    {
        printf("name%s marks %d\n",ans[i]->name,ans[i]->score);
    }
}
