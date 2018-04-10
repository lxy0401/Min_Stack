#include <stdio.h>
#include "seqstack1.h"
typedef struct MinStack
{
    SeqStact stack;
}MinStack;

void MinStackInit(MinStack* min_stack)
{
    if(min_stack == NULL)
    {
        //非法操作
        return;
    }
    SeqStactInit(&min_stack->stack);
}

void MinStackPush(MinStack* min_stack,SeqStactType value)
{
    if(min_stack == NULL)
    {
        //非法操作
        return;
    }
    SeqStactType min=value;
    SeqStactType top;
    int ret = SeqStactTop(&min_stack->stack,&top);
    if(ret!=0)//ret=1
    {
        //有棧顶元素对情况下,让min等于棧对最小值
        min=top<value?top:value;
    }

    SeqStactPush(&min_stack->stack,value);//先入棧的为真正要入棧对元素
    SeqStactPush(&min_stack->stack,min);//后入棧对为当前棧对最小值
}

void MinStackPop(MinStack* min_stack)
{
    if(min_stack == NULL)
    {
        //非法操作
        return;
    }
    //连续出栈两个元素
    SeqStactPop(&min_stack->stack);
    SeqStactPop(&min_stack->stack);
}

int MinStackTop(MinStack* min_stack,SeqStactType* value)
{
    if(min_stack == NULL)
    {
        //非法操作
        return 0;
    }
    return SeqStactTop(&min_stack->stack,value);
}

/*****
 *
 * 以下为测试代码
 *
 * ****/

#if 1
#include <stdio.h>
#define TEST_HEADER printf("\n========%s=========\n",__FUNCTION__)

void Test()
{
    TEST_HEADER;
    MinStack min_stack;
    MinStackInit(&min_stack);
    MinStackPush(&min_stack,'a');
    MinStackPush(&min_stack,'b');
    MinStackPush(&min_stack,'c');
    MinStackPush(&min_stack,'d');
    char value;
    int ret;
    ret = MinStackTop(&min_stack,&value);
    printf("ret expected 1,actuall %d\n",ret);
    printf("value expected a,actuall %c\n",value);
    
    MinStackPop(&min_stack);
    MinStackPop(&min_stack);
    ret = MinStackTop(&min_stack,&value);
    printf("ret expected 1,actuall %d\n",ret);
    printf("value expected a,actuall %c\n",value);

    MinStackPop(&min_stack);
    MinStackPop(&min_stack);
    ret =MinStackTop(&min_stack,&value);
    printf("ret expected 0,actuall %d\n",ret);
    //printf("value expected b,actuall %c\n",value);
}

int main()
{
    Test();
    return 0;
}
#endif
