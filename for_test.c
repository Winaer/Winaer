#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void test1()
{

    char str[80];
    int i;
    int space = 0;
    int word = 0;
    int figure = 0;
    int other = 0;

    printf("please input the string:\n");
    fflush(stdin);
    gets(str);

    for ( i = 0; i < strlen(str) ; i++)
    {
        if (str[i] == 32)
        {
            space++;
        }
        else if ( ( ( str[i] >= 'A') && (str[i] <= 'Z') ) || (( str[i] >= 'a') && (str[i] <= 'z') ) )
        {
            word++;
        }
        else if (( str[i] >= '0') && (str[i] <= '9'))
        {
            figure++;
        }
        else
        {
            other++;
        }   
    }
    

    printf("you input %d words and %d figures and %d space and %d other!", word, figure, space, other);

}

void test2()
{

    // double pi = 3.1415926;
    // double m[20];
    int a[5][4];

    int i;
    int j;


    for ( i = 0; i < 5; i++)
    {
       for ( j = 0; j < 4; j++)
       {
          a[i][j] = 5*i + j;
       }
       
    }
    printf("a = %p\n", a);
    printf("a+1 = %p\n", a+1);
    printf("*(a+1)+1 =   %p     &(a[1][1]) = %p\n", *(a+1)+1, &(a[1][1]));
    printf("&a[1]+1 =    %p     &(a[2][0])=  %p\n", &a[1]+1, &(a[2][0]));
    printf("*((a+2)+1) = %p     &(a[3][0]) = %p\n", *((a+2)+1), &(a[3][0]) );
    printf("this is complex logic!\n");


}


void test3()
{
    float sum = 0;
    float date;
    int c = -1;
    int i;


    for ( i = 0; i < 100; i++)
    {
        c = -c;
        date = (float)c/i;
        sum += date;
    }
    printf("1-1/2+1/3+...+1/99-1/100 = %5.2f", sum);

}



void test4()
{
    int num;
    int i;
    int hun;
    int ten;
    int fig;

    for ( i = 100; i < 1000; i++)
    {
        hun = i/100;
        ten = (i / 10) % 10;
        fig = i % 10;

        if (i == hun*hun + ten*ten + fig*fig)
        {
            printf("%d is  narcissistic number!\n", i);
        }   
    }
}



void test5()
{
    int sum = 0;
    int a;
    int n;
    int date;
    int i;


    printf("please input n,a to count Sn = a+aa+aaa+...\n");
    scanf("%d %d", &n, &a);

    date = a;
    for ( i = 0; i < n; i++)
    {
        date += a*i*10; 
        sum += date;
    }
    
}


void test6()
{
    int a[4][2];
    int i;
    int j;
    int average = 0;

    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            printf("please input the grade of student%d coure%d\n", i+1, j+1);
            scanf("%d", &a[i][j]);
            average += a[i][j] / 8;
        }
        
    }
    
    printf("the average of these studentes is %d\n", average);

}




int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    system("pause");
    return 0;
}