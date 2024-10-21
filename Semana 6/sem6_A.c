#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_STRING_SIZE 101

int readInt(char *inputString);
void readLineWithoutSpaces(char *string);
int sameLetters (char *name, char *anagram);

char inputString[INPUT_STRING_SIZE];

int main() {

  char name[INPUT_STRING_SIZE] = {0};
  char nameBackup[INPUT_STRING_SIZE] = {0};
  char anagram[INPUT_STRING_SIZE] = {0};

  int nCases = 0;
  nCases = readInt(inputString);

  int **results = (int**) calloc(nCases, sizeof(int*));

  for (int i = 0; i < nCases; i++) {

    int totalAnagrams = 0;
    totalAnagrams = readInt(inputString);

    results[i] = (int*) calloc((totalAnagrams + 1), sizeof(int));
    
    readLineWithoutSpaces(name);
    
    strcpy(nameBackup, name);
    
    //[LER ANAGRAMAS]
    for (int j = 0, k = 0; j < totalAnagrams; j++) {

      readLineWithoutSpaces(anagram);

      if (sameLetters(name, anagram)) {results[i][k] = j+1; k++;}
      
      memset(anagram, 0, (int) sizeof(anagram));
      strcpy(name, nameBackup);
    }
    memset(name, 0, (int) sizeof(name));
    memset(nameBackup, 0, (int) sizeof(name));
  }

  //[OUTPUT]
  for(int i = 0, j; i < nCases; i++) {

    j = 0;
    
    if (results[i][0] == 0) printf("-1\n");

    else {
      for(; results[i][j + 1] != 0; j++) printf("%d ",results[i][j]);
      printf("%d",results[i][j]);
      printf("\n");
    }
  }

  //[Dar free á memory]
  for(int i = 0; i < nCases; i++) {free(results[i]);}
  free(results);

  return 0;
}

int sameLetters (char *name, char *anagram) {

  int flag = 1;
  
  for(int i = 0; name[i] && flag; i++) {
    
    int hasLetter = 0;
    
    for(int j = 0; anagram[j] && !hasLetter; j++) {
      
      if (anagram[j] == name[i]) {
        
        anagram[j] ='\n';
        name[i] = '\n';
        hasLetter = 1;
      } 
    }
    flag = hasLetter;
  }
  return flag;
}

void readLineWithoutSpaces(char *string) {
  
  if (fgets(inputString, INPUT_STRING_SIZE, stdin) != NULL) {}
  int j = 0;
  for (int i = 0; inputString[i]; i++) if (!isspace(inputString[i])) string[j++] = inputString[i];
  string[j] = '\0';
  if (sscanf(string, "%s", string) == 1) {}
  memset(inputString, 0, (int) sizeof(inputString));
}

int readInt(char *inputString) {

  int number = 0;

  if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) {}
  if (sscanf(inputString, "%d", &number) == 1) {}
  //number = (int) strtol(inputString, NULL, 10);
  memset(inputString, 0, (int) sizeof(inputString));

  return number;
}
