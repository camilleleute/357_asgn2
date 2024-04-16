/* Call histhelp to convert data into a histogram */

#include <stdio.h>
#include "HistHelp.h"


int main(void) {
    char line[2048];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        stringFormatter(line);
    }
    /*while (scanf("%s", line) != EOF) {
	printf("%s\n", line);    
    }*/

    return 0;
}

