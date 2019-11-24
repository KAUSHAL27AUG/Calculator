#include "postfix.h"

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** array, int numberOfStrings) {
  struct double_stack* calc = double_stack_new(numberOfStrings);
	for(int i = 0; i < numberOfStrings; i++)
	{
	        int len = strlen(array[i]);
                if(len == 1)
	        {
	                double value1;
	                double value2;
	                switch(array[i][0]){  
	                case 'X':
	                value1 = double_stack_pop(calc);
	                value2 = double_stack_pop(calc);
	                value1 = value1 * value2;
	                double_stack_push(calc, value1);
	                break;
	                case '/':
	                value1 = double_stack_pop(calc);
	                value2 = double_stack_pop(calc);
	                value1 = value2 / value1;
	                double_stack_push(calc, value1);
	                break;
	                case'+':
	                value1 = double_stack_pop(calc);
	                value2 = double_stack_pop(calc);
	                value1 = value1 + value2;
	                double_stack_push(calc, value1);
	                break;
	                case'-':
	                value1 = double_stack_pop(calc);
	                value2 = double_stack_pop(calc);
	                value1 = value2 - value1;
	                double_stack_push(calc, value1);
	                break;
	                case'^':
	                value1 = double_stack_pop(calc);
	                value2 = double_stack_pop(calc);
	                value1 = pow(value2, value1);
	                double_stack_push(calc, value1);
	                break;
	                default:
	                double_stack_push(calc, atof(array[i]));
	                break;
 	                }
 	         }
 	     else if((len!= 1 && array[i][0] >= '0' && array[i][0] <= '9') || (len!= 1 && array[i][0] == '-'))
                { 
		        double_stack_push(calc, atof(array[i]));       
	        }
 	     
         }
         return double_stack_pop(calc);
}
