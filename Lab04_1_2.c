/*
* lab04_1_1.cpp - главный файл проекта.
* Copyright (C) 2021 Смирновский М.Е. <mistertonyragrel@gmail.com>
*
* Данная программа решает задачу определения номера члена ряда,
* начиная с которого сумма S будет больше заданного числа A.
* Дата последней редакции 02.01.2021
* Программа доступна по лицензии GNU
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define mAUTHOR "[1] - Об авторе"
#define mCALCULATE "[2] - Номер члена ряда"
#define mEXIT "[0] - Выход"
#define mCHOOSE "Ваш выбор: "
#define AUTHOR "Смирновский Михаил Евгеньевич"
#define NO_SUCH_NUM "Невозможно найти номер члена ряда, начиная с которого сумма S будет больше числа A"
#define NO_SUCH_NUMBER 0

void showMenu();
void getValues(int*, float*);
float getNum(int, float);

int main(void){
    int choose, x;
    float a;

    setlocale(LC_ALL, "RUS");

    printf("Программа определяет номер члена ряда, начиная с которого\nСумма ряда больше заданного числа A.\n");
    showMenu();

    while(scanf("%d", &choose)==1 && choose!=0){
        switch(choose){
            case 1:
                printf("\nФИО автора: %s\n\n", AUTHOR);
                showMenu();
                break;
            case 2:
                getValues(&x, &a);
                /*
                    Присваиваем переменной k возвращаемое
                    значение фун-ции getNum, чтобы проверить
                    равно ли оно 0. Если k = 0, то выводим
                    символьную константу NO_SUCH_NUM,
                    определенную директивой #define.
                    Иначе - выводим k
                */
                int k = getNum(x, a);
                if(k){
                    printf("\nНомер члена ряда - %d\n\n", k);
                }else{
                    printf("\n%s\n\n", NO_SUCH_NUM);
                }
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
    printf("%s", mCHOOSE);
}

void getValues(int *x, float *a){
    printf("\nВведите число a: ");
    scanf("%g", a);
    printf("\nВведите число x: ");
    scanf("%d", x);
}


float getNum(int x, float a){
    float sum=0;
    float an = 1;
    int k = 0;
    printf("\n%10s%14s","НОМЕР", "СУММА РЯДА");
    while(sum <= a){
        // Если k >= 30, то возвращаем 0 (NO_SUCH_NUMBER)
        if(k>=30) return NO_SUCH_NUMBER;
        k++;
        an*=x/(float)(k+1);
        sum+=an;
        printf("\n%10.d %14.8f", k, sum);
    }

    printf("\n");
    return k;
}
