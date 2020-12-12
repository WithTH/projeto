#include <iostream>
#include <fstream>
#include <string>
#include "utf8.h" //Biblioteca Personalizada para ocupar menos espaço, transforma os terminais de Windows em UTF-8
int main()
{
    
    utf();
    char letra;
    int i = 0;
    std::string linha, livro;
    std::ifstream lista,txt;
    std::cout << "Olá caro leitor(a)! Irei mostrar a tua lista de livros para que escolha vossa leitura." << std::endl;
    std::cout << "Lembrando que existe o arquivo 'README.txt' que esclarece algumas dúvidas." << std::endl;
    std::cout << "Para escolher o livro que deseja ler, informe o nome do mesmo (É recomendável 'copiar e colar'!)" << std::endl << std::endl;
    lista.open ("lista.txt"); //Abre o arquivo txt
    if(lista.is_open()) //Caso aberto o txt
    {
        while(getline(lista, linha)) //Lê uma linha
        {
            std::cout << linha << std::endl; //Enquanto houver linhas no txt
        }
        std::cout << "\nQual o livro que você deseja ler?" << std::endl;
        lista.clear(); //limpa o arquivo
        lista.close(); //fecha o arquivo
    }
    
    else
    {
        std::cout << "Não foi possível abrir o arquivo que contém os títulos, verifique se o mesmo se encontra no diretorio e tente novamente.";// caso não ache o txt, informa essa msg
    }
    getline(std::cin, livro); //pega o nome do txt que vc quer ler e armazena em livro
    std::cout << std::endl;
    livro="livros\\"+livro+".txt"; //transforma oq vc digitou na variavel livro e transforma no caminho do arquivo
    txt.open(livro.c_str()); //traforma a string e chars, pq o fstream entende so chars
    if(txt.is_open()) //Caso aberto o txt
    {
        do
        {
            do
            {
            getline(txt, linha); //Lê uma linha
            std::cout << linha << std::endl; //Enquanto houver linhas no txt
            i++; //soma 1++ para contar as linhas
            }
            while ( i < 20); // batendo 20 linhas ele para de ler
            i=0; // zera a variavel
            std::cout << "\nDeseja continuar lendo? [S/N]" << std::endl; //pergunta se vc quer continuar lendo
            std::cin >> letra; // armazena
            std:: cout << std::endl;
        }
        while(letra == 'S' || letra == 's'); //caso o usuario informe que quer continuar lendo, ele roda o "1° do" de novo
        txt.close(); //fecha o arquivo
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo" << std::endl; // caso não ache o txt, informa essa msg
    }
}