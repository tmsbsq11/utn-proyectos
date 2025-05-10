#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
char getch(void) {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
    return buf;
 }
 void clearsc() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void getch_clrsc() {
    getch();
    clearsc();
}
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int leerEntero() {
    char buffer[20];
    int num;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &num) == 1) break;
        printf("Entrada inválida. Intente de nuevo: ");
    }
    return num;
}
