#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

//Function declarations
void func(char * pointer);
 
int main()
{
  printf("Hello World\n");
  char * pointer = NULL;
  func(pointer);
  printf("After func() pointer = %s\nLength: %lu\n", pointer, strlen(pointer));
  return 0;
}

void func(char * pointer){
   pointer = malloc(sizeof(char)*5);
   strcpy(pointer, "Pooja");
}
