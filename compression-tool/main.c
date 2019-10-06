#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "FileChar.h"//read characters from file
#include "huffman.h"//generate huffman codes
#include "BitToFile.h"//write bits to file
#include "adaptive.h"//adaptive character word length algorithm
#include "head.h"//creates the file header
int main()
{
sizecal();
file();
HuffmanCodes(characters, freq, ack-1);
display(ack-1);
adaptive();
create_head(ack-1);
return 0;
}
