#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "FileChar.h"//read characters from file
#include "huffman.h"//generate huffman codes
#include "BitToFile.h"//write bits to file
#include "adaptive.h"//adaptive character word length algorithm
#include "head.h"//creates the file header
void call_deleter(char *filer)
{
int status;
status = remove(filer);
if (status == 0)
  printf("Processing...\n");
else
{
  printf("Unable to delete the file\n");
}
}

int main()
{
printf("\n\t\t\tWELCOME TO FILE COMPRESSION TOOL\n");
sizecal();
file();
HuffmanCodes(characters, freq, ack-1);
write(ack-1);
adaptive();
reverse();
reverse_my_head();
create_head(ack-1);
call_deleter("compressed.txt");
call_deleter("checker.txt");
call_deleter("new_head.txt");
call_deleter("sample.txt");
printf("File Compression Success!");
return 0;
}
