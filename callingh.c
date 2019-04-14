#include<stdio.h>
#include "user.h"
#include "menu-user.h"
#include "menu-afterlogin.h"

void start(){
  char a[100];
  int n = menu(0), d;
  if(n==0){
    user();
    delay(2);
    system("CLS");
    start();
  }else if(n==1){
    strcpy(a, "users\\");
    strcat(a, login());
    puts(a);
    FILE *fptr;
    sprintf(a, "%s.txt", a);
    fptr = fopen(a,"a");
  }else{
    printf("Thank you for using");
  }
  if(n==1){
    system("CLS");
    int m = menu_afterlogin(0);
    if(m==3){
      system("CLS");
      start();
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
