void display(int end)
{
  int count=0;
  int n=0;
  int diff=0;
  int one=1;
  int zero=0;
FILE *fptr;
   fptr = fopen("sample.txt","w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   for(int i=0;i<me;i++)
   {
   	for(int j=0;j<end;j++)
   	{
      if(ptr[i]==dataarr[j])
      {
   	  n=bitarr[j];
   	  while(n != 0)
   	    {
   	        // n = n/10
   	        n /= 10;
   	        ++count;
   	    }
   	    if(bitsize[j]==count)
   	    {
          fprintf(fptr,"%d",bitarr[j]);
   	    }
   	    else if(count==0)
   	    {
   	      diff=bitsize[j]-one;
   	      for(int k=0;k<diff;k++)
   	      {
   	        fprintf(fptr,"%d",zero);
   	      }
   	        fprintf(fptr,"%d",bitarr[j]);
   	    }
   	    else
   	    {
   	      diff=bitsize[j]-count;
   	      for(int k=0;k<diff;k++)
   	      {
   	        fprintf(fptr,"%d",zero);
   	      }
   	        fprintf(fptr,"%d",bitarr[j]);
   	    }
      }
   	    count=0;
   	}
  }
    fclose(fptr);
   }
