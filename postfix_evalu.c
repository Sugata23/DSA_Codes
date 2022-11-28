#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40

int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

int main()
{
	int i, a, b, result, pEval;
	char ch;
	
	for(i=0; i<SIZE; i++)
	{
		stack[i] = -1;
	}
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);

	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%':result = a%b;
					  break;
			}
			
			push(result);
		}		
	
	}

	pEval = pop();
	
	printf("\nThe postfix evaluation is: %d\n",pEval);
	
	return 0;
}

void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack is full!\n");
		exit(-1);
	}
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
}	