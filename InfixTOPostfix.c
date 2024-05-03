#include <stdio.h>
#include <stdlib.h>
#include<string.h>
# define MAX 100
char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

void push(char symbol){
   stack[++top]=symbol;
}
char pop(){
  return stack[top--];
}
int isEmpty(){
    return top==-1;
}
int precendence(char symbol){
    switch(symbol){
        //higher value means greater precendeneces
        case '^':
          return 3;
        case '/':
        case '*':
        case '%':
          return 2;
        case '+':
        case '-':
          return 1;
        default : //in case of '(' and  ')'
          return 0;
    }
}
void inToPost(){
    char symbol;
    int j=0;
    char next;
    //strlen() will give length of the character array without including '\0'
    for(int i=0;i<strlen(infix);i++){
         symbol=infix[i];
         switch(symbol){
            case '(':
            push(symbol);
            break;
            case ')':
              while((next=pop())!='(')
                  postfix[j++]=next;
              break;

             case '+':    
             case '-':
             case '*':
             case '/':
             case '%':
             case '^':
                 while(!isEmpty() && precendence(stack[top])>=precendence(symbol)){
                    postfix[j++]=pop();
                 }
                 push(symbol);
                break;

            default :
             postfix[j++]=symbol;       
         }
    }
    while(!isEmpty())
    postfix[j++]=pop();
    postfix[j]='\0';
}

int main(){
   printf("Enter the infix expression : ");
   gets(infix);

   inToPost();
   printf("%s",postfix);
}