static char characters[127]={};
static int freq[127]={};
static int ack=0;
static int origsize=0;
static char* ptr;
static int me=0;
void sizecal()
{
  char ch;
	int i=0, sum = 0;
  FILE *fp=fopen("sample.txt", "r");
  if (fp == NULL) {
        printf("File Not Found!\n");
    }
    fseek(fp, 0, SEEK_END);
    // calculating the size of the file
     origsize = ftell(fp);
     ptr = (char*)malloc(origsize * sizeof(char));
     fseek(fp,0,SEEK_SET);
     while ((ch=fgetc(fp))!=EOF)
     {
       ptr[i]=ch;
       i++;
     }
     me=i;
     fclose(fp);
}
void file()
{
  char ch;
  char hc;
  char fn;
  int i=0;
  int count=0;
  int j=0;
  int size=0;
  int c=0;
  int flag=0;
    // Declare the file pointer
    FILE *filePointer1 ;
    FILE *filePointer2 ;
    // Open the existing file using fopen()
    // in read mode using "r" attribute
    filePointer1 = fopen("sample.txt", "r") ;
    filePointer2 = fopen("sample.txt", "r") ;
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer1 == NULL || filePointer2 == NULL )
    {
        printf( "File failed to open." ) ;
    }
    else
    {
        // Read the dataToBeRead from the file
        // using fgetc() method
        while ((ch=fgetc(filePointer1))!=EOF)
        {
          count=0;
          for(c=0;c<127;c++)
          {
            if(characters[c]==ch)
            {
              flag=1;
              break;
            }
          }
           if(flag==0)
           {
               characters[j]=ch;
               ack++;
           }
          while((hc=fgetc(filePointer2))!=EOF)
          {
          if(ch==hc)
          {
            count++;
          }
          }
          i++;
          fseek(filePointer2,i, SEEK_SET);
          if(flag==0)
          {
          freq[j]=count;
          j++;
          }
          flag=0;
         }
        // Closing the file using fclose()
        fclose(filePointer1) ;
        fclose(filePointer2) ;
    }
}
