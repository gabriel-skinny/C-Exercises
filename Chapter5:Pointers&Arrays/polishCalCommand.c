#include <stdio.h>
#include <stdlib.h>

void push(double);
double pop(void);

int main(int argc, char *argv[]){
  char *c;
  double op1, op2;

  while(--argc > 0){
    c = *(++argv);

    if ((*c - '0') > 0 && (*c - '0') <= 9){
      push(atof(c));
    }

    else {
      switch(*c) {
        case '+': 
          op1 = pop();
          op2 = pop();

          printf("\nthe expression is %f + %f = %f", op1, op2, op1 + op2);
          push(op1 + op2);
          break;

        case '*':
          op1 = pop();
          op2 = pop();

          printf("\nthe expression is %f * %f = %f", op1, op2, op1 * op2);
          push(op1 * op2);
          break;

        case '-':
          op1 = pop();
          op2 = pop();

          printf("\nthe expression is %f - %f = %f", op1, op2, op1 - op2);
          push(op1 - op2);
          break;

        case '/':
          op1 = pop();
          op2 = pop();
          if (op2 != 0.0){
            printf("\nthe expression is %f / %f = %f", op1, op2, op1 / op2);
            push(op1 / op2);
          }
          else
            printf("error: zero divisor\n");
          break;
        
        case '%':
          op2 = pop();
          if (op2 != 0.0)
            push((int)pop() % (int)op2);
          else
            printf("error: zero divisor");
          break;

        default:
          printf("error: unknown command");
          break;
      }
    }
    
  }

  return 0;
}

#define MAXVAL 20
double val[MAXVAL];

int sp = 0;

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  
  else 
    printf("\n\nTo much values");
  
}

double pop(void) {
  if (sp > 0) 
    return val[--sp];
 
  else 
     printf("error: stack empty\n");
    return 0.0; 
}