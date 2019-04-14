#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int menu_adminlogin(int);

int arrow_adminlogin(int n){
  int ch1, ch2;
  ch1 = getch();
  ch2 = 0;
  if (ch1 == 0xE0) { // a scroll key was pressed
    ch2 = getch();
  }
  switch(ch2){
    case 72:
      n = n-1;
      break;
    case 80:
      n = n + 1;
      break;
    case 0:
      break;
    default: printf("No valid statement, %d", ch2);
  }
  if(ch2!=0){
    if(n<0){
      n = 5;
    }
    if(n>5){
      n = 0;
    }
    system("CLS");
    menu_adminlogin(n);
  }else{
    return n;
  }
}

int menu_adminlogin(int n){
  if(n==0)
    printf("-> 1. View list of trains\n");
  else
    printf("   1. View list of trains\n");
  if(n==1)
    printf("-> 2. Add a New Train\n");
  else
    printf("   2. Add a New Train\n");
  if(n==2)
    printf("-> 3. Remove a Train\n");
  else
    printf("   3. Remove a Train\n");
  if(n==3)
    printf("-> 4. View specific train detils\n");
  else
    printf("   4. View specific train detils\n");
  if(n==4)
    printf("-> 5. Reserve a Ticket\n");
  else
    printf("   5. Reserve a Ticket\n");
  if(n==5)
    printf("-> 6. To go to main menu \n");
  else
    printf("   6. To go to main menu\n");

  arrow_adminlogin(n);
}
