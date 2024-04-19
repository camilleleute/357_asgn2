/* Call histhelp to convert data into a histogram */

#include <stdio.h>
#include "HistHelp.h"
#include <string.h>

int main(void) {
	char line[2048];
	int lineCount = 0;
	int num = 0;
	int xMax = 0;
	int yMax = 0;
	int xMin = 0;
	int freqArray[541] = {0};
	memset(freqArray, 0, sizeof(freqArray));
	while (fgets(line, sizeof(line), stdin) != NULL) {
		lineCount++;
		num = stringFormatter(line, lineCount, freqArray);
		if (num == 1) {
			printf("./hist: Mismatched cells\n");
			return 1;
		} else {
			if (num == 2) {
            		printf("./hist: Unsupported quotes\n");
            		return 2;
	    		}	
    		}	
	}
	xMax = findXMax(freqArray);
	xMin = findXMin(freqArray);
	yMax = findYMax(freqArray);
	printf("x max: %d\n", xMax);
	printf("x min: %d\n", xMin);
	printf("y max: %d\n", yMax);
	printHistogram(freqArray, xMax, yMax, xMin);
	return 0;
}
