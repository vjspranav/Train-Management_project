#include<stdio.h>
#include<string.h>

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
  char classstr[50];
  struct cl cls;
}a;

struct train return_train_details(int train_num){
  struct train a1;
  FILE *fptr1;
  fptr1 = fopen("train_details.txt","r");
  while(fscanf(fptr1,"%s %s %s %s %d:%d %d:%d %d %d %d %d %d %d %d",  &a1.train_name, &a1.from_city, &a1.to_city, &a1.classstr, &a1.arrival.hour, &a1.arrival.min, &a1.departure.hour, &a1.departure.min, &a1.train_num, &a1.cls.A3, &a1.cls.A2, &a1.cls.A1, &a1.cls.SL, &a1.cls.GN, &a1.cls.CC)!=EOF)
    if(train_num==a1.train_num){
      fclose(fptr1);
      break;
  }
  return a1;
}

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
fclose(fptr);
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
  while(fscanf(fptr1,"%s %s %s %s %02d:%02d %02d:%02d %d",  &a.train_name, &a.from_city, &a.to_city, &a.classstr, &a.arrival.hour, &a.arrival.min, &a.departure.hour, &a.departure.min, &a.train_num)!=EOF){
      if(c!=a.train_num){
      fprintf(fptr2,"%s %s %s %s %02d:%02d %02d:%02d %d\n", a.train_name, a.from_city, a.to_city, a.classstr, a.arrival.hour, a.arrival.min, a.departure.hour, a.departure.min, a.train_num);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove("train_details.txt");
  perror("Following error occurred");
  rename("replica.txt", "train_details.txt");
  display_train_details();
}

void specific_train_details(int train_num){
  struct train t = return_train_details(train_num);
  printf("\n\tTrain Name: %s\t Train Number: %d", t.train_name, t.train_num);
  printf("\n\tFrom: %s\t\t To: %s", t.from_city, t.to_city);
  printf("\n\tDeparture time: %02d:%02d\t Arrival time: %02d:%02d", t.departure.hour, t.departure.min, t.arrival.hour, t.arrival.min);
  printf("\n\tTime of Journey : %02d hours %02d mins", t.departure.hour<t.arrival.hour?abs(t.departure.hour-t.arrival.hour):12-abs(t.departure.hour-t.arrival.hour), t.departure.min>t.arrival.min?60-abs(t.arrival.min-t.departure.min):abs(t.arrival.min-t.departure.min));

  printf("\n\t  _____                 . . . . . o o o o o");
  printf("\n\t __|[_]|__ ___________ _______    ____      o");
  printf("\n\t|[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][.");
  printf("\n\t_|________|_[_________]_[________]_|__|________)<");
  printf("\n\t oo    oo 'oo      oo ' oo    oo 'oo 0000---oo\_");
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

}
