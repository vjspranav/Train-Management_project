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

  if(strcmp(inp_class, "1A")==0)
    n=23;
  if(strcmp(inp_class, "2A")==0)
    n=61;
  if(strcmp(inp_class, "3A")==0 || strcmp(inp_class, "GN")==0 || strcmp(inp_class, "SL")==0)
    n=81;
  if(strcmp(inp_class, "CC")==0)
    n=74;
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
    printf("\n\t\tAvailable Seats in class %s", inp_class);
    if(strcmp(inp_class, "3A")==0 || strcmp(inp_class, "GN")==0 || strcmp(inp_class, "SL")==0){
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
    }else if(strcmp(inp_class, "1A")==0){
      printf("\n\t     Lower: ");
        for(i=1; i<23; i++)
          if((i)%2 != 0)
            if(seats[i]!=0)
              printf("%d ", seats[i]);
      printf("\n\t     Upper: ");
        for(i=1; i<23; i++)
           if((i)%2 == 0)
            if(seats[i]!=0)
              printf("%d ", seats[i]);
    }else if(strcmp(inp_class, "CC")==0){
      printf("\n\tWindow: ");
        for(i=1; i<74; i++)
          if((i-5)%5 == 0 || i==1 || i==73  || (i-4)%5==0)
            if(seats[i]!=0)
              printf("%d ", seats[i]);
      printf("\n\tMiddle: ");
        for(i=1; i<74; i++)
          if((i-6)%5 ==0   && (i!=1 && i!=71))
            if(seats[i]!=0)
              printf("%d ", seats[i]);
      printf("\n\tSide: ");
        for(i=1; i<74; i++)
          if(((i-3)%5 ==0 || i==2 || i==71 || (i-7)%5==0)  && (i!=1 && i!=73))
            if(seats[i]!=0)
              printf("%d ", seats[i]);
    }



  }

void reserve_seat(char uname[]){
  char a[] = "users\\";
  FILE *fptr1, *unamef;
  fptr1 = fopen("train_details.txt","r");
  strcat(a, uname);
  sprintf(a, "%s.txt", a);
  unamef = fopen(a, "a");
  display_train_details();
  int train_num;
  struct date dt;
  printf("Please enter a train number from above list: ");
  scanf("%d", &train_num);
  system("CLS");
  struct train t = return_train_details(train_num);
  specific_train_details(t.train_num);

  }

void main(){
  reserve_seat("vjspranav");
}
