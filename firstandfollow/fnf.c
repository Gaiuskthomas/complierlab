#include <stdio.h>
#include <string.h>
#include <ctype.h>

void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);

int count = 8;
int n = 0;
int m = 0;
int k;
int e;

char calc_first[10][100];
char calc_follow[10][100];
char production[10][10];
char f[10];
char first[10];
char ck;

int main(void) {
    int i;
    int choice;
    char c;
    int jm = 0;
    int km = 0;

    strcpy(production[0], "E=TR");
    strcpy(production[1], "R=+TR");
    strcpy(production[2], "R=e");
    strcpy(production[3], "T=FY");
    strcpy(production[4], "Y=*FY");
    strcpy(production[5], "Y=e");
    strcpy(production[6], "F=(E)");
    strcpy(production[7], "F=i");

    for (k = 0; k < count; k++) {
        for (int kay = 0; kay < 100; kay++) {
            calc_first[k][kay] = '!';
        }
    }

    char done[count];
    int ptr = -1;
    int point1 = 0;

    for (k = 0; k < count; k++) {
        c = production[k][0];

        int point2 = 0;
        int xxx = 0;

        for (int kay = 0; kay <= ptr; kay++) {
            if (c == done[kay]) {
                xxx = 1;
                break;
            }
        }

        if (xxx) {
            continue;
        }

        findfirst(c, 0, 0);

        ptr++;
        done[ptr] = c;

        printf("First(%c) = { ", c);
        calc_first[point1][point2++] = c;

        for (i = jm; i < n; i++) {
            int chk = 0;

            for (int lark = 0; lark < point2; lark++) {
                if (first[i] == calc_first[point1][lark]) {
                    chk = 1;
                    break;
                }
            }

            if (!chk) {
                printf("%c, ", first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }

        printf("}\n");
        jm = n;
        point1++;
    }

    printf("\n");

    char donee[count];
    ptr = -1;
    point1 = 0;
    int land = 0;

    for (e = 0; e < count; e++) {
        for (int kay = 0; kay < 100; kay++) {
            calc_follow[e][kay] = '!';
        }
    }

    for (e = 0; e < count; e++) {
        ck = production[e][0];

        int point2 = 0;
        int xxx = 0;

        for (int kay = 0; kay <= ptr; kay++) {
            if (ck == donee[kay]) {
                xxx = 1;
                break;
            }
        }

        if (xxx) {
            continue;
        }

        land++;
        follow(ck);

        ptr++;
        donee[ptr] = ck;

        printf("Follow(%c) = { ", ck);
        calc_follow[point1][point2++] = ck;

        for (i = km; i < m; i++) {
            int chk = 0;

            for (int lark = 0; lark < point2; lark++) {
                if (f[i] == calc_follow[point1][lark]) {
                    chk = 1;
                    break;
                }
            }

            if (!chk) {
                printf("%c, ", f[i]);
                calc_follow[point1][point2++] = f[i];
            }
        }

        printf("}\n");
        km = m;
        point1++;
    }

    return 0;
}

void follow(char c) {
    int i;
    int j;

    if (production[0][0] == c) {
        f[m++] = '$';
    }

    for (i = 0; i < count; i++) {
        for (j = 2; j < strlen(production[i]); j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0') {
                    followfirst(production[i][j + 1], i, j + 2);
                }

                if (production[i][j + 1] == '\0' &&
                    c != production[i][0]) {
                    follow(production[i][0]);
                }
            }
        }
    }
}

void findfirst(char c, int q1, int q2) {
    int j;

    if (!isupper((unsigned char)c)) {
        first[n++] = c;
        return;
    }

    for (j = 0; j < count; j++) {
        if (production[j][0] == c) {
            if (production[j][2] == 'e') {
                if (production[q1][q2] == '\0') {
                    first[n++] = 'e';
                } else if (production[q1][q2] != '\0' &&
                           (q1 != 0 || q2 != 0)) {
                    findfirst(production[q1][q2], q1, q2 + 1);
                } else {
                    first[n++] = 'e';
                }
            } else if (!isupper((unsigned char)production[j][2])) {
                first[n++] = production[j][2];
            } else {
                findfirst(production[j][2], j, 3);
            }
        }
    }
}

void followfirst(char c, int c1, int c2) {
    if (!isupper((unsigned char)c)) {
        f[m++] = c;
    } else {
        int i;
        int j = 1;

        for (i = 0; i < count; i++) {
            if (calc_first[i][0] == c) {
                break;
            }
        }

        while (calc_first[i][j] != '!') {
            if (calc_first[i][j] != 'e') {
                f[m++] = calc_first[i][j];
            } else {
                if (production[c1][c2] == '\0') {
                    follow(production[c1][0]);
                } else {
                    followfirst(production[c1][c2], c1, c2 + 1);
                }
            }

            j++;
        }
    }
}
