#define SIZE 50
#include <stdio.h>
#include <ctype.h>

char stack[SIZE];
int top=-1;

push(char elem)
{
	stack[++top]=elem;
}

char pop()
{
	return (stack[top--]);
}

int precedence(char elem)
{
	switch(elem)
	{
		case '#': return 0;
		case '(': return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':
		case '%':return 3;
		case '^': return 4;
	}
}

int main()
{
	char infix[50], postfix[50], ch, elem;
	int i=0, k=0;

	printf("Enter the infix expression:\t");
	scanf("%s", infix);

	push('#');

	while((ch=infix[i++])!='\0')
	{
		if(ch=='(')
		push(ch);
	
		else if(isalnum(ch))
		postfix[k++]=ch;

		else if(ch==')')
			{
				while(stack[top]!='(')
				postfix[k++]=pop();
				elem=pop();

			}
		else
		{
				while(precedence(stack[top])>=precedence(ch))
				postfix[k++]=pop();
				push(ch);

		}
	}

	while(stack[top]!='#')
	
		postfix[k++]=pop();
		postfix[k]='\0';
		printf("Given infix expression:\t%s\n", infix);
		printf("Postfix expression:\t%s\n", postfix);
}
