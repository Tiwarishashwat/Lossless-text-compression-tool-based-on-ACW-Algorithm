void call_rev_adapt()
{
  char ch,ch1,ch2;
  int n;
  int k;
  FILE *f1,*f2,*f3;
  int skip=0;
  f3=fopen("new__head.txt","r");
  f1=fopen("comp__net.txt","r");
  f2=fopen("huff_net.txt","w");
  while ((ch=fgetc(f1))!=EOF)
  {
  ch1=fgetc(f3);
  int flag=ch1-'0';
  if(flag<7 && skip>0)
  {
    ch2=fgetc(f3);
    int x=ch2-'0';
    flag=(x*10)+flag;
  }
  skip++;
  n=ch;
  if (n<0)
  {
    n=256+n;
  }
  n=n-33;
  for(int i=flag-1; i>=0; i--)
  {
    k = n >> i;
    if (k & 1)
     fprintf(f2, "1");
    else
     fprintf(f2, "0");
   }
  }
  fclose(f1);
  fclose(f2);
  fclose(f3);
}
