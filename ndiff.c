#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* @pre -
* @post retourne le nombre de caractères différents dans la chaine pointée par str
  Exemples :
    - ndiff("ABA") retourne 2
    - ndiff("") retourne 0
    - ndiff(NULL) retourne 0
    - ndiff("AabBAb") retourne 4
*/
int ndiff(char* str){
    if(str == NULL || str == ""){
        return 0;
    }
    int n = 1;
    int i = 0;
    char* lettres = (char*)calloc(sizeof(str), sizeof(char));
    lettres[0] = str[0];
    while(str[i] != 0){
        int k = 0;
        int new = 0;
        while(lettres[k] != 0){
            if(lettres[k] == str[i]){
                new++;
            }
            k++;
        }
        if(new == 0){
            lettres[k] = str[i];
            n++;
        }
        i++;
    }
    free(lettres);
    return n;
}


int main(int argc, const char *argv[]){
    printf("%d\n", ndiff("ABA"));
    printf("%d\n", ndiff(""));
    printf("%d\n", ndiff(NULL));
    printf("%d\n", ndiff("AabBAb"));
    return 0;
}