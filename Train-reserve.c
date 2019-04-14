#include<stdio.h>
#include "user.h"
#include "menu-user.h"
#include "menu-afterlogin.h"
#include "menu-adminlogin.h"
#include "train_details.h"


void start(){
  char a[100], b[20];
  int n = menu(0), d;
  switch(n){
    case 0:
      user();
      system("CLS");
      start();
      break;
    case 1:
    strcpy(a, "users\\");
    strcpy(b, login());
    strcat(a, b);
    FILE *fptr;
    sprintf(a, "%s.txt", a);
    fptr = fopen(a,"a");
    break;
    default:  printf("Thank you for using");
  }
  if(n==1){
    int o, m;
    start:
    if(strcmp("admin", b)==0){
      system("CLS");
      o = menu_adminlogin(0);
      switch(o){
       case 5:
        system("CLS");
        start();
        break;
      case 1:
        system("CLS");
        get_train_details();
        goto start;
        break;
      case 0:
        system("CLS");
        display_train_details();
        printf("\n\nPress any key(except arrows) to go to Main Menu..");
        getch(); getch();
        goto start;
        break;
      }
    }else{
      system("CLS");
      m = menu_afterlogin(0);
      switch(m){
        case 3:
          system("CLS");
          start();
          break;
        case 0:
          system("CLS");
          display_train_details();
          printf("\n\nPress any key(except down arrow) to go to Main Menu..");
          getch();
          goto start;
          break;
      }
    }
  }
}



void main(){
   printf("\t\t=================================================\n");
   printf("\t\t|                                               |\n");
   printf("\t\t|        -----------------------------          |\n");
   printf("\t\t|        TRAIN TICKET RERVATION SYSTEM          |\n");
   printf("\t\t|        -----------------------------          |\n");
   printf("\t\t|                                               |\n");
   printf("\t\t|                                               |\n");
   printf("\t\t|                                               |\n");
   printf("\t\t|              BROUGHT TO YOU BY                |\n");
   printf("\t\t|           |  VJS-Santosh-Sourish  |           |\n");
   printf("\t\t|                                               |\n");
   printf("\t\t=================================================\n\n\n");
   printf(" \n Press any key to continue:");
   getch();
   system("cls");
   getch();
   start();
}
