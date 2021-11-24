#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char** initialize_matrix(int len) {
    char** mat = (char**)malloc(sizeof(char*) * len);
    int i;
    i = 0;
    label:
    mat[i] = (char*)malloc(sizeof(char) * len);
    i++;
    if (i < len)
        goto label;
    return mat;
}
void fill_matrix(char** mat,char ch ,int start, int end) {
    int row,col;
    row = start;
    label:
    col = start;
    label2:
    mat[row][col] = ch;
    col++;
    if (col < end)
        goto label2;
    row++;
    if (row < end)
        goto label;
}
void print(char **mat, int len) {
    int i, r;
    r = 0;
label:
    i = 0;
    label2:
        putchar(mat[r][i]);
        i++;
    if (i < len)
        goto label2;
    putchar('\n');
    r++;
    if (r < len)
        goto label;
}
void run(char** mat,char *s,int len) {
    int i, r,index=0;
    i = 0;
    r = len;
    label:
    if (i < r) {
        fill_matrix(mat, s[index], i, r);
        index++;
        i++;
        r--;
        goto label;
    }
}
void main(){
    char **mat;
    char** mat2;
    char s[20];
    int len,len2;
    puts("Enter a string");
    gets(s);
    len = strlen(s) * 2 - 1;
    len2 = strlen(s) * 2;
    mat = initialize_matrix(len);
    mat2 = initialize_matrix(len2);
    run(mat, s, len);
    run(mat2, s, len2);
    print(mat, len);
    putchar('\n');
    print(mat2, len2);
    system("pause");
}

