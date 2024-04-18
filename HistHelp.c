/* makes histogram */
#include <stdio.h>
#include "HistHelp.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int headerColumns = 0;

int stringFormatter(char *line, int linecnt, int freqArray[]){
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
				int sum = parsingString(line);
				printf("before counts\n");
				printf("got past *counts init\n");
				freqArr(sum, freqArray);		
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
		if ((str[i] == '"') || (str[i] == '\'')) {
		return 0;
		}
	}
	str[j] = '\0';
	return commas;
}

int parsingString(char *line) {
	char *ptr = strchr(line, ',');
	int sum = 0;
	int val = 0;
	while (ptr != NULL) {
		int i;
		int flag = 0;
		int len = &ptr - &line;
		*ptr = '\0';
		for (i = 0; i < len; i++) {
			if (!(isdigit(line[i]))) {
				val = 0;
			}
		}
		if (flag == 0) {
			val = strtol(line, &ptr - 1, 10);
		} else {
			val = 0;
		}
		sum = sum + val;
		line = ptr + 1;
		ptr = strchr(line, ',');
	}
	val = strtol(line, &ptr - 1, 10);
	sum = sum + val;
	printf("sum of row: %d\n", sum);
	return sum;
}


void freqArr(int num, int arr[]){
	num = num + 90;
	if ((num % 2) == 1){
		num++;
	}
	num = num/2;
	arr[num]++;
}

int findYMax(int arr[]){
	int max = arr[0];
	int i;
	for (i = 1; i <= 541; i++) {
		if (arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int findXMin(int arr[]) {
	int i;
	for (i = 0; i < 541; i++) {
        if (arr[i] != 0) {
            return i - 45;
        }
    }
    return -1; 
    }

int findXMax(int arr[]) {
	int i;
	for (i = 541; i >= 0; i--) {
		if (arr[i] !=0) {
		return i - 45;
		}
	}
	return -1;
}
