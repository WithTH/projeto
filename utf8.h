#ifdef _WIN32 // Caso aberto em um Widndows faça isso
#include <windows.h> //inclui a biblioteca windows, estou utilizando para transformar o terminal em UTF-8
void utf()
{
    SetConsoleOutputCP (65001); //"seta" o terminal em UTF-8
    SetConsoleCP (65001); //"seta" o terminal em UTF-8
}
#else // Caso o SO não for windows, ele não mudará nada no terminal, colocado isso pra ajudar os linux users
void utf()
{
    return 0; // não mudará nada pois retornara 0
}
#endif