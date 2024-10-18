#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int unrepeatedSetIndex(char *letters, int setSize);

int main() {

  int totalLines, setSize;
  char inputString[50], letters[1001];

  if (fgets(inputString, (int)sizeof(inputString), stdin) != NULL) { }
  
  totalLines = strtol(inputString, NULL, 10);

  int Positions[totalLines];

  for (int i = 0; i < totalLines; i++) {

    if (scanf("%d",&setSize) == 1) { }
    getchar();

    memset(letters, 0, (int)sizeof(letters));
    if (fgets(letters, (int)sizeof(letters), stdin) != NULL) { letters[strcspn(letters, "\n")] = 0; }

    Positions[i] = unrepeatedSetIndex(letters, setSize);
  }

  for (int i = 0; i < totalLines; i++) printf("%d\n", Positions[i]);

  return 0;
}

int unrepeatedSetIndex(char *letters, int setSize) {

  int setIndex = 0, letterSize = strlen(letters);

  for (int i = 0; i < letterSize; i++) {

    for (int j = i + 1; (j < (setSize + setIndex)) && (letters[j] != '\0'); j++) {

      if (letters[i] == letters[j]) { setIndex = i + 1; break; }
    }
    
    if ((setIndex + setSize) > letterSize) { setIndex = -1; break; }

    if (i == setSize + setIndex - 1) break;
  }
  return setIndex;
}
