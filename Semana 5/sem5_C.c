#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INPUT_STRING_SIZE 1001

int readInt(char *inputString);
void insultMatcher(int **insultData, char *insult);
char* Matcher(int index);

int main() {

  char inputString[INPUT_STRING_SIZE];
  char insult[INPUT_STRING_SIZE] = {0};
  int nDays = 0;

  nDays = readInt(inputString);

  int **insultData = (int**) calloc(36, sizeof(int*));
  for (int i = 0; i < 36; i++) insultData[i] = (int*) calloc(1, sizeof(int));

  for (int i = 0; i < nDays; i++) {

    if (fgets(inputString, (int)sizeof(inputString), stdin) != NULL) {}
    while(sscanf(inputString, "%s%[^\n]", insult, inputString) == 2) insultMatcher(insultData, insult);
    insultMatcher(insultData, insult);
    memset(inputString, 0, (int) sizeof(inputString));
  }

  //[Indice com menos aparicoes]
  int smallest = 0, index = 0;
  smallest = insultData[0][0];

  for (int i = 1; i < 36; i++) {
    if (insultData[i][0] < smallest) {
      smallest = insultData[i][0];
      index = i;
    }
  }

  //[OUTPUT]
  char *string;
  string = Matcher(index);
  puts(string);

  //[Dar free á memory]
  for(int i = 0; i < 36; i++) free(insultData[i]);
  free(insultData);

  return 0;
}

void insultMatcher(int **insultData, char *insult) {

  int n = 0;
  if (strcmp(insult, "Enguia") == 0 ) {n = insultData[0][0]; insultData[0][0] = n + 1;}
  if (strcmp(insult, "Lambidinho") == 0 ) {n = insultData[1][0]; insultData[1][0] = n + 1;}
  if (strcmp(insult, "Fanhoso") == 0 ) {n = insultData[2][0]; insultData[2][0] = n + 1;}
  if (strcmp(insult, "Cobaia") == 0 ) {n = insultData[3][0]; insultData[3][0] = n + 1;}
  if (strcmp(insult, "Centopeia") == 0 ) {n = insultData[4][0]; insultData[4][0] = n + 1;}
  if (strcmp(insult, "Formiga") == 0 ) {n = insultData[5][0]; insultData[5][0] = n + 1;}
  if (strcmp(insult, "Manco") == 0 ) {n = insultData[6][0]; insultData[6][0] = n + 1;}
  if (strcmp(insult, "Gorgulho") == 0 ) {n = insultData[7][0]; insultData[7][0] = n + 1;}
  if (strcmp(insult, "Tisico") == 0 ) {n = insultData[8][0]; insultData[8][0] = n + 1;}
  if (strcmp(insult, "Mongol") == 0 ) {n = insultData[9][0]; insultData[9][0] = n + 1;}
  if (strcmp(insult, "Javardo") == 0 ) {n = insultData[10][0]; insultData[10][0] = n + 1;}
  if (strcmp(insult, "Coxo") == 0 ) {n = insultData[11][0]; insultData[11][0] = n + 1;}
  if (strcmp(insult, "Patarata") == 0 ) {n = insultData[12][0]; insultData[12][0] = n + 1;}
  if (strcmp(insult, "Monxo") == 0 ) {n = insultData[13][0]; insultData[13][0] = n + 1;}
  if (strcmp(insult, "Tiradentes") == 0 ) {n = insultData[14][0]; insultData[14][0] = n + 1;}
  if (strcmp(insult, "Pirata") == 0 ) {n = insultData[15][0]; insultData[15][0] = n + 1;}
  if (strcmp(insult, "Sapo") == 0 ) {n = insultData[16][0]; insultData[16][0] = n + 1;}
  if (strcmp(insult, "Iconoclasta") == 0 ) {n = insultData[17][0]; insultData[17][0] = n + 1;}
  if (strcmp(insult, "Anao") == 0 ) {n = insultData[18][0]; insultData[18][0] = n + 1;}
  if (strcmp(insult, "Catatua") == 0 ) {n = insultData[19][0]; insultData[19][0] = n + 1;}
  if (strcmp(insult, "Fedorento") == 0 ) {n = insultData[20][0]; insultData[20][0] = n + 1;}
  if (strcmp(insult, "Perneta") == 0 ) {n = insultData[21][0]; insultData[21][0] = n + 1;}
  if (strcmp(insult, "Malota") == 0 ) {n = insultData[22][0]; insultData[22][0] = n + 1;}
  if (strcmp(insult, "Fuinha") == 0 ) {n = insultData[23][0]; insultData[23][0] = n + 1;}
  if (strcmp(insult, "Flibusteiro") == 0 ) {n = insultData[24][0]; insultData[24][0] = n + 1;}
  if (strcmp(insult, "Ogre") == 0 ) {n = insultData[25][0]; insultData[25][0] = n + 1;}
  if (strcmp(insult, "Marreco") == 0 ) {n = insultData[26][0]; insultData[26][0] = n + 1;}
  if (strcmp(insult, "Toupeira") == 0 ) {n = insultData[27][0]; insultData[27][0] = n + 1;}
  if (strcmp(insult, "Troll") == 0 ) {n = insultData[28][0]; insultData[28][0] = n + 1;}
  if (strcmp(insult, "Carrapato") == 0 ) {n = insultData[29][0]; insultData[29][0] = n + 1;}
  if (strcmp(insult, "Calhau") == 0 ) {n = insultData[30][0]; insultData[30][0] = n + 1;}
  if (strcmp(insult, "Burro") == 0 ) {n = insultData[31][0]; insultData[31][0] = n + 1;}
  if (strcmp(insult, "Hiena") == 0 ) {n = insultData[32][0]; insultData[32][0] = n + 1;}
  if (strcmp(insult, "Australopiteco") == 0 ) {n = insultData[33][0]; insultData[33][0] = n + 1;}
  if (strcmp(insult, "Piolho") == 0 ) {n = insultData[34][0]; insultData[34][0] = n + 1;}
  if (strcmp(insult, "Mabeco") == 0 ) {n = insultData[35][0]; insultData[35][0] = n + 1;}
  //if (strcmp(insult, "Enguia") == 0 ) insultData[36][0] = n + 1;
  //if (strcmp(insult, "Enguia") == 0 ) insultData[37][0] = n + 1;
  //if (strcmp(insult, "Enguia") == 0 ) insultData[38][0] = n + 1;
  //if (strcmp(insult, "Enguia") == 0 ) insultData[39][0] = n + 1;
}

char* Matcher(int index) {

  char *insult;
  switch (index) {
    case 0 : insult = "Enguia"; break;
    case 1 : insult = "Lambidinho"; break;
    case 2 : insult = "Fanhoso"; break;
    case 3 : insult = "Cobaia"; break;
    case 4 : insult = "Centopeia"; break;
    case 5 : insult = "Formiga"; break;
    case 6 : insult = "Manco"; break;
    case 7 : insult = "Gorgulho"; break;
    case 8 : insult = "Tisico"; break;
    case 9 : insult = "Mongol"; break;
    case 10 : insult = "Javardo"; break;
    case 11 : insult = "Coxo"; break;
    case 12 : insult = "Patarata"; break;
    case 13 : insult = "Monxo"; break;
    case 14 : insult = "Tiradentes"; break;
    case 15 : insult = "Pirata"; break;
    case 16 : insult = "Sapo"; break;
    case 17 : insult = "Iconoclasta"; break;
    case 18 : insult = "Anao"; break;
    case 19 : insult = "Catatua"; break;
    case 20 : insult = "Fedorento"; break;
    case 21 : insult = "Perneta"; break;
    case 22 : insult = "Malota"; break;
    case 23 : insult = "Fuinha"; break;
    case 24 : insult = "Flibusteiro"; break;
    case 25 : insult = "Ogre"; break;
    case 26 : insult = "Marreco"; break;
    case 27 : insult = "Toupeira"; break;
    case 28 : insult = "Troll"; break;
    case 29 : insult = "Carrapato"; break;
    case 30 : insult = "Calhau"; break;
    case 31 : insult = "Burro"; break;
    case 32 : insult = "Hiena"; break;
    case 33 : insult = "Australopiteco"; break;
    case 34 : insult = "Piolho"; break;
    case 35 : insult = "Mabeco"; break;
    //case 36 : insult = ""; break;
    //case 37 : insult = ""; break;
    //case 38 : insult = ""; break;
    //case 39 : insult = ""; break;
    default: insult = "Invalid insult"; break;
  }
  return insult;
}

int readInt(char *inputString) {

  int number = 0;

  if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) {}
  if (sscanf(inputString, "%d", &number) == 1) {}
  //number = (int) strtol(inputString, NULL, 10);
  memset(inputString, 0, (int) sizeof(inputString));

  return number;
}
