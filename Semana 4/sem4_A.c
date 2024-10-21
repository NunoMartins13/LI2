#include <stdio.h>
#include <string.h>

int main() {

  int totalLyrics;
  char inputString[50], lyrics[1001];

  if (fgets(inputString, (int)sizeof(inputString), stdin) != NULL) { }
  if (sscanf(inputString, "%d", &totalLyrics) == 1) { }

  int totalInterchangedWords[totalLyrics];

  for (int i = 0; i < totalLyrics; i++) {

    int flag = 1, wordCounter = 0;

    memset(lyrics, 0, (int)sizeof(lyrics));

    if (fgets(lyrics, (int)sizeof(lyrics), stdin) != NULL) lyrics[strcspn(lyrics, "\n")] = 0;

    for (int j = 0; lyrics[j + 1] != '\0'; j++) {

      if ((lyrics[j] == 'A' || lyrics[j] == 'E' || lyrics[j] == 'I' ||
           lyrics[j] == 'O' || lyrics[j] == 'U' || lyrics[j] == 'Y') &&
          (lyrics[j + 1] == 'A' || lyrics[j + 1] == 'E' ||
           lyrics[j + 1] == 'I' || lyrics[j + 1] == 'O' ||
           lyrics[j + 1] == 'U' || lyrics[j + 1] == 'Y')) { flag = 0; }

      if ((lyrics[j] != 'A' && lyrics[j] != 'E' && lyrics[j] != 'I' &&
                lyrics[j] != 'O' && lyrics[j] != 'U' && lyrics[j] != 'Y') &&
               (lyrics[j + 1] != 'A' && lyrics[j + 1] != 'E' &&
                lyrics[j + 1] != 'I' && lyrics[j + 1] != 'O' &&
                lyrics[j + 1] != 'U' && lyrics[j + 1] != 'Y') &&
               lyrics[j] != ' ' && lyrics[j+1] != ' ') { flag = 0; }

      if ((lyrics[j] == ' ' && flag == 1) || (lyrics[j + 2] == '\0' && flag == 1)) wordCounter++;

      if (lyrics[j] == ' ' && flag == 0) flag = 1;
      
    }
    totalInterchangedWords[i] = wordCounter;
  }

  for (int i = 0; i < totalLyrics; i++) printf("%d\n", totalInterchangedWords[i]);

  return 0;
}
