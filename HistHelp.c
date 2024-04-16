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
	int i, j;
	for (i = 0, j = 0; i < strleng; i++) {
		if ((str[i] != ' ') && (str[i] != '\t')) {
		str[j++] = str[i];
		
		}
	}
	str[j] = '\0';
}

