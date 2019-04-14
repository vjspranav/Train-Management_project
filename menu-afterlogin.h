#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int menu_afterlogin(int n);

// int re(int n){
//   return n;
// }

int arrow_afterlogin(int n){
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
      n = 3;
    }
    if(n>3){
      n = 0;
    }
    system("CLS");
    menu_afterlogin(n);
  }else{
    return n;
  }
}

int menu_afterlogin(int n){
  if(n==0)
    printf("-> 1. View list of trains\n");
  else
    printf("   1. View list of trains\n");
  if(n==1)
    printf("-> 2. View specific train detils\n");
  else
    printf("   2. View specific train detils\n");
  if(n==2)
    printf("-> 3. Reserve a Ticket\n");
  else
    printf("   3. Reserve a Ticket\n");
  if(n==3)
    printf("-> 4. To return back to main menu \n");
  else
    printf("   4. To return back to main menu\n");
  arrow_afterlogin(n);
}
