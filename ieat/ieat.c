#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int flag() {
  char flag[48];
  FILE *file;
  file = fopen("flag", "r");
  if (file == NULL) {
    printf("Flag File is Missing. Problem is Misconfigured, please contact an Admin\n");
    exit(0);
  }

  fgets(flag, sizeof(flag), file);
  printf("%s", flag);
  return 0;
}


int main(int argc, char **argv){

  setvbuf(stdout, NULL, _IONBF, 0);
  
  FILE *file;
  char dessert[64];
  char tastystring[256];
  char dessert_input[64];
  
  memset(dessert, 0, sizeof(dessert));
  memset(tastystring, 0, sizeof(tastystring));
  memset(dessert_input, 0, sizeof(dessert_input));
  
  printf("Give me a string to chew?\n");
  
  fgets(tastystring, sizeof(tastystring), stdin);
  char *end = strchr(tastystring, '\n');
  if (end != NULL) {
    *end = '\x00';
  }

  strcat(tastystring, "....tastyyyyy, give me more");

  file = fopen("dessert", "r");
  if (file == NULL) {
    printf("dessert is Missing. Problem is Misconfigured, please contact an Admin\n");
    exit(0);
  }

  fgets(dessert, sizeof(dessert), file);

  puts(tastystring);

  fgets(dessert_input, sizeof(dessert_input), stdin);
  dessert_input[sizeof(dessert_input)] = '\x00';
  
  if (!strcmp(dessert_input, dessert)) {
    printf("That blew my heart away\n");
    flag();
  }
  else {
    printf("That was not tasty!\n");
  }
  return 0;
}

