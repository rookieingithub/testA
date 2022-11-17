#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// 忽略本行剩余字符
void func_ignore(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

// 回显本行剩余字符
void func_echo(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        putchar(ch);
        continue;
    }
}

// 判断ch是否在opt中存在
bool optionalchar(char ch,char *opt)
{
    int i;
    for (i = 0; i < sizeof(opt); i++)
    {
        if (opt[i] == ch)
        {
            return true;
        }
        
    }
    
    return false;
}

// 跳过空白字符
char notblank(void)
{
    char ch;
    char space[32] = {'\n','\t',' '};
    ch = getchar();
    while (optionalchar(ch,space))
    {
        ch = getchar();
        continue;
    }

    return ch;
}

// 获得一行输入的首个字母类的字符,跳过其他字符
char get_firstchar(char *opt)
{
    char ch;

    while ((ch = notblank()) != '\n')
    {
        func_ignore();
        if (!optionalchar(ch, opt))
        {
            printf("your input is inviald.\n");
            continue;
        }
        break;
    }
    return ch;
}

// 获得一个数字
float get_floatnum(void)
{
    float num;
    while(scanf("%f",&num) != 1)
    {
        func_echo();
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:1\n");
        continue;
    }
    return num;
}

// 用户主界面
void display_main(void)
{
    printf("\n***********************MAIN***************************\n");
    printf("a. addition             s. subtract \n");
    printf("m. multiply             d. divide   \n");
    printf("q. quit \n");
    printf("\n******************************************************\n");
    printf("Enter the operation of your choice : ");
}

void display_addition(void)
{
    printf("\n***********************ADDATION***********************\n");
    printf("b. back             q. quit \n");
    printf("\n******************************************************\n");
    printf("Enter the operation of your choice : ");
}

void display_subtract(void)
{
    printf("\n***********************SUBTRACT***********************\n");
    printf("b. back             q. quit \n");
    printf("\n******************************************************\n");
    printf("Enter the operation of your choice : ");
}

void display_multiply(void)
{
    printf("\n***********************MULTIPLY***********************\n");
    printf("b. back             q. quit \n");
    printf("\n******************************************************\n");
    printf("Enter the operation of your choice : ");
}

void display_divide(void)
{
    printf("\n***********************DIVIDE*************************\n");
    printf("b. back             q. quit \n");
    printf("\n******************************************************\n");
    printf("Enter the operation of your choice : ");
}

float func_add(float a,float b)
{
    float res = 0;
    res = a + b;
    return res;
}

void addition(void)
{
    char opt[32] = {'b', 'q'};
    float optnum1,optnum2;

    printf("Enter first number : ");
    optnum1 = get_floatnum();
    printf("Enter second number : ");
    optnum2 = get_floatnum();
    printf("\n%f + %f = %f\n", optnum1, optnum2, func_add(optnum1,optnum2));

    display_addition();
    get_firstchar(opt);
}

float func_sub(float a,float b)
{
    float res = 0;
    res = a - b;
    return res;
}

void subtract(void)
{    char opt[32] = {'b', 'q'};
    float optnum1,optnum2;

    printf("Enter first number : ");
    optnum1 = get_floatnum();
    printf("Enter second number : ");
    optnum2 = get_floatnum();
    printf("\n%f - %f = %f\n", optnum1, optnum2, func_sub(optnum1,optnum2));

    display_subtract();
    get_firstchar(opt);
    }

float func_mul(float a,float b)
{
    float res = 0;
    res = a * b;
    return res;
}

void multiply(void)
{
    char opt[32] = {'b', 'q'};
    float optnum1,optnum2;

    printf("Enter first number : ");
    optnum1 = get_floatnum();
    printf("Enter second number : ");
    optnum2 = get_floatnum();
    printf("\n%f * %f = %f\n", optnum1, optnum2, func_mul(optnum1,optnum2));

    display_multiply();
    get_firstchar(opt);
}

// 除法,注意b不能为0
float func_div(float a,float b)
{
    float res = 0;
    res = a / b;
    return res;
}

void divide()
{
    char opt[32] = {'b', 'q'};
    float optnum1,optnum2;

    printf("Enter first number : ");
    optnum1 = get_floatnum();
    printf("Enter second number : ");
    optnum2 = get_floatnum();
    while(optnum2 == 0)
    {
        printf("Enter a number other than 0 : ");
        optnum2 = get_floatnum();
    }
    
    printf("\n%f / %f = %f\n", optnum1, optnum2, func_div(optnum1,optnum2));

    display_divide();
    get_firstchar(opt);
}

int main(int argc, char const *argv[])
{
    char ch;
    char opt[32] = {'a', 's', 'm', 'd', 'q'};


    display_main();
while ((ch = get_firstchar(opt)) != 'q')
{
    switch (ch)
    {
    case 'a':
        addition();
        break;
    case 's':
        subtract();
        break;
    case 'm':
        multiply();
        break;
    case 'd':
        divide();
        break;
    default:
        printf("something error!\n");
        break;
    }

    display_main();
}

    return 0;
}

