/* makes histogram */
#include <stdio.h>
#include "HistHelp.h"
#include <string.h>
#include <stdlib.h>
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
		if (columns == 0) {
			return 2;
		} else {
			if (columns != headerColumns) {
			return 1;
			} else {
				parsingString(line);
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

void parsingString(char *line) {
	char *ptr = strchr(line, ',');
	int sum = 0;
	int val = 0;
	printf("sum before while: %d\n", sum);
	while (ptr != NULL) {
		*ptr = '\0';
		val = strtol(line, ptr - 1, 10);
		printf("val: %d\n", val);
		printf("sum before getting sum: %d\n", sum);
		sum = sum + val;
		printf("sum: %d\n", sum);
		line = ptr + 1;
		ptr = strchr(line, ',');
	}
	val = strtol(line, ptr - 1, 10);
	sum = sum + val;
	printf("sum of row: %d\n", sum);
}

