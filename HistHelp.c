/* makes histogram */
#include <stdio.h>
#include "HistHelp.h"
#include <string.h>

int stringFormatter(char *line){
	int length = strlen(line);
	removeWhiteSpace(line, length);
	printf("%s", line);
	return 0;	
}

void removeWhiteSpace(char *str, int strleng) {
	int i = 0;
	int j = 0;
	for (i = 0; i < strleng; i++) {
		if ((str[i] != ' ') && (str[i] != '\t')) {
		*(str+j) = str[i];
		j++;
		}
	}
	str[j] = '\0';
}

