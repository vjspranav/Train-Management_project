#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int menu(int n);

// int re(int n){
//   return n;
// }

int arrow(int n){
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
      n = 2;
    }
    if(n>2){
      n = 0;
    }
    system("CLS");
    menu(n);
  }else{
    return n;
  }
}

int menu(int n){
  if(n==0)
    printf("-> 1. To Create user\n");
  else
    printf("   1. To Create user\n");
  if(n==1)
    printf("-> 2. To Login\n");
  else
    printf("   2. To Login\n");
  if(n==2)
    printf("-> 3. To Exit \n");
  else
    printf("   3. To Exit\n");
  arrow(n);
}
