static char adapt[127]={};
static int adapt_size=0;
static int ind_size[127]={};
void adaptive()
{
	FILE *fp,*fw ;
	int i=0;
	char ch;
	int s=0;
	int decNum=0;
	int rem=0;
	int f=0;
	fp = fopen("sample.txt", "r") ;
	fw = fopen("compressed.txt", "w") ;
	if ( fp == NULL)
	{
      printf( "File failed to open." ) ;
  }
    else
    {
    	fseek(fp, -3, SEEK_END);
    	s=ftell(fp);
    }
		while(s>=0)
		{
						ch=fgetc(fp);
						rem=ch - '0';
							  f = decNum;
								decNum += rem*pow(2,i);
								i++;
								if (decNum>127)
								{
								decNum=f+33;
								fprintf(fw, "%c",decNum);
								adapt[adapt_size]=decNum;
								ind_size[adapt_size++]=i;
								i=0;
								decNum=0;
								fseek(fp, +1, SEEK_CUR);
								s++;
								}
								else
								{
										if (s==0)
										{
										decNum=decNum+33;
										fprintf(fw, "%c",decNum);
										adapt[adapt_size]=decNum;
										ind_size[adapt_size]=i;
										}
								}
								fseek(fp, -2, SEEK_CUR);
								s--;
	  }
		printf("Successfully created file 'compressed.txt'");
		fclose(fp);
		fclose(fw);
}
