/* Call histhelp to convert data into a histogram */

#include <stdio.h>
#include "HistHelp.h"


int main(void) {
    char line[2048];
    int lineCount = 0;
    int num = 0;
    while (fgets(line, sizeof(line), stdin) != NULL) {
	    lineCount++;
	    num = stringFormatter(line, lineCount);
	    if (num == 1) {
	    	    printf("Mismatched cells\n");
		    return 1;
	    } else {
	    	if (num == 2) {
            	printf("Unsupported quotes\n");
            	return 2;
	    	}	
    	}
     }
	return 0;
}
