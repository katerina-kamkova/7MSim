#include "game.h"

Game::~Game() {
    robots.clear();
}

void Game::Run() {
    int velocity = robots[100].velocity.left;
    if (velocity >= 30) robots[100].velocity.left = 0;
    else robots[100].velocity.left ++;
}
