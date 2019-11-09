void write(int end)
{
  char ch;
  FILE *newt,*pptr;
  newt = fopen("checker.txt","w");
  pptr = fopen("sample.txt","r");
  if (newt == NULL || pptr == NULL)
  {
    printf("ERROR!");
    exit(1);
  }
  fprintf(newt,"%c",'a');
  while((ch=fgetc(pptr))!=EOF)
  {
   for(int j=0;j<end;j++)
   {
     if(ch==dataarr[j])
     {
       for(int k=0;k<bitsize[j];k++)
       {
       fprintf(newt,"%d",supportarr[j][k]);
       }
     }
   }
 }
     fclose(newt);
     fclose(pptr);
}
