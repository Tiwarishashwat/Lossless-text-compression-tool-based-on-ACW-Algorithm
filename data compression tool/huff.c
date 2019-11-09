#include<stdio.h>
#include<math.h>
void main()
{
	FILE *fp,*fw ;
	int i=0;
	char ch;
	int s=0;
	int decNum=0;
	int rem=0;
	int f=0;
	fp = fopen("samorig.txt", "r") ;
	fw = fopen("compressed_huff.txt", "w") ;
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
								if (i==7)
								{
								decNum=decNum+33;
							  printf("%d:",decNum);
								printf("%c\n",decNum);
								fprintf(fw, "%c",decNum);
								i=0;
								decNum=0;
								}
								else
								{
										if (s==0)
										{
										decNum=decNum+33;
										printf("%d:",decNum);
										printf("%c",decNum);
										fprintf(fw, "%c",decNum);
										}
								}
								fseek(fp, -2, SEEK_CUR);
								s--;
	  }
		fclose(fp);
		fclose(fw);
}
