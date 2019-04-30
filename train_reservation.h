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

int check_class(struct train t, char inp_class[]){
  if(strcmp("3A", inp_class)==0){
    if(!t.cls.A3)
      return 1;
  }else if(strcmp("2A", inp_class)==0){
    if(!t.cls.A2)
      return 1;
  }else if(strcmp("1A", inp_class)==0){
    if(!t.cls.A1)
      return 1;
  }else if(strcmp("SL", inp_class)==0){
    if(!t.cls.SL)
      return 1;
  }else if(strcmp("GN", inp_class)==0){
    if(!t.cls.GN)
      return 1;
  }else if(strcmp("CC", inp_class)==0){
    if(!t.cls.CC)
      return 1;
  }
}

int get_price_train(struct train t, char class[]){
  if(strcmp("3A", class)==0) return 930;
  else if(strcmp("2A", class)==0) return 1530;
  else if(strcmp("1A", class)==0) return 2230;
  else if(strcmp("GN", class)==0|| strcmp("SL", class)==0) return 330;
  else if(strcmp("CC", class)==0) return 500;
}

int is_seat_available(struct train t, char inp_class[], int inp_seat_no, struct date inp_date){
  char a[100], train_name[20],  fname[20], uname[20], lname[20], pass[20], class[4];
  int seat_no, train_num, k=0;
  FILE* fptr;
  fptr = fopen("users/User.txt", "r");
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    strcpy(a, "users\\");
    strcat(a, uname);
    FILE* user;
    sprintf(a, "%s.txt", a);
    user = fopen(a, "r");
      while(fscanf(user, "%s %d %d %s %d %d %d", &train_name, &seat_no, &train_num, &class, &doj.day, &doj.month, &doj.year)!=EOF){
        //printf("\n%d %d %d",strcmp(train_name, t.train_name), strcmp(class, inp_class), datecmp(inp_date, doj));
        if(strcmp(train_name, t.train_name)==0 && strcmp(class, inp_class)==0 && datecmp(inp_date, doj)==0){
          if(inp_seat_no==seat_no){
            k=1;
          }
        }
      }
    }
  if(k==1)
    return 1;
  else
    return 0;
}

long get_pnr(){
  FILE* fptr;
  fptr = fopen("users/User.txt", "r");
  char a[100], train_name[20],  fname[20], uname[20], lname[20], pass[20], class[4];
  int seat_no, train_num;
  long pnr = cur_date().tm_mday*10000000 + cur_date().tm_mon*100000 + cur_date().tm_year*10;
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    strcpy(a, "users\\");
    strcat(a, uname);
    FILE* user;
    sprintf(a, "%s.txt", a);
    user = fopen(a, "r");
    while(fscanf(user, "%s %d %d %s %d %d %d", &train_name, &seat_no, &train_num, &class, &doj.day, &doj.month, &doj.year)!=EOF)
      pnr++;
  }
  fclose(fptr);
  return pnr;
}

void reserve_seat(char uname[]){
  char a[] = "users\\", inp_class[20];
  struct date dob;
  FILE *fptr1, *unamef;
  fptr1 = fopen("train_details.txt","r");
  strcat(a, uname);
  sprintf(a, "%s.txt", a);
  unamef = fopen(a, "a");
  start:
  system("CLS");
  display_train_details_r();
  int train_num, seat_num, cnfrm;
  struct date dt;
  printf("Please enter a train number from above list: ");
  scanf("%d", &train_num);
  system("CLS");
  struct train t = return_train_details(train_num);
  specific_train_details(t.train_num);
  inpclass:
  printf("\nPlease Select the class in which you would like to book: ");
  scanf("%s", &inp_class);
  if(strcmp(inp_class, "3A")==0||strcmp(inp_class, "2A")==0||strcmp(inp_class, "1A")==0||strcmp(inp_class, "SL")==0||strcmp(inp_class, "GN")==0||strcmp(inp_class, "CC")==0){
      if(check_class(t, inp_class)==1){
        printf("The selected class is not available in this train please select a different class\n");
        goto inpclass;
      }
  }else{
    printf("Please enter a valid class\n");
    goto inpclass;
  }
  printf("\n");
  inpdate:
  printf("Please enter the date of travel in dd mm yyyy format(Please enter only numbers in the given format): ");
  scanf("%d %d %d", &dob.day, &dob.month, &dob.year);
  if(dob.year<cur_date().tm_year || dob.year==cur_date().tm_year && (dob.day<cur_date().tm_mday && (dob.month==cur_date().tm_mon)) || dob.year==cur_date().tm_year && dob.month<cur_date().tm_mon){
    printf("Please enter a valid upcoming date\n");
    goto inpdate;
  }
  display_available_seats(t.train_name, uname, inp_class, dob);
  inpseatno:
  printf("\nPlease enter a seat number from above: ");
  scanf("%d", &seat_num);
  if(is_seat_available(t, inp_class, seat_num, dob)==1){
    printf("\nYou've selected an already reserved seat\n");
    goto inpseatno;
  }
  int calc_price = get_price_train(t, inp_class)+50;
  printf("Your username: %s\nTrain name: %s\nClass: %s\tSeat No: %d\nTotal charge(inclusive of 50rs tax) = %d", uname, t.train_name, inp_class, seat_num, calc_price);
  printf("\nPlease enter 1 to confirm, 2 to rebook, 0 to cancel: ");
  scanf("%d", &cnfrm);
  switch(cnfrm){
    case 1:
      fprintf(unamef, "%s %d %d %s %d %d %d %d %d\n", t.train_name, seat_num, t.train_num, inp_class, dob.day, dob.month, dob.year, calc_price, get_pnr());
      printf("Your reservation is succesfull");
      break;
    case 2:
      goto start;
      break;
    case 0: break;
    default: printf("You've entered a wrong option defaulting to cancel");
  }
  fclose(fptr1);
  fclose(unamef);
}

int view_reserved_tickets(char inpt_uname[]){
  char a[50], train_name[20], class[4];
  int seat_no, train_num, k=0, pnr, inpt_pnr, charge;
  int i=1;
  strcpy(a, "users\\");
  strcat(a, inpt_uname);
  FILE* user;
  sprintf(a, "%s.txt", a);
  user = fopen(a, "r");
  while(fscanf(user, "%s %d %d %s %d %d %d %d %d", &train_name, &seat_no, &train_num, &class, &doj.day, &doj.month, &doj.year, &charge, &pnr)!=EOF){
    printf("%d. PNR: %d\t Booked on %02d/%02d/%02d\t Train name: %s\n", i, pnr, doj.day, doj.month, doj.year, train_name);
    i++;
  }
  fclose(user);
  printf("Please enter the PNR no of the ticket which you want to view: ");
  scanf("%d", &inpt_pnr);
  return inpt_pnr;
}

void view_ticket_details(int inpt_pnr){
  char a[100], train_name[20],  fname[20], uname[20], lname[20], pass[20], class[4];
  int seat_no, train_num, k=0, pnr, charge;
  FILE* fptr;
  fptr = fopen("users/User.txt", "r");
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    strcpy(a, "users\\");
    strcat(a, uname);
    FILE* user;
    sprintf(a, "%s.txt", a);
    user = fopen(a, "r");
    while(fscanf(user, "%s %d %d %s %d %d %d %d %d", &train_name, &seat_no, &train_num, &class, &doj.day, &doj.month, &doj.year, &charge, &pnr)!=EOF){
      if(inpt_pnr==pnr){
        k=1;
        break;
      }
    }
    if(k==1)
      break;
  }
  struct train tr = return_train_details(train_num);
  system("CLS");
  if(k==1)
    printf("Your pnr no is : %d\nWelcome %s %s\nYour train name is %s\nIt starts from %s at %02d:%02d\nYou will arrive at %s at %02d:%02d\nYou will be siting in seat no: %d in class %s\nYour ticket is confirmed\n\nTo view more details about the train Please select specific train details", pnr, lname, fname, tr.train_name, tr.from_city, tr.departure.hour, tr.departure.min, tr.to_city, tr.arrival.hour, tr.arrival.min, seat_no, class);
  else printf("pnr not found");
}
