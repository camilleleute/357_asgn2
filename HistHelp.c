/* makes histogram */
#include <stdio.h>
#include "HistHelp.h"
#include <string.h>
int headerColumns = 0;

int stringFormatter(char *line, int linecnt){
	int columns = 0;
	int length = strlen(line);
	printf("line count: %d\n", linecnt);
	if (linecnt == 1) {
		headerColumns = removeWhiteSpace(line, length);
		printf("%s", line);
		printf("header columns: %d\n", headerColumns);
	} else {
		columns =  removeWhiteSpace(line, length);
		printf("%s", line);
		if (columns != headerColumns) {
			return 1;
		} else {
			if (columns == 0) {
			return 2;
			} else {
			return 0;	
			}
		}
	}
	return 0;
}

int removeWhiteSpace(char *str, int strleng) {
	int i, j;
	int commas = 0;
	for (i = 0, j = 0; i < strleng; i++) {
		if ((str[i] != ' ') && (str[i] != '\t')) {
		str[j++] = str[i];
		}
		if (str[i] == ','){
		commas++;
		}
		if (str[i] == '"') {
		return 0;
		}
	}
	str[j] = '\0';
	return commas;
}


