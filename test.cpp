#include "game.h"

int main(){
    Game* game = new Game(640, 480, "GaNonder");
        
    Sprite* spr_player = game->addSprite("img.bmp");
    Sprite* spr_enemy = game->addSprite("img2.bmp");
    
    Object* obj_player = game->addObject(spr_player);
    Object* obj_enemy = game->addObject(spr_enemy);
    
    Instance* ins_player = game->addInstance(obj_player, 120, 160);
    
    Instance* enemies[5];
    for(int i = 0; i < 5; ++i){
        enemies[i] = game->addInstance(obj_enemy, i * 64, i * 48);;
    }
    
    while(1){
        game->delay(5);
        game->updateGame();
        vector<string> events = game->getEvents();
        for(unsigned int k = 0; k < 5; ++k){
            enemies[k]->setRelPos(1, 0);
        }
        for(unsigned int e = 0; e < events.size(); ++e){
            if(events[e] == "up"){
                ins_player->setRelPos(0, -16);
            }
            if(events[e] == "down"){
                ins_player->setRelPos(0, 16);
            }
            if(events[e] == "right"){
                ins_player->setRelPos(16, 0);
            }
            if(events[e] == "left"){
                ins_player->setRelPos(-16, 0);
            }
            if(events[e] == ""){
                
            }
        }    
    }
    
    game ->close();
    
    delete game;
    return 0;
}
