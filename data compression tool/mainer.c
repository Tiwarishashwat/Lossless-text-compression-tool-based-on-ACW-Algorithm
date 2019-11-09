#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "filee.h"
#include "deadapt.h"
#include "huffcomp.h"
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
void main()
{
  printf("\t\t\tWelcome to Decompressor\n");
  fetch();
  call_rev_adapt();
  call_decoder(data,freqq,nw_size);
  call_deleter("huff_net.txt");
}
