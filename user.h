#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}

int check_username(char a[20]){
  int i = 1;
  static char fname[20], uname[20], lname[20], pass[20] ;
  FILE *fptr;
  fptr = fopen("users/User.txt","r");
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    if(strcmp(a, uname)==0){
      i = 0;
    }
  }
  return i;
}

char* get_pass(){
  static char str1[20], str2[20];
  char c=' ';
  int i=0, k=4;
  do{
    printf("\nEnter the password [max length 10] : ");
    while (i<=9){
       str1[i]=getch();
       c=str1[i];
       if(c==8){
         if(i>0){
         printf("\b \b");
         i--;
         }
      }else{
       if(c==13) break;
       else printf("*");
       i++;
    }
  }
  str1[i]='\0';
  i=0;
  printf("\nRe-enter the password [max length 10] : ");
  while (i<=9){
    str2[i]=getch();
    c=str2[i];
    if(c==8){
      if(i>0){
        i--;
        printf("\b \b");
      }
    }else{
    if(c==13) break;
    else printf("*");
    i++;
    }
  }
  str2[i]='\0';
  i=0;
  if(strcmp(str1, str2) != 0){
    printf("\n You have %d tries left", k-1);
    k--;
  }
}while(strcmp(str1, str2) != 0 && k>0);
  if(k!=0){
    printf("\nPasswords Matched\n");
    return str1;
  }else{
    printf("\nYou've entered incorrect 3 times please try again\n");
    return "tryagain";
  }
}

void user(){
  FILE *fptr;
  int i=3;
  char fname[20], lname[20], uname[20], inpass[20], another = 'Y';
  fptr = fopen("users/User.txt","a");
  printf("Enter First name: ");
  scanf("%s",&fname);
  printf("Enter Last name: ");
  scanf("%s",&lname);
  printf("\nEnter username: ");
  scanf("%s",&uname);
  while(check_username(uname)==0 && i>0){
    printf("Username already exists please try again, you have %d tries left: \n", i);
    printf("\nEnter username: ");
    scanf("%s",&uname);
    i--;
  }
  if(i!=-1){
    char pass[20];
    strcpy(pass, get_pass());
    if(strcmp(pass,"tryagain")==0){
      user();
    }else{
      fprintf(fptr,"%s %s %s %s\n",fname, lname, uname, pass);
      fclose(fptr);
      printf("The Details have been saved");
      delay(2);
    }
  }else{
    printf("You've entered an already exisiting username more than 3 times\nPlease Try again");
    delay(1);
    system("CLS");
    user();
  }
}

char* login(){
  static char fname[20], defuname[20], uname[20], lname[20], defpass[20], pass[20] ;
  FILE *fptr;
  int d, n=0;
  if ((fptr = fopen("users/User.txt","r")) == NULL){
    printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
  }
  printf("\nEnter Username: ");
	scanf("%s", &defuname);
  char c=' ';
  int i=0;
  printf("\nEnter the password [max length 10] : ");
  while (i<=9){
    int g = i;
    defpass[i]=getch();
    c=defpass[i];
    if(c==8){
     if(i>0){
     i--;
     printf("\b \b");
    }
    }else{
    if(c==13) break;
    else printf("*");
    i++;
    }
  }
  defpass[i]='\0';
  i=0;
  printf("\n");
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    if(strcmp(defuname, uname) ==0 && strcmp(defpass, pass) ==0){
	    printf("\nWelcome %s %s Hope you have a good time with our reservation system\n", fname, lname);
      for(d=0; d<=3; d++){
        delay(1);
        printf("\rRedirecting in %d", 3-d);
      }
      n=1;
      return defuname;
    }
  }
  if(n!=1){
    printf("Try again");
    for(d=0; d<=3; d++){
      delay(1);
      printf("\rRedirecting in %d", 3-d);
    }
    login();
  }
}
