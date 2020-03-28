#include <stdio.h>
struct student
{
    int Stdnt_Id;
    int Fd_Tkn_Tm;
    int Wait_Tm;
    int Trn_Arnd_Tm;
};
void scheduling(struct student lst[], int s);
void turnAroundTime(struct student lst[], int n);
void acpt(struct student lst[], int s);
void waitingTime(struct student lst[], int n);
void display(struct student lst[], int s);
int main()
{
    struct student data[20];
    int n,i;
    char c='n';
    do
	{
    printf("Please enter the No. of Students wants to eat in mess? : ");
    scanf("%d", &n);
    acpt(data, n);
    scheduling(data, n);
    waitingTime(data,n);
    turnAroundTime(data,n);
    display(data, n);
    printf("Want to continue? press 'y' : ");
    scanf("%s",&c);
    }while(c=='y');
    return 0;
} 

//Display function
void display(struct student lst[80], int s)
{
    int i,AvgWaitingTime=0,AvgTurnAroundTime=0;
	int TotalWatingTime=0,TotalTurnAroundTime=0;
    printf("\n\n\t\t\tOutput according to LRTF\n");
    printf("\n\t\t\t|***************************************************************|");

    printf("\n\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n\t\t\t|***************************************************************|");
 
    for (i = 0; i < s; i++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", lst[i].Stdnt_Id, lst[i].Fd_Tkn_Tm,lst[i].Wait_Tm,lst[i].Trn_Arnd_Tm);
        
        printf("\a\n\t\t\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|");
		TotalWatingTime= TotalWatingTime+lst[i].Wait_Tm;
		TotalTurnAroundTime= TotalTurnAroundTime+lst[i].Trn_Arnd_Tm;
	} 
	printf("\n\n\t\t\tTotal Waiting Time is: = %d",TotalWatingTime);
	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",TotalTurnAroundTime);
	printf("\n\n\t\t\tAverage Waiting Time is: = %d",TotalWatingTime/s);
	printf("\n\t\t\tAverage Turn around Time is: = %d\n\n",TotalTurnAroundTime/s);
}





// Scheduling function
void scheduling(struct student lst[80], int s)
{
    int i, j;
    struct student temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (lst[j].Fd_Tkn_Tm < lst[j + 1].Fd_Tkn_Tm)
            {
                temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            } 
            else if(lst[j].Fd_Tkn_Tm == lst[j + 1].Fd_Tkn_Tm)
            {
            	if(lst[j].Stdnt_Id > lst[j + 1].Stdnt_Id)
            	{
            	temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
                }
			}
        }
    }
}

// Accept function
void acpt(struct student lst[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Student #%d", i + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &lst[i].Stdnt_Id);

        printf("Enter time taken for food (minuts): ");
        scanf("%d", &lst[i].Fd_Tkn_Tm);
    } 
}

//WAting time function

void waitingTime(struct student lst[80], int n)
{
	int j,total;
    lst[0].Wait_Tm=0;
    for(j=1;j<n;j++)
    {
        lst[j].Wait_Tm=lst[j-1].Wait_Tm+lst[j-1].Fd_Tkn_Tm;
    }
}

//Turnaround time function

void turnAroundTime(struct student lst[80], int n)
{
	int j,total;
    
    for(j=0;j<n;j++)
    {
        lst[j].Trn_Arnd_Tm=lst[j].Wait_Tm+lst[j].Fd_Tkn_Tm;
    }
}
