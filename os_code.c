#include <stdio.h>
struct student
{
    int StudentId;
    int FoodTakenTime;
    int WaitingTime;
    int TurnAroundTime;
};
int main()
{
    struct student data[20];
    int n,i;
    char c='n';
     do
	{
    printf("Please enter the No. of Students wants to eat in mess? : ");
    scanf("%d", &n);
    accept(data, n);
    scheduling(data, n);
    waitingTime(data,n);
    turnAroundTime(data,n);
    display(data, n);
    printf("Want to continue? press 'y' : ");
    scanf("%s",&c);
    }while(c=='y');
    return 0;
} 
