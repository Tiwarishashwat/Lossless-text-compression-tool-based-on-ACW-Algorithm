void file()
{
  int ack=0;
  char ch;
  char hc;
  char fn;
  int i=0;
  int count=0;
  int j=0;
  int size=0;
  int c=0;
  int flag=0;
  int characters[127]={};
  int freq[127]={};
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
        for(int m=0;m<ack-1;m++)
        {
          printf("%c\t:",characters[m]);
          printf("%d\n",freq[m]);
        }
    }
}
