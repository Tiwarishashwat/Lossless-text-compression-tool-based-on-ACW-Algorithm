void create_head(int end)
{
FILE *fh;
fh=fopen("new__head.txt","a");
fprintf(fh,"\n");
for(int i=0;i<end;i++)
{
  fprintf(fh,"%c:",characters[i]);
  fprintf(fh,"%d ",freq[i]);
}
 fclose(fh);
}
