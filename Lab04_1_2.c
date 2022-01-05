/*
* lab04_1_1.cpp - ������� ���� �������.
* Copyright (C) 2021 ����������� �.�. <mistertonyragrel@gmail.com>
*
* ������ ��������� ������ ������ ����������� ������ ����� ����,
* ������� � �������� ����� S ����� ������ ��������� ����� A.
* ���� ��������� �������� 02.01.2021
* ��������� �������� �� �������� GNU
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define mAUTHOR "[1] - �� ������"
#define mCALCULATE "[2] - ����� ����� ����"
#define mEXIT "[0] - �����"
#define mCHOOSE "��� �����: "
#define AUTHOR "����������� ������ ����������"
#define NO_SUCH_NUM "���������� ����� ����� ����� ����, ������� � �������� ����� S ����� ������ ����� A"
#define NO_SUCH_NUMBER 0

void showMenu();
void getValues(int*, float*);
float getNum(int, float);

int main(void){
    int choose, x;
    float a;

    setlocale(LC_ALL, "RUS");

    printf("��������� ���������� ����� ����� ����, ������� � ��������\n����� ���� ������ ��������� ����� A.\n");
    showMenu();

    while(scanf("%d", &choose)==1 && choose!=0){
        switch(choose){
            case 1:
                printf("\n��� ������: %s\n\n", AUTHOR);
                showMenu();
                break;
            case 2:
                getValues(&x, &a);
                /*
                    ����������� ���������� k ������������
                    �������� ���-��� getNum, ����� ���������
                    ����� �� ��� 0. ���� k = 0, �� �������
                    ���������� ��������� NO_SUCH_NUM,
                    ������������ ���������� #define.
                    ����� - ������� k
                */
                int k = getNum(x, a);
                if(k){
                    printf("\n����� ����� ���� - %d\n\n", k);
                }else{
                    printf("\n%s\n\n", NO_SUCH_NUM);
                }
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
    printf("%s", mCHOOSE);
}

void getValues(int *x, float *a){
    printf("\n������� ����� a: ");
    scanf("%g", a);
    printf("\n������� ����� x: ");
    scanf("%d", x);
}


float getNum(int x, float a){
    float sum=0;
    float an = 1;
    int k = 0;
    printf("\n%10s%14s","�����", "����� ����");
    while(sum <= a){
        // ���� k >= 30, �� ���������� 0 (NO_SUCH_NUMBER)
        if(k>=30) return NO_SUCH_NUMBER;
        k++;
        an*=x/(float)(k+1);
        sum+=an;
        printf("\n%10.d %14.8f", k, sum);
    }

    printf("\n");
    return k;
}
