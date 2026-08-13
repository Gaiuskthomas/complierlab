
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]){
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    for(int i = 0; i < 32; i++){
        if(strcmp(buffer, keywords[i]) == 0){
            return 1;
        }
    }

    return 0;
}

int main(){
    FILE *fp;
    int ch;                     // Fixed: should be int
    char buffer[100];
    int j = 0;

    char operators[] = "+-*/%=<>!&|^~";
    char special[] = "(){}[];,.:?";

    fp = fopen("program.txt", "r");

    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }else{
        printf("File opened!\n");
    }                                                                   

    while((ch = fgetc(fp)) != EOF){

        // Identifier
        if(isalpha(ch) || ch == '_'){
            buffer[j++] = ch;

            while((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_')){
                if(j < sizeof(buffer) - 1)
                    buffer[j++] = ch;
            }

            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer)){
                printf("%s is a keyword\n", buffer);
            }else{
                printf("%s is an identifier\n", buffer);
            }

            if(ch == EOF){
                break;
            }

            ungetc(ch, fp);
        }

        // Numeric constant
        else if(isdigit(ch)){
            buffer[j++] = ch;

            while((ch = fgetc(fp)) != EOF && (isdigit(ch) || ch == '.')){
                if(j < sizeof(buffer) - 1)
                    buffer[j++] = ch;
            }

            buffer[j] = '\0';
            j = 0;

            printf("%s is a constant\n", buffer);

            if(ch == EOF){
                break;
            }

            ungetc(ch, fp);
        }

        // Operators 
        else{
            int found = 0;

            for(int i = 0; operators[i] != '\0'; i++){
                if(ch == operators[i]){
                    printf("%c is an operator\n", ch);
                    found = 1;
                    break;
                }
            }

            // Special Characters
            if(!found){
                for(int i = 0; special[i] != '\0'; i++){
                    if(ch == special[i]){
                        printf("%c is a special character\n", ch);
                        break;
                    }
                }
            }
        }
    }

    fclose(fp);
    return 0;
}
