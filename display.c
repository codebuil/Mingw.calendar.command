#include <stdio.h>
#include <time.h>

int main()
{
    // Obtém a data atual
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int n=0;
    int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    // Calcula o dia da semana (0 = domingo, 1 = segunda-feira, etc.)
    int dia = 1;
    int mes = tm->tm_mon + 1; // O mês começa em zero, então adicionamos 1
    int ano = tm->tm_year + 1900; // O ano é o número de anos desde 1900
    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;
    int d = (dia + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    if((ano/4)*4==ano)months[2]=29;
    printf("\ec\e[44;30m\n");
    // Exibe o dia da semana
    for (n=0;n<d;n++){
        printf("   ");
    }
    for (n=1;n<32;n++){
        if(n<=months[mes-1])printf(" %2d",n);
        d++;
        if(d>6){
            d=0;
            printf("\r\n");
        }
    }    

    return 0;
}
