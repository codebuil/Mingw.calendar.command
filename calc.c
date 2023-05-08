#include <stdio.h>
#include <time.h>

int main()
{
    // Obtém a data atual
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Calcula o dia da semana (0 = domingo, 1 = segunda-feira, etc.)
    int dia = tm->tm_mday;
    int mes = tm->tm_mon + 1; // O mês começa em zero, então adicionamos 1
    int ano = tm->tm_year + 1900; // O ano é o número de anos desde 1900
    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;
    int d = (dia + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    printf("\ec\e[44;30m\n");
    // Exibe o dia da semana
    switch (d)
    {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }

    return 0;
}
