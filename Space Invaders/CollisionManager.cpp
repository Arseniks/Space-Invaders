#include "CollisionManager.h"

bool CollisionManager::collidesWith(Ship& obj1, Enemy& obj2)
{
    sf::FloatRect ship;

    ship.left = obj1.getSprite().getPosition().x + 10;
    ship.top = obj1.getSprite().getPosition().y + 10;

    ship.width = obj1.getSprite().getGlobalBounds().width - 10;
    ship.height = obj1.getSprite().getGlobalBounds().height - 10;

    sf::FloatRect alien;

    alien.left = obj2.getSprite().getPosition().x;
    alien.top = obj2.getSprite().getPosition().y;

    alien.width = obj2.getSprite().getGlobalBounds().width;
    alien.height = obj2.getSprite().getGlobalBounds().height;

    return ship.intersects(alien);

}

bool CollisionManager::collidesWith(Bullet& obj1, Enemy& obj2)
{

    sf::FloatRect bullet;

    bullet.left = obj1.getSprite().getPosition().x + 10;
    bullet.top = obj1.getSprite().getPosition().y + 10;

    bullet.width = obj1.getSprite().getGlobalBounds().width - 10;
    bullet.height = obj1.getSprite().getGlobalBounds().height - 10;


    sf::FloatRect alien;

    alien.left = obj2.getSprite().getPosition().x;
    alien.top = obj2.getSprite().getPosition().y;

    alien.width = obj2.getSprite().getGlobalBounds().width;
    alien.height = obj2.getSprite().getGlobalBounds().height;

    return bullet.intersects(alien);

}


bool CollisionManager::collidesWith(EnemyBullet& obj1, Ship& obj2)
{

    sf::FloatRect enemybullet;

    enemybullet.left = obj1.getSprite().getPosition().x + 10;
    enemybullet.top = obj1.getSprite().getPosition().y + 10;

    enemybullet.width = obj1.getSprite().getGlobalBounds().width - 10;
    enemybullet.height = obj1.getSprite().getGlobalBounds().height - 10;


    sf::FloatRect ship;

    ship.left = obj2.getSprite().getPosition().x;
    ship.top = obj2.getSprite().getPosition().y;

    ship.width = obj2.getSprite().getGlobalBounds().width;
    ship.height = obj2.getSprite().getGlobalBounds().height;

    return enemybullet.intersects(ship);

}