/*
* lab04_1_1.cpp - главный файл проекта.
* Copyright (C) 2021 Смирновский М.Е. <mistertonyragrel@gmail.com>
*
* Данная программа решает задачу определения суммы ряда с заданной точностью.
* Дата последней редакции 02.01.2021
* Программа доступна по лицензии GNU
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define mAUTHOR "[1] - Об авторе"
#define mCALCULATE "[2] - Сумма ряда"
#define mEXIT "[0] - Выход"
#define mCHOOSE "Ваш выбор: "
#define AUTHOR "Смирновский Михаил Евгеньевич"

void showMenu();
void getValues(float*, float*);
float getSum(float, float);

int main(void){
    int choose;
    float e, x;

    setlocale(LC_ALL, "RUS");

    printf("Программа расчитывает сумму ряда с заданной точностью.\n");
    showMenu();

    while(scanf("%d", &choose)==1 && choose!=0){
        switch(choose){
            case 1:
                printf("\nФИО автора: %s\n\n", AUTHOR);
                showMenu();
                break;
            case 2:
                getValues(&x, &e);
                printf("\nСумма ряда S = %f\n\n", getSum(x, e));
                showMenu();
                break;
            default:
                printf("Такой команды нет. Попробуйте ввести еще раз.\n\n");
                showMenu();
        }
    }
    return 0;
}

void showMenu(){
    printf("%s\n", mAUTHOR);
    printf("%s\n", mCALCULATE);
    printf("%s\n", mEXIT);
    printf("\n%s", mCHOOSE);
}

void getValues(float *x, float *e){
    printf("\nВведите точность e: ");
    scanf("%g", e);
    printf("\nОбласть сходимости функционального ряда (-1; 1)\n");
    printf("\nВведите число x в пределах области сходимости: ");
    while(scanf("%g",x)==1 && (*x>=1 || *x<=-1)){
        printf("\nВведенное число не принадлежит интервалу (-1;1).\nВведите число х повторно: ");
    }
}

float getSum(float x, float e){
    float sum=0;
    float an = 2*x;
    int k = 0;
    printf("\n%10s%14s%14s","НОМЕР", "ЧЛЕН РЯДА", "СУММА РЯДА");
    while(fabs(an)> e){
        sum+=an;
        printf("\n%10d %14.8f %14.8f", k, an, sum);
        k++;
        an= 2 * pow(x,(2*k + 1))/(2*k + 1);
    }
    sum+=an;
    printf("\n%10.d %14.8f %14.8f\n", k, an, sum);
    return sum;
}
