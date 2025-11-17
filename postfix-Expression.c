// Write a program to evaluate a postfix expression

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main(){
    char exp[20];
    printf("Enter the postfix expression\n");
    scanf("%s",exp);
    int stack[20];
    int top=-1;
    int i=0;
    while(exp[i]!='\0'){
        if(isdigit(exp[i])){
            stack[++top]=exp[i] - '0';// this is to convert the string format of the number to integer format
        }
        else{
            int a=stack[top--];
            int b=stack[top--];
            switch(exp[i]){
                case '+':
                stack[++top]=a+b;
                break;

                case '-':
                stack[++top]=b-a;
                break;

                case '*':
                stack[++top]=a*b;
                break;

                case '/':
                stack[++top]=a/b;
                break;

                case '^':
                stack[++top]=pow(a,b);
                break;
            }
        }
        i++;
        //printf("%d\n",stack[top]);
    }
    printf("%d\n",stack[top]);
    return 0;
}