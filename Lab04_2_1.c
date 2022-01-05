/*
* lab04_1_1.cpp - ������� ���� �������.
* Copyright (C) 2021 ����������� �.�. <mistertonyragrel@gmail.com>
*
* ������ ��������� ������ ������ ����������� ����� ���� � �������� ���������.
* ���� ��������� �������� 02.01.2021
* ��������� �������� �� �������� GNU
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define mAUTHOR "[1] - �� ������"
#define mCALCULATE "[2] - ����� ����"
#define mEXIT "[0] - �����"
#define mCHOOSE "��� �����: "
#define AUTHOR "����������� ������ ����������"

void showMenu();
void getValues(float*, float*);
float getSum(float, float);

int main(void){
    int choose;
    float e, x;

    setlocale(LC_ALL, "RUS");

    printf("��������� ����������� ����� ���� � �������� ���������.\n");
    showMenu();

    while(scanf("%d", &choose)==1 && choose!=0){
        switch(choose){
            case 1:
                printf("\n��� ������: %s\n\n", AUTHOR);
                showMenu();
                break;
            case 2:
                getValues(&x, &e);
                printf("\n����� ���� S = %f\n\n", getSum(x, e));
                showMenu();
                break;
            default:
                printf("����� ������� ���. ���������� ������ ��� ���.\n\n");
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
    printf("\n������� �������� e: ");
    scanf("%g", e);
    printf("\n������� ���������� ��������������� ���� (-1; 1)\n");
    printf("\n������� ����� x � �������� ������� ����������: ");
    while(scanf("%g",x)==1 && (*x>=1 || *x<=-1)){
        printf("\n��������� ����� �� ����������� ��������� (-1;1).\n������� ����� � ��������: ");
    }
}

float getSum(float x, float e){
    float sum=0;
    float an = 2*x;
    int k = 0;
    printf("\n%10s%14s%14s","�����", "���� ����", "����� ����");
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
