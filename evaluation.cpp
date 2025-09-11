#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50
int stack[SIZE];
int top = -1;
void push(int elem){
	top = top+1;
	stack[top]=elem;
}
int pop(){
	return (stack[top--]);
}
int main(){
	char pofx[50],ch;
	int i,op1,op2;
	printf("Read the infix expression ? ");
	scanf("%s",pofx);
	while((ch=pofx[i++]) != '\0'){
		if(isdigit(ch))
		push(ch-'0');
		else{
			op2=pop();
			op1=pop();
			switch(ch){
				case '+' :push(op1+op2); break;
				case '-' :push(op1-op2); break;
				case '*' :push(op1*op2); break;
				case '/' :push(op1/op2); break;
			}
		}
	}
	printf("Given postfix expn : %s \n",pofx);
	printf("result after evaluation %d",stack[top]);
}
