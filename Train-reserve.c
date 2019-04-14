#include<stdio.h>
#include "user.h"
#include "menu-user.h"
#include "menu-afterlogin.h"
#include "menu-adminlogin.h"
#include "train_details.h"


void start(){
  char a[100], b[20];
  int n = menu(0), d;
  if(n==0){
    user();
    system("CLS");
    start();
  }else if(n==1){
    strcpy(a, "users\\");
    strcpy(b, login());
    strcat(a, b);
    FILE *fptr;
    sprintf(a, "%s.txt", a);
    fptr = fopen(a,"a");
  }else{
    printf("Thank you for using");
  }
  if(n==1){
    int o, m;
    start:
    if(strcmp("admin", b)==0){
      system("CLS");
      o = menu_adminlogin(0);
      if(o==5){ /* **TODO** Replace if with switch case **/
        system("CLS");
        start();
      }else if(o==1){
        system("CLS");
        get_train_details();
        goto start;
      }else if(o==0){
        system("CLS");
        display_train_details();
        printf("\n\nPress any key(except down arrow) to go to Main Menu..");
        getch(); getch();
        goto start;
      }
    }else{
      system("CLS");
      m = menu_afterlogin(0);
      if(m==3){ /* **TODO** Replace if with switch case **/
        system("CLS");
        start();
      }else if(m==0){
        system("CLS");
        display_train_details();
        printf("\n\nPress any key(except down arrow) to go to Main Menu..");
        getch();
        goto start;
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
