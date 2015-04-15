#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "sprite.h"
#include "object.h"
#include "instance.h"

using namespace std;

/* The main game class
 * holds everything that operates Pengine
 */

class Game{
public:
    Game(int SCR_W, int SCR_H, const char* cap);
    SDL_Window* window;
    SDL_Surface* screen;
    vector<string> getEvents();
    Object* addObject(Sprite* sprite);
    Sprite* addSprite(const char* path);
    Instance* addInstance(Object* obj, long int x, long int y);
    void updateGame();
    void close();
    void delay(int time);
private:
    vector<Instance*> instances;
    vector<Object*> objects;
    vector<Sprite*> sprites;
    vector<string> events;
};

//The main constructor for the game class
Game::Game(int SCR_W, int SCR_H, const char* cap){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(cap, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    screen = SDL_GetWindowSurface(window);
}

//The main update method for game. Updates the graphics
void Game::updateGame(){
    SDL_FillRect(screen, NULL, SDL_MapRGB( screen->format, 255, 255, 255));
    for(unsigned int i = 0; i < instances.size(); i++){
        SDL_BlitSurface(instances[i]->getObj()->getSpr()->getImg(), NULL, screen, instances[i]->getPos());
    }
    //Event handling... Oh boy!
    SDL_Event e;
    events.clear();
    while(SDL_PollEvent(&e) != 0){
        if( e.type == SDL_QUIT ){
            close();
        }
        else if(e.type == SDL_KEYDOWN){
            switch(e.key.keysym.sym){
            case SDLK_UP: events.push_back("up");
            continue;
            case SDLK_DOWN: events.push_back("down");
            continue;
            case SDLK_LEFT: events.push_back("left");
            continue;
            case SDLK_RIGHT: events.push_back("right");
            continue;
            }
        }
    }
    //Updates screen
    SDL_UpdateWindowSurface(window);
}

//Returns a vector of all the events in strings
vector<string> Game::getEvents(){
    return events;
}

//Adds an object to the list of objects in a game
Object* Game::addObject(Sprite* sprite){
    Object* pObj = new Object(sprite);
    objects.push_back(pObj);
    return pObj;
}

//Adds an object to the list of objects in a game
Sprite* Game::addSprite(const char* path){
    Sprite* pSpr = new Sprite(path);
    sprites.push_back(pSpr);
    return pSpr;
}

Instance* Game::addInstance(Object* obj, long int x, long int y){
    Instance* pIns = new Instance(obj, x, y);
    instances.push_back(pIns);
    return pIns;
}

//Creates a sleep
void Game::delay(int time){
    SDL_Delay(time);
}

//Prevents memory leaks :)
void Game::close(){
    for(unsigned int o = 0; o < objects.size(); ++o){
        delete objects[o];
    }
    for(unsigned int s = 0; s < sprites.size(); ++s){
        delete sprites[s];
    }
    for(unsigned int i = 0; i < instances.size(); ++i){
        delete instances[i];
    }
    SDL_Quit();
    exit(0);
}
