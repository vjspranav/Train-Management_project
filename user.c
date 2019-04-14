#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void get_pass(){
  FILE *fptr;
  fptr = fopen("R:\\C\\User.txt","a");
  char str[20],c=' ';
  int i=0;
  printf("\nEnter the password [max length 10] : ");
  while (i<=9){
     str[i]=getch();
     c=str[i];
     if(c==13) break;
     else printf("*");
     i++;
  }
  str[i]='\0';
  i=0;
  printf("\n");
  fprintf(fptr,"%s",fname, lname, uname);
}

void user(){
  FILE *fptr;
  char fname[20], lname[20] uname[20], another = 'Y';
  fptr = fopen("R:\\C\\User.txt","a");
  printf("Enter First name: ");
  scanf("%s",&fname);
  printf("Enter Last name: ");
  scanf("%s",&lname);
  printf("\nEnter username: ");
  scanf("%s",&uname);
  fprintf(fptr,"%s %s %s",fname, lname, uname);
  get_pass();
  printf("want to enter another one(Y/N):");
  scanf(" %c", &another);

  fclose(fptr);
  printf("The Details have been saved");
}

int login(){
   char fname[20], defuname[20], uname[20], defpass[20], pass[20] ;
   FILE *fptr;

   if ((fptr = fopen("R:\\C\\User.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	fscanf(fptr,"%s %s %s", &fname, &uname, &pass);
  printf("\nEnter Username: ");
	scanf("%s", &defuname);
    char c=' ';
    int i=0;
    printf("\nEnter the password [max length 10] : ");
    while (i<=9){
       defpass[i]=getch();
       c=defpass[i];
       if(c==13) break;
       else printf("*");
       i++;
    }
    defpass[i]='\0';
    i=0;
    printf("\n");
//    printf("%s %s %s %s\n", uname, defuname, pass, defpass);
//    printf("%d, %d", strlen(defpass), strlen(pass));
//    printf("\n%d, %d", strcmp(defuname, uname), strcmp(defpass, pass));
  while(fscanf(fptr, "%s %s %s %s", &fname, &lname, &uname, &pass)!=EOF){
    if(strcmp(defuname, uname) ==0 && strcmp(defpass, pass) ==0)
		  printf("\nWelcome %s %s Hope you have a good time with our reservation system", fname, lname);
  }
}

void main(){
  user();
  // char fname[20], defuname[20], uname[20], defpass[20], pass[20];
  // FILE *fptr;
  // fptr =  fopen("R:\\C\\User.txt","r");
  // while(fscanf(fptr,"%s %s %s", &fname, &uname, &pass)!=EOF){
  //     printf("%s, %s, %s\n", fname, uname, pass);
  //   }
  //login();
}
