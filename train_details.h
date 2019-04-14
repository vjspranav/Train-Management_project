#include<stdio.h>
#include<string.h>

struct cl{

};

struct time{
  int hour;
  int min;
};

struct train{
  char train_name[50];
  char from_city[50];
  char to_city[50];
  struct time departure;
  struct time arrival;
  int train_num;
  char classstr[50];
}a;

void get_train_details(){
FILE* fptr;
fptr = fopen("train_details.txt","a");
printf("Please enter the name of train: ");
scanf("%s", &a.train_name);
printf("Please enter from and to city with a space: ");
scanf("%s", &a.from_city);
scanf("%s", &a.to_city);
printf("Please enter available classes in the form 3A/2A...: ");
scanf("%s", &a.classstr);
printf("Please enter departure time(hours and minutes with a space): ");
scanf("%d", &a.departure.hour);
scanf("%d", &a.departure.min);
printf("Please enter arrival time(hours and minutes with a space): ");
scanf("%d", &a.arrival.hour);
scanf("%d", &a.arrival.min);
printf("Please enter Train number: ");
scanf("%d", &a.train_num);
fprintf(fptr,"%s %s %s %s %d:%d %d:%d %d\n", a.train_name, a.from_city, a.to_city, a.classstr, a.arrival.hour, a.arrival.min, a.departure.hour, a.departure.min, a.train_num);
}

void display_train_details(){
  int i = 1;
  FILE* fptr;
  fptr = fopen("train_details.txt","r");
  printf("\t|------------------------------------------------------------------------------------------------------------------------------------|");
  printf("\n\t|Sr.No\tTr.No\t\tName\t\tDestinations\t\tAvailable Class\t\tDeparture Time\t\tArrival Time\t     |\n");
  printf("\t|------------------------------------------------------------------------------------------------------------------------------------|");
  while(fscanf(fptr,"%s %s %s %s %d:%d %d:%d %d",  &a.train_name, &a.from_city, &a.to_city, &a.classstr, &a.arrival.hour, &a.arrival.min, &a.departure.hour, &a.departure.min, &a.train_num)!=EOF){
    printf("\n\t|%d.\t%d\t\t% 8s\t% 4s to %s\t\t% 8s\t\t%02d:%02d\t\t\t%02d:%02d\t\t     |",i, a.train_num, a.train_name, a.from_city, a.to_city, a.classstr, a.departure.hour, a.departure.min, a.arrival.hour, a.arrival.min?a.arrival.min:00);
    i++;
  }
    printf("\n\t--------------------------------------------------------------------------------------------------------------------------------------\n\n");
}
