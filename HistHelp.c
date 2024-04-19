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
	if (linecnt == 1) {
		headerColumns = removeWhiteSpace(line, length);
	} else {
		columns =  removeWhiteSpace(line, length);
		if (columns == 0) {
			return 2;
		} else {
			if (columns != headerColumns) {
			return 1;
			} else {
				int sum = parsingString(line);
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
		if ((str[i] == '"') || (str[i] == '\'') || (str[i] == '\"')) {
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
		int len = ptr - line;
		*ptr = '\0';
		for (i = 0; i < len; i++) {
			if ((!(isdigit(line[i]))) && (line[i] != '-')){
				flag = 1;
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
	ptr = strchr(line, '\0');
        val = strtol(line, &ptr - 1, 10);
	sum = sum + val;
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
	int i, rem;
	for (i = 1; i < 541; i++) {
		if (arr[i] > max){
			max = arr[i];
		}
	}
	rem = max %5;
        if (rem != 0){
		max += (5 - rem);
        }
	printf("y max: %d\n", max);
	return max;
}

int findXMin(int arr[]) {
	int i, minx, rem;
	for (i = 0; i <= 541; i++) {
        if (arr[i] != 0) {
	    minx = i - 45;
	    rem = minx % 5;
	    if (rem != 0) {
	    	minx = minx - (5 + rem)%5;
	    }
	    printf("x min: %d\n", minx);
	    return 2*minx;
 	}
    }
    return -1; 
}

int findXMax(int arr[]) {
	int i = 0;
	int maxx = 0; 
	int rem = 0;
	for (i = 540; i >= 0; i--) {
		if (arr[i] !=0) {
		maxx = i - 45;
		rem = maxx % 5;
		if (rem != 0){
			maxx = maxx + (5 - rem)%5;
		}
		printf("x max: %d\n", maxx);
		return 2*maxx;
		}
	}
	return -1;
}


void printHistogram(int arr[], int maxX, int maxY, int minX){
	int i = 0, j = 0, yAxis, check;
	int range = maxX - minX;
	for (i = 0; i <= maxY; i++) {
		if (((i-1)%5) == 0){
			yAxis = maxY - i + 1;
			if (yAxis > 99) {
				printf("%d T ", yAxis);
			} else {
				if (yAxis>9) {
					printf(" %d T ", yAxis);
				} else {
					printf("  %d T ", yAxis);
				}
			}
		} else {
			printf("    | ");}

		if (i == 0){
			check = 10000;
		} else {
			check = maxY - i + 1;
		}
		hashtagPrint(check, arr, minX, maxX);
		if (((i-1)%5) == 0){
                        yAxis = maxY - i + 1;
			printf(" T %d\n", yAxis);
		} else {
			printf(" |\n");
		}
	}
	printf("    +-");
	for (j = 0; j <= (range)/2; j++) {
		if (j%5 == 0){
			printf("|");
		}else{
			printf("-");
		}
	} 
	printf("-+\n");
	printf("  ");
	for (j = minX/2; j <= maxX/2; j++){
		if (j%5 == 0) {
			printf("  %3d", j*2);
		}
	}
	printf("\n");
}
void hashtagPrint(int num, int arr[], int minX, int maxX){
	int i = 0;
	int newX, newY;
	newX = minX/2 + 45;
	newY = maxX/2 + 45;
	for (i = (newX); i <= (newY); i++){
		if (num <= arr[i]) {
			printf("#");
		} else {
			printf(" ");
		}
	}
}
