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

void showMenu(); // Прототип функции вывода текстового меню
void getValues(float*, float*); // Прототип функции для инициализации переменных
float getSum(float, float); // Прототип функции, расчитывающей сумму ряда с заданной точностью

int main(void){
    int choose; // Переменная для хранения выбранного пункта меню
    float e, x; // e - точность

    setlocale(LC_ALL, "RUS");

    printf("Программа расчитывает сумму ряда с заданной точностью.\n");
    showMenu(); // Показать меню
    /*
        Цикл повторяется до тех пор
        Пока пользователь не введет 0
        Либо любой символ текста
    */
    while(scanf("%d", &choose)==1 && choose!=0){
        switch(choose){
            case 1:
                printf("\nФИО автора: %s\n\n", AUTHOR);
                showMenu(); // Показать меню
                break;
            case 2:
                getValues(&x, &e); // Присваиваем переменным значения, введенные пользователем
                printf("\nСумма ряда = %f\n\n", getSum(x, e)); // Выводим сумму ряда
                showMenu();// Показать меню
                break;
            default:
                printf("Такой команды нет. Попробуйте ввести еще раз.\n\n");
                showMenu();// Показать меню
        }
    }
    return 0;
}
/*
    Функция выводит текстовое меню
    Используя символические константы,
    Заданные директивой #define
*/
void showMenu(){
    printf("%s\n", mAUTHOR);
    printf("%s\n", mCALCULATE);
    printf("%s\n", mEXIT);
    printf("%s", mCHOOSE);
}
/*
    Функция принимает в качестве аргументов
    Адреса переменных e и x
    И присваивает этим переменным значения,
    Введеные пользователем
*/
void getValues(float *x, float *e){
    printf("\nВведите точность e: ");
    scanf("%g", e);
    printf("\nВведите число x: ");
    scanf("%g", x);
}

/*
    Функция принимает значения e и x
    В качестве аргументов и вычисляет
    Сумму ряда с точностью e,
    После чего возвращает значение суммы
*/
float getSum(float x, float e){
    float sum=0; // Сумма ряда
    float an = 1; // Член ряда
    int k = 0; // Номер члена ряда
    printf("\n%10s%14s%14s","НОМЕР", "ЧЛЕН РЯДА", "СУММА РЯДА");

    while(fabs(an)> e){
        k++;
        an*=x/(float)(k+1);
        sum+=an;
        printf("\n%10.d %14.8f %14.8f", k, an, sum);
    }

    printf("\n");

    return sum;
}
