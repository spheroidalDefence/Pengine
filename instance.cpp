#include <string>
#include <SDL2/SDL.h>
#include "object.h"

using namespace std;

/* The main instance class
 * is a instance of an object that can be seen (or not) in a room
 */
class Instance{
public:
    Instance(Object* obj, long int arg_x, long int arg_y);
    void setPos(int x, int y);
    void setRelPos(int x, int y);
    Object* getObj();
    SDL_Rect* getPos();
private:
    Object* pObj;
    SDL_Rect pos;
};

Instance::Instance(Object* obj, long int arg_x, long int arg_y){
    pObj = obj;
    pos.x = arg_x;
    pos.y = arg_y;
}

void Instance::setPos(int x, int y){
    pos.x = x;
    pos.y = y;
}

void Instance::setRelPos(int x, int y){
    pos.x += x;
    pos.y += y;
}

Object* Instance::getObj(){
    return pObj;
}

SDL_Rect* Instance::getPos(){
    SDL_Rect* pPos = &pos; 
    return pPos;
}
