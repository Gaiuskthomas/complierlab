#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
int i = 1, j = 0, no = 0, tmpch = 90; char str[100], left[15], right[15]; 
void findop(void); 
void explore(void);
 void fleft(int); 
 void fright(int);
  struct exp {  
    int pos;    char op; }
     k[15]; 
     int main(void) 
     {
         printf("INTERMEDIATE CODE GENERATION\n");  
           printf("Enter the expression: ");   
            scanf("%99s", str);
                printf("\nIntermediate code:\tExpression\n");
                    findop();
                    explore();    
                    printf("\n");   
                    return 0; 
      } void findop(void) 
      {    for (i = 0; str[i] != '\0'; i++)    
             if (str[i] == ':')
              {            k[j].pos = i; 
                         k[j++].op = ':'; 
              }   
               for (i = 0; str[i] != '\0'; i++)
                 if (str[i] == '/') 
                 {            k[j].pos = i;
                             k[j++].op = '/'; 
                  }   
                for (i = 0; str[i] != '\0'; i++)    
                   if (str[i] == '*') 
                    {  
                         k[j].pos = i;   
                        k[j++].op = '*';      
                          } 
               for (i = 0; str[i] != '\0'; i++)    
                   if (str[i] == '+')
                {            k[j].pos = i; 
                           k[j++].op = '+';  
                 }    
                for (i = 0; str[i] != '\0'; i++)  
                   if (str[i] == '-') 
                   {           
                    k[j].pos = i;
                     k[j++].op = '-';       
                      } } 
                   void explore(void) 
                   {    i = 1; 
                      while (k[i].op != '\0') 
                      {        fleft(k[i].pos); 
                             fright(k[i].pos);   
                              str[k[i].pos] = tmpch--;  
                               printf("\t%c := %s %c %s\t\t", str[k[i].pos],               
                               left, k[i].op, right);       
                                for (j = 0; j < (int)strlen(str); j++)           
                                 if (str[j] != '$')               
                                  printf("%c", str[j]);
                                  printf("\n");
                                  i++;
                                 }
                               fright(-1);

if (no == 0) {
    fleft((int)strlen(str));
    printf("\t%s := %s\n", right, left);
    exit(0);
}

printf("\t%s := %c\n", right, str[k[--i].pos]);
}

void fleft(int x) {
    int w = 0;
    int flag = 0;

    x--;

    while (x != -1 &&
           str[x] != '+' &&
           str[x] != '*' &&
           str[x] != '=' &&
           str[x] != ':' &&
           str[x] != '-' &&
           str[x] != '/' &&
           str[x] != '\0') {
        if (str[x] != '$' && flag == 0) {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
            flag = 1;
        }

        x--;
    }
}

void fright(int x) {
    int w = 0;
    int flag = 0;

    x++;

    while (x != -1 &&
           str[x] != '+' &&
           str[x] != '*' &&
           str[x] != '=' &&
           str[x] != ':' &&
           str[x] != '-' &&
           str[x] != '/' &&
           str[x] != '\0') {
        if (str[x] != '$' && flag == 0) {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
            flag = 1;
        }

        x++;
    }
}
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
