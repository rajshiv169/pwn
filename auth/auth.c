#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define FLAGSIZE 64

int auth(){
	return 0;
}

void win() {
	char buf[FLAGSIZE];
	FILE *f = fopen("flag","r");
	if (f == NULL) {
		printf("Flag File is Missing. Problem is Misconfigured, please contact an Admin.\n");
		exit(0);
	}
	fgets(buf,FLAGSIZE,f);
	printf(buf);
}


int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	char user[64];
	char pass[32];
	int allow=auth();
	printf("Username: ");
	fgets(user, 64, stdin);
	printf("Password: ");
	fgets(pass, 0x64, stdin);
	if (allow)win();
	else printf("Sorry man\n");
	return 0;
}
