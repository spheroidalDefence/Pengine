#include <string>
#include <SDL2/SDL.h>

using namespace std;

/* The main sprite class
 * serves as a holder for an image and its dimensions
 */
class Sprite{
public:
    Sprite(const char* arg_path);
    string getPath();
    SDL_Surface* getImg();
private:
    SDL_Surface* img;
    const char* path;
};

Sprite::Sprite(const char* arg_path){
    path = arg_path;
    img = SDL_LoadBMP(path);
}

SDL_Surface* Sprite::getImg(){
    return img;
}

string Sprite::getPath(){
    return path;
}
