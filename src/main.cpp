#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#include "container/container.h"
#include "hand_commands/handCom.h"


void upload_commands(container &cont)
{
    std::string str;
    std::ifstream file("./file.txt");

    while(std::getline(file, str))
    {
        handCom::exect_com(cont, str);
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
 
    int cd;
    bool ext_f = true;
    container cont;

    try
    {
        while (ext_f)
        {
            printf("Выберите действие:\n1)Отобразить контейнер\n2)Загрузить файл команд\n3)закрыть программу\n");
            scanf_s("%d", (int*)&cd);

            switch(cd)
            {
                case 1:
                    handCom::exect_com(cont, std::string("PRINT"));
                    break;
                case 2:
                    upload_commands(cont);
                    break;
                case 3:
                    ext_f = false;
                    break;
                default:
                    printf("\nerr_value\n");
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        system("pause");
    }
    
    printf("\nПрограмма закрыта.");
    return 0;
}