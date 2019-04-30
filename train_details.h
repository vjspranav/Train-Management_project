#include<stdio.h>
#include<string.h>
#include<stdbool.h>
struct cl{
bool A3, A2, A1, GN, SL, CC;
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
  struct cl cls;
}a;

struct train return_train_details(int i_train_num){
  int k=0;
  FILE *fptr;
  fptr = fopen("train_details.txt","r");
  while(fscanf(fptr,"%s %s %s %d:%d %d:%d %d %d %d %d %d %d %d",  &a.train_name, &a.from_city, &a.to_city, &a.arrival.hour, &a.arrival.min, &a.departure.hour, &a.departure.min, &a.train_num,  &a.cls.A3, &a.cls.A2, &a.cls.A1, &a.cls.SL, &a.cls.GN, &a.cls.CC)!=EOF)
    if(i_train_num==a.train_num){
      k=1;
      break;
    }
    fclose(fptr);
    if(k==1)
    return a;
    else{
      a.train_num = 10000;
      return a;
    }

}

void get_train_details(){
FILE* fptr;
fptr = fopen("train_details.txt","a");
printf("Please enter the name of train: ");
scanf("%s", &a.train_name);
printf("Please enter from and to city with a space: ");
scanf("%s", &a.from_city);
scanf("%s", &a.to_city);
printf("Enter 1/0 for the following (1=yes, 2=no)\n Has 3A: ");
scanf("%d", &a.cls.A3);
printf(" Has 2A: ");
scanf("%d", &a.cls.A2);
printf(" Has 1A: ");
scanf("%d", &a.cls.A1);
printf(" Has SL: ");
scanf("%d", &a.cls.SL);
printf(" Has GN: ");
scanf("%d", &a.cls.GN);
printf(" Has CC: ");
scanf("%d", &a.cls.CC);
printf("Please enter departure time(hours and minutes with a space): ");
scanf("%d", &a.departure.hour);
scanf("%d", &a.departure.min);
printf("Please enter arrival time(hours and minutes with a space): ");
scanf("%d", &a.arrival.hour);
scanf("%d", &a.arrival.min);
printf("Please enter Train number: ");
scanf("%d", &a.train_num);
fprintf(fptr,"%s %s %s %02d:%02d %02d:%02d %d %d %d %d %d %d %d\n", a.train_name, a.from_city, a.to_city, a.arrival.hour, a.arrival.min, a.departure.hour, a.departure.min, a.train_num,  a.cls.A3, a.cls.A2, a.cls.A1, a.cls.SL, a.cls.GN, a.cls.CC);
fclose(fptr);
}


void display_train_details_r(){
  int i = 1;
  FILE* fptr;
  fptr = fopen("train_details.txt","r");
  printf("\t|--------------------------------------------------------------------------------------------------------------------|");
  printf("\n\t|Sr.No\tTr.No\t\tName\t\t\tDestinations\t\t\tDeparture Time\t\tArrival Time |\n");
  printf("\t|--------------------------------------------------------------------------------------------------------------------|");
  while(fscanf(fptr,"%s %s %s %d:%d %d:%d %d %d %d %d %d %d %d",  &a.train_name, &a.from_city, &a.to_city, &a.arrival.hour, &a.arrival.min, &a.departure.hour, &a.departure.min, &a.train_num,  &a.cls.A3, &a.cls.A2, &a.cls.A1, &a.cls.SL, &a.cls.GN, &a.cls.CC)!=EOF){
    printf("\n\t|%d.\t%d\t\t% 8s\t% 10s to % 10s\t\t%02d:%02d\t\t\t%02d:%02d        |",i, a.train_num, a.train_name, a.from_city, a.to_city, a.departure.hour, a.departure.min, a.arrival.hour, a.arrival.min?a.arrival.min:00);
    i++;
  }
    printf("\n\t----------------------------------------------------------------------------------------------------------------------\n\n");
  fclose(fptr);
}

void display_train_details(){
  int i = 1;
  FILE* fptr;
  fptr = fopen("train_details.txt","r");
  printf("\t|--------------------------------------------------------------------------------------------------------------------|");
  printf("\n\t|Sr.No\tTr.No\t\tName\t\t\tDestinations\t\t\tDeparture Time\t\tArrival Time |\n");
  printf("\t|--------------------------------------------------------------------------------------------------------------------|");
  while(fscanf(fptr,"%s %s %s %d:%d %d:%d %d %d %d %d %d %d %d",  &a.train_name, &a.from_city, &a.to_city, &a.arrival.hour, &a.arrival.min, &a.departure.hour, &a.departure.min, &a.train_num,  &a.cls.A3, &a.cls.A2, &a.cls.A1, &a.cls.SL, &a.cls.GN, &a.cls.CC)!=EOF){
    printf("\n\t|%d.\t%d\t\t% 8s\t% 10s to % 10s\t\t%02d:%02d\t\t\t%02d:%02d\t     |",i, a.train_num, a.train_name, a.from_city, a.to_city, a.departure.hour, a.departure.min, a.arrival.hour, a.arrival.min?a.arrival.min:00);
    i++;
  }
    printf("\n\t----------------------------------------------------------------------------------------------------------------------\n\n");
  fclose(fptr);
}


void remove_train_details(){
  int c;
  display_train_details();
  printf("Please enter the train number of the train you want to remove from the list: ");
  scanf("%d", &c);
  FILE  *fptr1, *fptr2;
  fptr1 = fopen("train_details.txt","r");
  fptr2 = fopen("replica.txt", "w");
  while(fscanf(fptr1,"%s %s %s %02d:%02d %02d:%02d %d %d %d %d %d %d %d",  &a.train_name, &a.from_city, &a.to_city, &a.arrival.hour, &a.arrival.min, &a.departure.hour, &a.departure.min, &a.train_num, &a.cls.A3, &a.cls.A2, &a.cls.A1, &a.cls.SL, &a.cls.GN, &a.cls.CC)!=EOF){
      if(c!=a.train_num){
      fprintf(fptr2,"%s %s %s %02d:%02d %02d:%02d %d %d %d %d %d %d %d\n", a.train_name, a.from_city, a.to_city, a.arrival.hour, a.arrival.min, a.departure.hour, a.departure.min, a.train_num, a.cls.A3, a.cls.A2, a.cls.A1, a.cls.SL, a.cls.GN, a.cls.CC);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove("train_details.txt");
  rename("replica.txt", "train_details.txt");
  display_train_details();
}

void specific_train_details(int i_train_num){
  int i = 0;
  struct train t = return_train_details(i_train_num);
  if(t.train_num==10000){
    printf("Wrong train number");
  }else{
    system("CLS");
    printf("\n\t==========================================================");
    printf("\n\t| Train Name: %s\t Train Number: %d   \t\t |", t.train_name, t.train_num);
    printf("\n\t| From: %s\t\t To: %s \t\t\t |", t.from_city, t.to_city);
    printf("\n\t| Departure time: %02d:%02d\t Arrival time: %02d:%02d  \t\t |", t.departure.hour, t.departure.min, t.arrival.hour, t.arrival.min);
    printf("\n\t| Time of Journey : %02d hours %02d mins   \t\t\t |", t.departure.hour<t.arrival.hour?abs(t.departure.hour-t.arrival.hour):12-abs(t.departure.hour-t.arrival.hour), t.departure.min>t.arrival.min?60-abs(t.arrival.min-t.departure.min):abs(t.arrival.min-t.departure.min));
    printf("\n\t| Available Classes: %s%s%s%s%s%s \t\t\t\t |", t.cls.A3?"3A/":"",t.cls.A2?"2A/":"",t.cls.A1?"1A/":"",t.cls.SL?"SL/":"",t.cls.GN?"GN/":"",t.cls.CC?"CC":"");
    printf("\n\t|    _____                 . . . . . o o o o o           |");
    printf("\n\t|   __|[_]|__ ___________ _______    ____      o         |");
    printf("\n\t|  |[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][.       |");
    printf("\n\t| _|________|_[_________]_[________]_|__|________)<      |");
    printf("\n\t|   oo    oo 'oo      oo ' oo    oo 'oo 0000---oo\\_      |");
    printf("\n\t| ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |");
    printf("\n\t==========================================================");
  }
}
