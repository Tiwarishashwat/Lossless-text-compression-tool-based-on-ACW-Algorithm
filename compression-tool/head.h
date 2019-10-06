void create_head(int end)
{
FILE *fh;
fh=fopen("header.txt","w");
for(int i=0;i<=adapt_size;i++)
{
  fprintf(fh,"%c:",adapt[i]);
  fprintf(fh,"%d\n",ind_size[i]);
}
for(int i=0;i<end;i++)
{
  fprintf(fh,"%d:",bitarr[i]);
  fprintf(fh,"%d:",bitsize[i]);
  fprintf(fh,"%c\n",dataarr[i]);
}
 fclose(fh);
}
