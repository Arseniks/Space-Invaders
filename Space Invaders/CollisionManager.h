#pragma once
#ifndef SpriteMove_CollisionManager_h
#define SpriteMove_CollisionManager_h

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include <iostream>

class CollisionManager
{
public:
    static bool collidesWith(Ship&, Enemy&);
    static bool collidesWith(Bullet&, Enemy&);
    static bool collidesWith(EnemyBullet&, Ship&);

private:
};

#endif