int arrowupdown(int n){
  int ch1, ch2, m=n;
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
      n = n+1;
      break;
    case 0:
      break;
    default: printf("No valid statement, %d", ch2);
  }
  if(ch2!=0){
  if(n<0){
    retu;
  }
  if(n>m){
    n = 0;
  }
  return n;
}else{
  return 10;
  }
}

int arrowleftright(int n){
  int ch1, ch2, m=n;
  ch1 = getch();
  ch2 = 0;
  if (ch1 == 0xE0) { // a scroll key was pressed
    ch2 = getch();
  }
  switch(ch2){
    case 75:
      n = n-1;
      break;
    case 77:
      n = n + 1;
      break;
    case 0:
      break;
    default: printf("No valid statement, %d", ch2);
  }
  if(ch2!=0){
  if(n<0){
    n = m;
  }
  if(n>m){
    n = 0;
  }
  system("CLS");
  }
}
