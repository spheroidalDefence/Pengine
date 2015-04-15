#include <string>
#include "sprite.h"

using namespace std;

/* The main object class
 * serves as a template for instances to use
 */
class Object{
public:
    Object(Sprite* spr);
    Sprite* getSpr();
private:
    Sprite* pSpr;
};

Object::Object(Sprite* spr):
    pSpr(spr)
{}

Sprite* Object::getSpr(){
    return pSpr;
}
