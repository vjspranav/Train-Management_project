#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "train_details.h"

struct tm cur_date(){
    time_t now;
    time(&now);
    struct tm local = *localtime(&now);
//    int cur_day = local.tm_mday;        	// get day of month (1 to 31)
      local.tm_mon++ ;   	// get month of year (0 to 11)
      local.tm_year += 1900; // get year since 1990
      return local;
}

struct date{
  int day, month, year;
}doj; //date of journey


int datecmp(struct date a, struct date b){
  if(a.day==b.day && a.month==b.month && a.year==b.year)
    return 0;
  else return 1;
}

void display_available_seats(char g_train_name[], char b[], char inp_class[], struct date inp_date){
  int i, n, seats[100];
  if(strcmp(inp_class, "2A")==0)
    n=61;
  if(strcmp(inp_class, "3A")==0 || strcmp(inp_class, "GN")==0)
    n=81;
  for(i=1; i<n; i++){
   seats[i] = i;
 }
  char a[100], train_name[20],  fname[20], uname[20], lname[20], pass[20], class[4];
  int seat_no, train_num;
  FILE* fptr;
  fptr = fopen("users/User.txt", "r");
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    strcpy(a, "users\\");
    strcat(a, uname);
    FILE* user;
    sprintf(a, "%s.txt", a);
    user = fopen(a, "r");
      while(fscanf(user, "%s %d %d %s %d %d %d", &train_name, &seat_no, &train_num, &class, &doj.day, &doj.month, &doj.year)!=EOF){
//        printf("\n %s %s %d %d", class, inp_class, strcmp(class, inp_class), seat_no);
        if(strcmp(train_name, g_train_name)==0 && strcmp(class, inp_class)==0 && datecmp(inp_date, doj)==0){
          for(i=1; i<n; i++){
            if(seats[i]==seat_no)
              seats[i] = 0;
          }
        }
      }
      fclose(user);
    }
    printf("\t\tAvailable Seats in class %s", inp_class);
    if(strcmp(inp_class, "3A")==0 || strcmp(inp_class, "GN")==0){
      printf("\n\tSide Lower: ");
      for(i=1; i<81; i++)
        if((i-7)%8==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\tSide Upper: ");
      for(i=1; i<81; i++)
        if((i-8)%8==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\t     Lower: ");
      for(i=1; i<81; i++)
        if((i-1)%8 == 0 || (i-4)%8==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\t    Middle: ");
      for(i=1; i<81; i++)
        if((i-2)%8 == 0 || (i-5)%8==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\t     Upper: ");
      for(i=1; i<81; i++)
        if((i-3)%8 == 0 || (i-6)%8==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
    }else if(strcmp(inp_class, "2A")==0){
      printf("\n\tSide Lower: ");
      for(i=1; i<61; i++)
        if((i-5)%6==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\tSide Upper: ");
      for(i=1; i<61; i++)
        if((i-6)%6==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\t     Lower: ");
      for(i=1; i<61; i++)
        if((i-1)%6 == 0 || (i-3)%6==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
      printf("\n\t     Upper: ");
      for(i=1; i<61; i++)
        if((i-2)%6 == 0 || (i-4)%6==0)
          if(seats[i]!=0)
            printf("%d ", seats[i]);
    }
  }

void reserve_seat(){
  FILE *fptr1;
  fptr1 = fopen("train_details.txt","r");
  display_train_details();
  int train_num;
  char uname[20], class[10];
  struct date dt;
  struct train a1;
  printf("Please enter a train number from above list: ");
  scanf("%d", &train_num);
  system("CLS");
  while(fscanf(fptr1,"%s %s %s %s %d:%d %d:%d %d",  &a1.train_name, &a1.from_city, &a1.to_city, &a1.classstr, &a1.arrival.hour, &a1.arrival.min, &a1.departure.hour, &a1.departure.min, &a1.train_num)!=EOF)
    if(train_num==a1.train_num){
      fclose(fptr1);
      break;
    }


}

void main(){
  struct date a = {23, 10, 2019};
  // display_available_seats("Shatabdi", "Sourish", "3A", a);
  //printf("Date is : %02d/%02d/%d\n", cur_date().tm_mday, cur_date().tm_mon, cur_date().tm_year);
 specific_train_details(18052);
 specific_train_details(12052);
 specific_train_details(15063);
 specific_train_details(15064);

}
