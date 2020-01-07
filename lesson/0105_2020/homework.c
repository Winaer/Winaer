#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fornumber(int a,int count)
{
    if (a > 1)
    {
       count *= a;
       a--;
       fornumber(a, count);
    }
    else
    {
        return count;
    }

}


void test1()
{
    int count = 1;
    int num;

    printf("please input the number you want:\n");
    scanf("%d", &num);

    count = fornumber( num, count);

    printf("%d! = %d\n", num, count);
}


int countmoney(int day,int money, int count, int date)
{
    if (day > 0)
    {
        count += money;
        money += date;
        day--;
        countmoney(day, money, count, date);
    }
    else
    {
       return count;
    }
    
    
}


void test2()
{
    int count = 0;
    int money = 100;
    int date = 10;
    int day;

    printf("please input the day you want:\n");
    scanf("%d", &day);

    count = countmoney(day, money, count, date);

    printf("the count of money is :%d\n", count);


}


void test3()
{
    int numa;
    int numb;
    int ctrl;
    float count;
    char s;

    printf("please input the num1 and num2  and the kind of count:\n");
    scanf("%d %d %d", &numa, &numb, &ctrl);

    switch (ctrl)
    {
    case 1:
        count = numb + numa;
        s = '+';
        break;
    case 2:
        count = numa - numb;
        s = '-';
        break;
    case 3:
        count = numa * numb;
        s = '*';
        break;
    case 4:
        count = numa / numb;
        s = '/';
        break;        
    
    default:
        printf("input error, it's ending!\n");
        break;
    }

    printf("%d %c %d = %d", numa, s, numb, count);

}


int main(void)
{
    test1();
    test2();
    test3();


    system("pause");
    return 0;

}