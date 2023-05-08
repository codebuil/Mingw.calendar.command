#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getday(int dia,int mes,int ano){
    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;
    int d = (dia + y + y/4 - y/100 + y/400 + (31*m)/12) % 7; 
    return d;
}
int main()
{
    // Obtém a data atual
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char ttt[1024];
    // Calcula o dia da semana (0 = domingo, 1 = segunda-feira, etc.)
    int dia = 0;
    int mes = 0 ;// O mês começa em zero, então adicionamos 1
    int ano = 0; // O ano é o número de anos desde 1900
    int d=0;
    
    printf("\ec\e[44;30m\n");
    while(1){
        printf("give me the month?");
        fgets(ttt,1023,stdin);
        mes=atoi(ttt);
        printf("give me the day?");
        fgets(ttt,1023,stdin);
        dia=atoi(ttt);
        printf("give me the Year YYYY?");
        fgets(ttt,1023,stdin);
        ano=atoi(ttt);
        d=getday(dia,mes,ano);
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

    }
    return 0;
}
