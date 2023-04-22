#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *floop;
	char name[20], search[20], temp[200];
	printf("what file: ");
	scanf("%s", floop);
	printf("what are you searching for: ");
	scanf("%s", search);

	fp = fopen(floop, "r");
	if (fp == NULL){
		printf("wah wah no file how sad");
		return 1;
	}

	printf("%s found in: ", search);
	while (!EOF){
		fgets(temp, sizeof(temp), fp);
		if (strstr(temp, search) != NULL) {
			printf("%s", temp);			
		}	
	}
	fclose(fp);
	return 0;
}



