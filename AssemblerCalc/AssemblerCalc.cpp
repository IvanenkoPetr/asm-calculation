// AssemblerCalc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>

int main()
{
    int a, b, c, d, w;
    int ordinaryResult, asmResult;

    while (true)
    {
        printf("\nEnter a:");
        scanf_s("%d", &a);

        printf("\nEnter b:");
        scanf_s("%d", &b);

        printf("\nEnter c:");
        scanf_s("%d", &c);

        printf("\nEnter d:");
        scanf_s("%d", &d);

        printf("\nEnter w:");
        scanf_s("%d", &w);

        // Произведем эталонный рассчет, "обычными" арифметическими операторами c++
        ordinaryResult = c - (a + b + d)*b/(a + w);

        __asm
        {
            // Получаем сумму a + b + c, результат накапливается в регистре eax 
            mov eax, a
            add eax, b
            add eax, d

            mov ebx, b // помещаем переменную b в регистр ebx
            mul ebx // умножаем сумму a + b + c, лежащую в регистре eax на b, результат остается в eax

            // Получаем сумму a + w, результат накапливается в регистре ebx 
            mov ebx, a
            add ebx, w            

            div ebx // делим (a + b + c) * b, лежащую в eax, на (a + w), лежащую в ebx, результат в остается в eax
            
            mov ebx, c // положим переменную c в регистр ebx
            sub ebx, eax // вычтем из c, лежащую в ebx, все что вычислили на предыдущих шагах  

            mov asmResult, ebx // результат вычислений сохраним в переменную asmResult
        };

        printf("ordinary result  = %d   result from assembler = %d\n\a", ordinaryResult, asmResult); // Сравним вычисления "обычным способом" и через assembler

    }

}

