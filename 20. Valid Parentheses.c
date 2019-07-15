#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack_t{
    char data[100000];
    int top;
};

int enstack_t(struct stack_t *qu,char x)
{
    qu->top=qu->top+1;
    qu->data[qu->top]=x;
    return 1;
}

int destack_t(struct stack_t*qu)
{
    qu->top=qu->top-1;
    return 1;
}

bool isValid(char* s)
{
    struct stack_t *p=(struct stack_t *)malloc(sizeof(struct stack_t));
    p->top=0;
    if(strlen(s)==0)return true;
    enstack_t(p,s[0]);

    for(int i=1;i<strlen(s);i++)
    {
        if(p->data[p->top]=='[')
        {
            if(s[i]==']')destack_t(p);
            else enstack_t(p,s[i]);
        }
        else if(p->data[p->top]=='(')
        {
            if(s[i]==')')destack_t(p);
            else enstack_t(p,s[i]);
        }
        else if(p->data[p->top]=='{')
        {
            if(s[i]=='}')destack_t(p);
            else enstack_t(p,s[i]);
        }
        else enstack_t(p,s[i]);
    }
    if(p->top==0)return true;
    else return false;
}