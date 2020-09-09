#include <iostream>
#include <zconf.h>
#include <map>
#include "server.h"
#include "game.h"


int main() {
    int counter = 0;                               // просто для удобства отладки

    auto game = new Game();
    auto server = new Server(true, 7777);

    int supervisorConnection = 0;                      // связь с супервизором/ssl-vision

    // распараллелить
    /*for (int i = 0; i < 2; i ++)
    {
        auto robot = server->connectClient();
        if (robot.number == 0){                        // номера роботов = номер команды * 100 + номер робота
            supervisorConnection = robot.connection;   // номер супервизора = 0
        }
        else{
            game->robots[robot.number] = robot;
        }
    }*/

    auto robot = server->connectClient();              // подключаем клиента
    supervisorConnection = robot.connection;

    std::cout << game->robots[100].number;             // просто для проверки
    game->robots[100].velocity = {25, 30};

    while (true)                                       // игровой процесс
    {
        server->getData(supervisorConnection, game->robots);   // получение информации
        game->Run();                                              // игра принимает решение
        Server::sendData(game->robots);                        // отсылаем новую команду
        std::cout << std::endl << (counter++) << "\n";
    }

    return 0;
}
