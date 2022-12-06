#include <iostream>
#include <string>
#include <exception>
#include "playableCharacter.hpp"
#include "weapon.hpp"
#include "monster.hpp"
#include "gameEvents.hpp"
#include <unistd.h>
#include "shop.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "inventory.hpp"
#include "vampire.hpp"
#include <stdlib.h>
#include "excecao.hpp"

int main()
{
    // system("canberra-gtk-play -f ./music/musica_jogo.wav");
    GameEvents game;
    char s;
    std::cout << "Choose a name for your character:" << std::endl;
    std::string playerName;
    std::cin >> playerName;
    std::cout << "Welcome to our RPG Battle Simulator, " << playerName << "!" << std::endl;
    PlayableCharacter player(playerName);
    PlayableCharacter *playerPtr = &player;
    // playerPtr->changeWeapon(availableWeapons.at(WEAPONS::DAGGER));

    Item healthPotion("Health Potion", 50, 1);
    Item grenade("Grenade", 80, 2);
    Item dagger("Dagger", 50, 3);
    Item longSword("Long sword", 120, 4);
    Item greatSword("Great Sword", 180, 5);
    Item battleAxe("Battle Axe", 220, 6);

    std::cout << "These are your starting items. You may buy new items in the shop anytime outside of battle by typing s" << std::endl;
    Inventory inventory;
    Inventory *inventoryPtr = &inventory;
    inventory.getItemN(healthPotion);
    inventory.createInventory();
    inventory.displayInventory(playerPtr);

    Enemy goblin(40, 40, "Goblin", 30, 30, 6, 2);   // gold, xpWorth, name, currentHP, maxHp, maxDamage, minDamage
    Enemy troll(235, 70, "Troll", 65, 65, 12, 4);   // gold, xpWorth, name, currentHP, maxHp, maxDamage, minDamage
    Enemy bandit(250, 90, "Bandit", 45, 45, 15, 6); // gold, xpWorth, name, currentHP, maxHp, maxDamage, minDamage
    Vampire vampire("Vampire", 100, 25, 8, 100);    // name, currentHp, maxDamage, minDamage, maxHp
    Enemy *goblinPtr = &goblin;
    Enemy *trollPtr = &troll;
    Enemy *banditPtr = &bandit;
    Vampire *vampirePtr = &vampire;
    // narracao inicial
    std::cout << "For three long days your have adventured in the Dark Woods, as you were summoned by the king of the realm to find and slay the Vampire that is haunting the kingdom. "
              << "Finally, you see a tower in the distance and praise the gods, as your supplies were barely enough for another day in the Dark Woods." << std::endl;
    std::cout << "Press (c) to continue or (s) to go to the store" << std::endl;

    while (1)
    {
        try
        {
            std::cin >> s;
            if (s != 's' || s != 'c')
                throw EntradaInvalidaException();
        }
        catch (EntradaInvalidaException &e)
        {
            if (s == 's' || s == 'c')
            {
                break;
            }
            std::cout << e.what() << std::endl;
        }
    }
    checkBuy(s, playerPtr, inventoryPtr);
    std::cout << "When you approach the tower you listen to a weird giggle that makes you shiver and fear for the worst!" << std::endl;

    std::cout << "Suddenly, a Goblin rushes towards you and attacks you!" << std::endl;

    // batalha com goblin
    // player.changeWeapon(availableWeapons.at(WEAPONS::GREATSWORD));
    game.battle(playerPtr, goblinPtr, inventoryPtr);

    std::cout << "You continue walking through the dense vegetation of the Dark Woods, trying to reach your objetive. "
              << "You can't see much but continue moving." << std::endl;

    std::cout << "When you get close enough to see the tower clearly you almost fall into a river! "
              << "Fortunately, you see a bridge. The only bad part is: it is guarded by a huge troll" << std::endl;
    std::cout << "Press (c) to continue or (s) to go to the store" << std::endl;

    while (1)
    {
        try
        {
            std::cin >> s;
            if (s != 's' || s != 'c')
                throw EntradaInvalidaException();
        }
        catch (EntradaInvalidaException &e)
        {
            if (s == 's' || s == 'c')
            {
                break;
            }
            std::cout << e.what() << std::endl;
        }
    }
    checkBuy(s, playerPtr, inventoryPtr);
    std::cout << "The troll says you cannot pass unless you spare him 20 coins." << std::endl;
    std::cout << "Would you like to (g) give him the coins or (b) battle the troll?" << std::endl;
    char trollChoice = 'x';
    while (trollChoice != 'g' && trollChoice != 'b')
    {
        std::cin >> trollChoice;
    }

    switch (trollChoice)
    {
    case 'g':
    {
        std::cout << "You reluctantly give the troll some of your coins" << std::endl;
        std::cout << "Thank you, stupid traveller. You may now proceed but be warned: you cannot defeat the Vampire. You are weak" << std::endl;
        player.subtractGold(20);
        std::cout << "You ignore the troll and keep moving" << std::endl;
        break;
    }
    case 'b':
    {
        std::cout << "You decide your coins are too precious to give away and proceed to battle the Troll." << std::endl;
        game.battle(playerPtr, trollPtr, inventoryPtr);
    }
    default:
    {
        break;
    }
    }

    // continua narracao

    std::cout << "After the two encounters you realize your journey will not be as easy as you thought it would be. "

              << "Nevertheless, you continue your journey as your mission is everything that matters to you." << std::endl;
    std::cout << "Press (c) to continue or (s) to go to the store" << std::endl;

    while (1)
    {
        try
        {
            std::cin >> s;
            if (s != 's' || s != 'c')
                throw EntradaInvalidaException();
        }
        catch (EntradaInvalidaException &e)
        {
            if (s == 's' || s == 'c')
            {
                break;
            }
            std::cout << e.what() << std::endl;
        }
    }
    checkBuy(s, playerPtr, inventoryPtr);

    std::cout << "You finally get to the gate of the tower and try to open it. Unfortunately it is locked." << std::endl;
    std::cout << "You start to get desperate and when you start to think of giving up a misterious mand approaches you." << std::endl;

    std::cout << "Hello there, traveler! Would you like this? The man shows you a rusty old key." << std::endl;
    std::cout << "Would you like to (t) take the key by force or (b) try buying the key?" << std::endl;
    char banditChoice = 'x';
    while (banditChoice != 'b' && banditChoice != 't')
    {
        std::cin >> banditChoice;
    }

    switch (banditChoice)
    {
    case 'b':
    {
        std::cout << "You offer the bandit some of your coins in exchange for the key." << std::endl;
        player.subtractGold(45);
        std::cout << "The misterious man says that is not enough for the key and persuades you into giving him five more coins." << std::endl;
        player.subtractGold(5);
        std::cout << "Humiliated, you get the key and enter the tower" << std::endl;
        break;
    }
    case 't':
    {
        std::cout << "You get very angry and decide to battle the man." << std::endl;
        game.battle(playerPtr, banditPtr, inventoryPtr);
    }
    default:
    {
        break;
    }
    }
    std::cout << "Finally, you enter the tower. Congratulations!" << std::endl;
    std::cout << "Press (c) to continue or (s) to go to the store" << std::endl;
    while (1)
    {
        try
        {
            std::cin >> s;
            if (s != 's' || s != 'c')
                throw EntradaInvalidaException();
        }
        catch (EntradaInvalidaException &e)
        {
            if (s == 's' || s == 'c')
            {
                break;
            }
            std::cout << e.what() << std::endl;
        }
    }
    checkBuy(s, playerPtr, inventoryPtr);

    std::cout << "You start climbing the stairs and feel a dark atmosphere surronding you. Everything seems to be rotten inside the tower."
              << " You get to a room with a black coffin and decide to open it." << std::endl;

    std::cout << "The vampire is resting inside and it seems it doesn't wake up when you open the coffin." << std::endl;
    std::cout << "As soon as you try to get a wooden stake inside its chest the vampire opens it's eyes and start floating towards you." << std::endl;

    std::cout << "Would you like to (r) run away or (a) attack the vampire?" << std::endl;
    char vampireChoice = 'x';
    while (vampireChoice != 'r' && vampireChoice != 'a')
    {
        std::cin >> vampireChoice;
    }

    switch (vampireChoice)
    {
    case 'r':
    {
        std::cout << "Unfortunately, you got so scare you couldn't bring yourself to do it. Everyday people die cause you couldn't do it." << std::endl;

        std::cout << "Over the years you get so depressed thinking about it you decide to abandon everything you lived for and become a gypsy." << std::endl;
        std::cout << "No one ever heard of " << playerName << " again." << std::endl;
        std::cout << "GAME OVER" << std::endl;
        abort();
    }
    case 'a':
    {
        std::cout << "You are so scared with the atmosphere and the situation you can barely getter enough strengh together to grab your weapon." << std::endl;
        std::cout << "Your rememeber your people and proudly engages in battle with the monster." << std::endl;
        game.finalBattle(playerPtr, vampirePtr, inventoryPtr);
    }
    default:
    {
        break;
    }
    }
    std::cout << "You return to the king and tell him everything that happened in your journey. He is so satisfied he promotes you to royal knight"
              << " and organizes a huge celebration to you. The people praise you as their savior and are forever grateful to you. Congratulations!" << std::endl;

    return 0;
}
