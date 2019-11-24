#include "infix.h"

// evaluate expression stored as an array of string tokens

int checkPrecendence(char operator)
{
	int precedence = 0;
	if(operator == '^')
	{
		precedence = 1;
	}
	else if(operator == 'X' || operator == '/')
	{
		precedence = 2;
	}	
	else if(operator == '+' || operator == '-')
	{
		precedence = 3;
	}
	else
	{
		precedence = 10;
	}
	return precedence;
}

double evaluate_infix_expression(char ** array, int numberOfStrings) {
int strings = numberOfStrings;
	struct double_stack* expStack = double_stack_new(numberOfStrings);
	char* expression[numberOfStrings];
	int count = 0;
	for(int i = 0; i < numberOfStrings; i++)
	{
		expression[i] = '\0';
	}
	
	for(int i = 0; i < numberOfStrings; i++)
	{
		int len = strlen(array[i]);
		if((array[i][0] >= '0' && array[i][0] <= '9') || (len!= 1 && array[i][0] == '-'))
		{
			expression[count] = array[i];
			count++;
		}
		else if(array[i][0] == '(')
		{
			double_stack_push(expStack, i);
			strings = strings -2;
		}
		else if(array[i][0] == ')')
		{
			int index = double_stack_pop(expStack);
			double_stack_push(expStack, index);
			char peak = array[index][0];
			while(peak != '(')
			{
				int index = double_stack_pop(expStack);
				expression[count] = array[index];
				count++;
				index = double_stack_pop(expStack);
				double_stack_push(expStack, index);
				peak = array[index][0];
			}
			double_stack_pop(expStack);
		}	
		else 
		{
			int index = double_stack_pop(expStack);
			double_stack_push(expStack, index); //peaking top 
			int topPrecedence = checkPrecendence(array[index][0]);
			int operatorPrecedence = checkPrecendence(array[i][0]);
			while(topPrecedence <= operatorPrecedence)
			{
				int index = double_stack_pop(expStack);
				expression[count] = array[index];
				count++;
				index = double_stack_pop(expStack);
				double_stack_push(expStack, index);
				topPrecedence = checkPrecendence(array[index][0]);
			}
			double_stack_push(expStack, i);
		}
	}
	int index = double_stack_pop(expStack);
	char peak = array[index][0];
	while(checkPrecendence(peak) != 10) //add the rest of the operators
	{
	expression[count] = array[index];
	count++;
	index = double_stack_pop(expStack);
	peak = array[index][0];
	}
   return evaluate_postfix_expression(expression , strings);
}
