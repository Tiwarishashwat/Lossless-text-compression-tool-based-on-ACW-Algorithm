void adaptive()
{
	FILE *fp,*fw, *fr;
	int i=0;
	char ch;
	int s=0;
	int decNum=0;
	int rem=0;
	int f=0;
	fr = fopen("new_head.txt","w");
	fp = fopen("checker.txt", "r");
	fw = fopen("compressed.txt", "w");
	if ( fp == NULL || fw == NULL)
	{
      printf( "File failed to open.");
  }
    else
    {
    	fseek(fp, -1, SEEK_END);
    	s=ftell(fp);
			fseek(fp, -1, SEEK_END);
			fprintf(fw,"%c",32);
			fprintf(fr,"%c",32);
    }
		while((ch=fgetc(fp))!='a')
		{
						rem=ch - '0';
							  f = decNum;
								decNum += rem*pow(2,i);
								i++;
								if (decNum>127)
								 {
			 					  decNum=f+33;
								  i=i-1;
									fprintf(fw,"%c",decNum);
									fprintf(fr,"%d",i);
									i=0;
									decNum=0;
									fseek(fp, +1, SEEK_CUR);
									s++;
								 }
								else
								{
									fseek(fp, -2, SEEK_CUR);
									char ch_new=fgetc(fp);
									fseek(fp, +1, SEEK_CUR);
										if (ch_new=='a')
										{
											decNum=decNum+33;
											fprintf(fw, "%c",decNum);
											fprintf(fr,"%d",i);
										}
								}
								fseek(fp, -2, SEEK_CUR);
								s--;
	  }
		printf("Successfully created file 'compressed.txt'");
		fclose(fp);
		fclose(fw);
		fclose(fr);
}
void reverse()
{
  char ch;
  FILE *f1,*f2;
f1=fopen("compressed.txt","r");
f2=fopen("comp__net.txt","w");
if ( f1 == NULL || f2 == NULL )
{
    printf( "File failed to open." ) ;
}
else
{
    // Read the dataToBeRead from the file
    // using fgetc() method
    fseek(f1, -1, SEEK_END);
    while ((ch=fgetc(f1))!=' ')
    {
      fprintf(f2, "%c",ch);
      fseek(f1, -2, SEEK_CUR);
    }
  fclose(f1);
  fclose(f2);
}
}
void reverse_my_head()
{
  char ch;
  FILE *f1,*f2;
f1=fopen("new_head.txt","r");
f2=fopen("new__head.txt","w");
if ( f1 == NULL || f2 == NULL )
{
    printf( "File failed to open." ) ;
}
else
{
    // Read the dataToBeRead from the file
    // using fgetc() method
    fseek(f1, -1, SEEK_END);
    while ((ch=fgetc(f1))!=' ')
    {
      fprintf(f2, "%c",ch);
      fseek(f1, -2, SEEK_CUR);
    }
  fclose(f1);
  fclose(f2);
}
}
