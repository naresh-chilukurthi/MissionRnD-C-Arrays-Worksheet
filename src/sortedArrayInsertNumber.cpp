/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
#include<stdio.h>
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{   int array_index,i;
    if(Arr==NULL||len<=0)
	return NULL;
	else
    {

        for(array_index=0;array_index<len;array_index++)
        {
            if(Arr[array_index]>num)
            {
                break;
            }
        }

         Arr=(int*)realloc(Arr,sizeof(int)*(len+1));
    for(i=len;i>array_index;i--)
    {
        Arr[i]=Arr[i-1];

    }
    Arr[array_index]=num;

        return Arr;
    }
}

/*int main()
{
    int *Arr;
    int len,num,i;
    scanf("%d%d",&len,&num);
    Arr=(int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++)
        scanf("%d",&Arr[i]);
    Arr=sortedArrayInsertNumber(Arr,len,num);
    for(i=0;i<=len;i++)
        printf("%d ",Arr[i]);

}*/
