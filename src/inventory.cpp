#include "inventory.hpp"

Inventory::Inventory(){};

Inventory::~Inventory(){};

std::map<Item, int> Inventory::createInventory()
{
    Item healthPotion("Health Potion", 50);
    Item grenade("Grenade", 80);
    Item greatSword("Great Sword", 180);
    Item battleAxe("Battle Axe", 220);
    Item dagger("Dagger", 50);
    Item longSword("Long sword", 120);

    _inventory[healthPotion] = 2;
    _inventory[grenade];
    _inventory[greatSword];
    _inventory[dagger]++;
    _inventory[longSword];
    _inventory[battleAxe];

    return _inventory;
}

bool Inventory::operator<(const Item &rhs) const
{
    return (_name < rhs._name);
}

void Inventory::subtractItem(Item item)
{
    if (_inventory[item] > 0)
    {
        _inventory[item]--;
    }
    else if (_inventory[item] <= 0)
    {
        throw SubtractItemException();
    }
}

void Inventory::addItem(Item item)
{

    _inventory[item]++;
    std::cout << "You bought one " << item.getName() << std::endl;
}

std::string Inventory::getItemN(Item item)
{
    return std::to_string(_inventory[item]);
}

void Inventory::displayInventory(PlayableCharacter *player)
{
    Item healthPotion("Health Potion", 50);
    Item grenade("Grenade", 80);
    Item greatSword("Great Sword", 180);
    Item battleAxe("Battle Axe", 220);
    Item dagger("Dagger", 50);
    Item longSword("Long sword", 120);

    Table inventoryT;

    inventoryT.add_row({"Item", "Amount"});
    inventoryT.add_row({"Grenades", getItemN(grenade)});
    inventoryT.add_row({"Health Potions", getItemN(healthPotion)});
    inventoryT.add_row({player->returnWeapon().getName(), "1"});
    inventoryT.format()
        .font_style({FontStyle::bold})
        .border_top(" ")
        .border_bottom(" ")
        .border_left(" ")
        .border_right(" ")
        .corner(" ");
    inventoryT[0].format().padding_top(1).padding_bottom(1).font_align(FontAlign::center).font_style({FontStyle::underline}).font_background_color(Color::red);
    std::cout << inventoryT << std::endl;

    // for (auto const &pair : _inventory)
    // {
    //     std::cout << "{" << pair.first.getName() << ": " << pair.second << "}"
    //               << " || ";
    // }
    // std::cout << std::endl;
}

int Inventory::checkValue(Item item)
{
    return _inventory.at(item);
}
