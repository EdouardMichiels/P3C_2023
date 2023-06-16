#include <stdio.h>
#include <stdlib.h>

struct record {
    char* student;
    int n;
    int* points;
};

/*
* @pre n > 0 correspond au nombre d'etudiants dans la classe classe != NULL
* @post retourne le nombre de cours en échecs pour l'ensemble des étudiants de la classe
*/
int echecs(int n, struct record *classe){
    int fails = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < classe[i].n; j++){
            if(classe[i].points[j] < 10){
                fails++;
            }
        }
    }
    return fails;
}


int main(int argc, const char *argv[]){
    //Test pour des valeurs classiques
    struct record classe[4];
    classe[0].student = "Jean";
    classe[0].n = 3;
    classe[0].points = (int*)malloc(sizeof(int)*3);
    classe[0].points[0] = 12;
    classe[0].points[1] = 8;
    classe[0].points[2] = 15;

    classe[1].student = "Pierre";
    classe[1].n = 2;
    classe[1].points = (int*)malloc(sizeof(int)*2);
    classe[1].points[0] = 12;
    classe[1].points[1] = 8;

    classe[2].student = "Paul";
    classe[2].n = 4;
    classe[2].points = (int*)malloc(sizeof(int)*4);
    classe[2].points[0] = 12;
    classe[2].points[1] = 8;
    classe[2].points[2] = 15;
    classe[2].points[3] = 8;

    classe[3].student = "Jacques";
    classe[3].n = 1;
    classe[3].points = (int*)malloc(sizeof(int)*1);
    classe[3].points[0] = 12;
    printf("%d\n", echecs(3, classe));


    //Test pour des valeurs extremes
    struct record classe2[4];
    classe2[0].student = "Jean";
    classe2[0].n = 3;
    classe2[0].points = (int*)malloc(sizeof(int)*3);
    classe2[0].points[0] = 0;
    classe2[0].points[1] = 0;
    classe2[0].points[2] = 0;

    classe2[1].student = "Pierre";
    classe2[1].n = 2;
    classe2[1].points = (int*)malloc(sizeof(int)*2);
    classe2[1].points[0] = 0;
    classe2[1].points[1] = 0;

    classe2[2].student = "Paul";
    classe2[2].n = 4;
    classe2[2].points = (int*)malloc(sizeof(int)*4);
    classe2[2].points[0] = 0;
    classe2[2].points[1] = 0;
    classe2[2].points[2] = 0;
    classe2[2].points[3] = 0;

    classe2[3].student = "Jacques";
    classe2[3].n = 1;
    classe2[3].points = (int*)malloc(sizeof(int)*1);
    classe2[3].points[0] = 0;

    printf("%d\n", echecs(4, classe2));


    //Test pour un étudiant
    struct record classe3[1];
    classe3[0].student = "Jean";
    classe3[0].n = 3;
    classe3[0].points = (int*)malloc(sizeof(int)*3);
    classe3[0].points[0] = 12;
    classe3[0].points[1] = 12;
    classe3[0].points[2] = 15;

    printf("%d\n", echecs(1, classe3));
    return 0;
}