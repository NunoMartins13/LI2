/*
Input
Line 1: 2
Line 2: 3 10 14 12
Line 3: 5 11 13 12 16 17

Output
Line 1: 3
LIne 2: 4
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int totalLines, totalHeights;

    if (scanf("%d", &totalLines) == 1) { }

    int visiblePerLine[totalLines];

    for (int i = 0; i < totalLines; i++) {

        if (scanf("%d", &totalHeights) == 1) { }
        
        int heights, maxHeight = 0, visibleDwarfs = 0;

        for (int j = 0; j < totalHeights; j++) { 
            
            if (scanf("%d", &heights) == 1) { }

            if (heights > maxHeight) { maxHeight = heights; visibleDwarfs++; }
        }
        visiblePerLine[i] = visibleDwarfs;
    }
    for (int x = 0; x < totalLines; x++)  printf("%d\n", visiblePerLine[x]);

    return 0;
}