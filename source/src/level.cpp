//
// Created by Danny Javier Sandi on 10/21/15.
//

#include "level.h"
#include "graphics.h"
#include "SDL.h"
#include "SDL_image.h"
#include "globals.h"

Level::Level() { }

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
    _mapName(mapName), _spawnPoint(spawnPoint), _size(Vector2(0,0))
{
    this->loadMap(mapName,graphics);
}

Level::~Level(){

}

void Level::loadMap(std::string mapName, Graphics &graphics) {
    this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("content/backgrounds/bkBlue.png"));
    this->_size = Vector2(1280, 960);
}

void Level::update(int elapsedTime) { }

void Level::draw(Graphics &graphics) {
    SDL_Rect sourceRect = { 0, 0, 64, 64};
    SDL_Rect destRect;
    for(int x = 0; x < this->_size.x; x++){
        for(int y = 0; y < this->_size.y; y++){
            destRect.x = x * 64 * globals::SPRITE_SCALE;
            destRect.y = y * 64 * globals::SPRITE_SCALE;
            destRect.w = 64 * globals::SPRITE_SCALE;
            destRect.h = 64 * globals::SPRITE_SCALE;
            graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);
        }
    }
}