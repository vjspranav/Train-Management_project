#include<stdio.h> /* Standard functions quite necesarry*/
#include "user.h" /* Has all the functions for creating a user and logging in a user */
#include "menu-user.h" /* Has functions for creating a menu before login */
#include "menu-afterlogin.h" /* Same as above but after a user logs in*/
#include "menu-adminlogin.h" /* For admin*/
#include "train_details.h" /* Has the fucnctions that shows the details of a train, takes in new train details and removes already added trains */


void start(){
  char a[100], b[20];
  int n = menu(0), d, inp_tr_num;
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
        case 3:
          system("CLS");
          display_train_details();
          printf("Please enter a train number: ");
          scanf("%d", &inp_tr_num);
          specific_train_details(inp_tr_num);
          printf("\n\nPress any key to go to Main Menu..");
          getch();
        goto start;
        case 2:
          system("CLS");
          remove_train_details();
          goto start;
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
          getch();
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
        case 1:
          system("CLS");
          display_train_details();
          printf("Please enter a train number: ");
          scanf("%d", &inp_tr_num);
          specific_train_details(inp_tr_num);
          printf("\n\nPress any key to go to Main Menu..");
          getch();
          goto start;
        case 0:
          system("CLS");
          display_train_details();
          printf("\n\nPress any key to go to Main Menu..");
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
  printf(" \n Press any key(except arrows) to continue:");
  getch();
  system("cls");
  start();
}
