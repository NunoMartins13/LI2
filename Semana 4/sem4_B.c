#include <stdio.h>
#include <string.h>

char repeatedLetter(char* phrase);

int main() {

  int totalLines;
  char inputString[50], letters[1001];

  if (fgets(inputString, (int)sizeof(inputString), stdin) != NULL) { }
  if (sscanf(inputString, "%d", &totalLines) == 1) { }

  char repeatedCharacters[totalLines];

  for (int i = 0; i < totalLines; i++) {

    memset(letters, 0, (int)sizeof(letters));

    if (fgets(letters, (int)sizeof(letters), stdin) != NULL) letters[strcspn(letters, "\n")] = 0;

    repeatedCharacters[i] = repeatedLetter(letters);
  }
  for (int i = 0; i < totalLines; i++) printf("%c", repeatedCharacters[i]);
  
  printf("\n");

  return 0;
}

char repeatedLetter(char *phrase) {

    int phraseSize = strlen(phrase);
    char repeatedCharacter = '\0';

    for (int i = 0; i < phraseSize; i++) {

        for (int j = i + 1; j < phraseSize; j++) {

            if (phrase[i] == phrase[j]) repeatedCharacter = phrase[i];
        }
    }
    return repeatedCharacter;
}
