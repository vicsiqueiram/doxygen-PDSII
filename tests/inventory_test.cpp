#include "../third_party/doctest.h"
#include "../include/enemy.hpp"
#include "../include/monster.hpp"
#include "../include/utilities.hpp"
#include "../include/gameEvents.hpp"
#include "../include/inventory.hpp"
#include "../include/item.hpp"
#include "../include/playableCharacter.hpp"
#include "../include/shop.hpp"
#include "../include/weapon.hpp"
#include <iostream>

TEST_CASE("Test createInventory and subtractItem")
{
  Inventory inventory;
  inventory.createInventory();
  //consider that initially the inventory contains 2 Health Potions
 inventory.subtractItem(itemList.at(ITEMS::HEALTH_POTION));
  CHECK(inventory._inventory[itemList.at(ITEMS::HEALTH_POTION)]==1);
  inventory.subtractItem(itemList.at(ITEMS::HEALTH_POTION));
  CHECK(inventory._inventory[itemList.at(ITEMS::HEALTH_POTION)]==0);
  //Implementar um try_catch em subtractItem(item):void
  SUBCASE("Testing invalid option-substract item when _inventory[item]==0")
{
  CHECK_THROWS(inventory.subtractItem(itemList.at(ITEMS::HEALTH_POTION)));
  }
}

TEST_CASE("Test createInventory and addItem")
{
  //consider that initially the inventory contains 2 Health Potions
  Inventory inventory;
  inventory.createInventory();
  inventory.addItem(itemList.at(ITEMS::HEALTH_POTION));
  CHECK(inventory._inventory[itemList.at(ITEMS::HEALTH_POTION)]==3);
  inventory.addItem(itemList.at(ITEMS::HEALTH_POTION));
  inventory.addItem(itemList.at(ITEMS::HEALTH_POTION));
  CHECK(inventory._inventory[itemList.at(ITEMS::HEALTH_POTION)]==5);
  
}
    
