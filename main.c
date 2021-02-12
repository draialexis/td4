#include <stdio.h>
#include <string.h>

//ex1
void afficheTab(int tab[5][7]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            printf("[%d] ", tab[i][j]);
        }
        printf("\n");
    }
}

void afficheTabF(float tab[4][5]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("[%f] ", tab[i][j]);
        }
        printf("\n");
    }
}

//ex2
int sommeTab2D(int tab[][10], int l) {
    int somme = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < 10; ++j) {
            somme = somme + tab[i][j];
        }
    }
    return somme;
}

//ex3
void plusGrandDesDeuxV1(float t1[][5], float t2[][5], float t3[][5], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            t3[i][j] = t2[i][j] > t1[i][j] ? t2[i][j] : t1[i][j];
        }
    }
}
void plusGrandDesDeuxV2(float t1[][5], float t2[][5], float t3[][5], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            t3[i][j] = t1[i][j] + t2[i][j];
        }
    }
}

int main() {
    //ex1
    //a)
    int tab1[5][7] = {{0}};
    afficheTab(tab1);
    tab1[1][3] = 5;
    tab1[2][1] = 18;
    tab1[2][5] = 10;
    tab1[0][3] = -9;
    tab1[0][4] = 2;
    int i, j, somme;
    somme = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            somme = somme + tab1[i][j];
        }
        tab1[i][6] = somme;
    }

    afficheTab(tab1);

    //b)
    char phrase[100];
    char fruit[] = "pomme";
    char legume[] = "chou";
    if (strcmp(fruit, legume) < 0) {
        strcpy(phrase, fruit);
        strcat(phrase, " ");
        strcat(phrase, legume);
    } else {
        strcpy(phrase, legume);
        strcat(phrase, " ");
        strcat(phrase, fruit);
    }
    int n = (int) strlen(phrase);
    sprintf(phrase, "%s (long. %d)",
            phrase, n);
    printf("%s\n", phrase);

    //ex2
    int tab2[][10] = {
            {1, 2, 5, 6, 1, 3, 7, 8, 1, 2},
            {1, 2, 4, 6, 1, 3, 7, 8, 1, 2},
            {1, 2, 5, 6, 1, 3, 7, 8, 1, 2},
            {1, 2, 5, 6, 1, 3, 7, 8, 1, 2}
    };

    printf("somme 2d = %d\n", sommeTab2D(tab2, 4));

    //ex3
    float tab3[][5] = {
            {1, 2,  5, 6,  21},
            {1, 1,  4, 6,  1},
            {1, 2,  5, -5, 1},
            {1, 23, 5, 6,  0}
    };
    float tab4[][5] = {
            {0, 2, 5,   6, 1},
            {1, 1, 4.1, 6, 1},
            {1, 2, 5,   5, 10},
            {1, 2, 51,  6, 0}
    };
    float tab5[4][5] = {{0}};
    plusGrandDesDeuxV1(tab3, tab4, tab5, 4);
    afficheTabF(tab5);
    printf("\n");
    plusGrandDesDeuxV2(tab3, tab4, tab5, 4);
    afficheTabF(tab5);

    return 0;
}