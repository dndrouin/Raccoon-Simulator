//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include "Raccoon.h"
#include "Item.h"
#include <string>
#include <iostream>
#include <algorithm>

//raccoon constructors

Raccoon::Raccoon(){
    preset=2;
    name="null";
    hunger=50;
    fun=50;
    care=50;
    age=0;

    hyper=false;
    smelly=false;
    dead=false;

    fedToday=false;
    caredToday=false;
    playedToday=false;

}

//adjustor methods for stats
//pass in a number and bool and if bool is true, adds the number to the current stats. otherwise subtracts

void Raccoon::adjustHunger(int num, bool adds){
    if(adds) {
        this->hunger += num;
        //do not let stats go over 100, which is the cap UNLESS raccoon is preset type 1 which has hunger cap set to 200 instead
        if (this->hunger > 100 && this->preset != 1){
            this-> hunger = 100;
        }
        else if(this->hunger > 200 && this->preset == 1){
            this->hunger = 200;
        }
    }
    else{
        this->hunger -= num;
    }
}

void Raccoon::adjustFun(int num, bool adds){
    if(adds) {
        this->fun += num;
        //do not let stats go over 100, which is the cap
        if (this->fun > 100){
            this-> care = 100;
        }
    }
    else{
        this->fun -= num;
    }
}

void Raccoon::adjustCare(int num, bool adds){
    if(adds) {
        this->care += num;
        //do not let stats go over 100, which is the cap
        if (this->care > 100){
            this-> care = 100;
        }
    }
    else{
        this->care -= num;
    }
}

//checkIfDead method, which checks the current stats of the raccoon to see if any are below zero. If they are,
//returns an integer representing what stat had hit zero or below and killed them, or returns zero if alive
int Raccoon::checkIfDead(){
    if(this->hunger == 0 || this->hunger < 0){
        return 1;
    }
    if(this->care == 0 || this->care < 0){
        return 2;
    }
    if(this->fun == 0 || this->fun < 0){
        return 3;
    }
    //raccoon is alive
    return 0;
}


//INVENTORY METHODS

//add an item to the inventory
void Raccoon::addItem(Item currentItem){

        if(currentItem.typeOfItem == 0){
            //item must be cosmetic, therefore is added to the closet
            this->closet.push_back(currentItem);
        }
        if(currentItem.typeOfItem == 1) {
            //item must be food, therefore is added to food inventory
            this->food.push_back(currentItem);
        }
        if(currentItem.typeOfItem == 2){
            //item must be care item, therefore is added to care inventory
            this->cares.push_back(currentItem);
        }
        if(currentItem.typeOfItem == 3) {
            //item must be toy, therefore is added to the play inventory
            this->play.push_back(currentItem);
        }
    }


//lists all of one type of item in inventory
void Raccoon::listItems(int type) {
    bool validEntry = false;
    std::string userEntry;
    int userEntryInt;

    //TODO: also include trash under play (for smelly buff)

    if (type == 0) {
        //list all cosmetic items (that aren't equipped)
        if (closet.empty()) {
            //if there's none, inform the user
            std::cout << "No items found.\n\n";
        } else {
            //otherwise, print their place in inventory and name
            for (int i = 0; i < closet.size(); i++) {
                std::cout << "\t" << i + 1 << ". " << closet[i].nameOfItem << "\n";
            }
        }
    }
    if (type == 1) {
        //list all food items
        if (food.empty()) {
            //if there's none, inform the user
            std::cout << "No items found.\n\n";
        } else {
            //otherwise, print their place in inventory and name
            for (int i = 0; i < food.size(); i++) {
                std::cout << "\t" << i + 1 << ". " << food[i].nameOfItem << "\n";
                //if last item, print the option to go back as well
                if (i == food.size() - 1) {
                    std::cout << "\t" << i + 2 << ". Back to the Menu\n";
                }
            }

            //ask the user if they would like to inspect an item or go back to menu
            //validEntry will not change until they enter a number (limited by the number of items in the inventory)
            while (!validEntry) {
                std::cout << "Enter the number of an item to inspect it, or enter the last number to go back.  ";
                std::cin >> userEntry;

                //try and catch to ensure only numbers are entered
                try {
                    userEntryInt = stoi(userEntry);
                }
                catch (const std::invalid_argument &e){
                    std::cout << "That isn't a number.\n";
                }

                if (userEntryInt > 0 && userEntryInt < food.size()) {
                    inspectItem(food[userEntryInt - 1]);
                } else if (userEntryInt - 1 == food.size()) {
                    //spacing to make everything less clumped together
                    std::cout << "\n";
                    validEntry = true;
                    //go back to the menu
                    //FIXME: this doesn't go back to the menu
                }
            }

        }
    }

    if(type == 2) {
        //list all care items
        if(cares.empty()){
            //if there's none, inform the user
            std::cout << "No items found.\n\n";
        }
        else {
            //otherwise, print their place in inventory and name
            for (int i = 0; i < cares.size(); i++) {
                std::cout << "\t" << i+1 << ". " << cares[i].nameOfItem << "\n";
            }
        }
    }
    if(type == 3) {
        //list all play items
        if(play.empty()){
            //if there's none, inform the user
            std::cout << "No items found.\n\n";
        }
        else {
            //otherwise, print their place in inventory and name
            for (int i = 0; i < play.size(); i++) {
                std::cout << "\t" << i+1 << ". " << play[i].nameOfItem << "\n";
            }
        }
    }
}


//useItem method which uses an item and subtracts a use off of it, if there are zero uses left it deletes the item using deconstructor
void Raccoon::useItem(Item& selected) {
    bool validResponse = false;
    std::string response;

    //item use is decided by what type the item is
    if (selected.typeOfItem == 0) {
        //item must be cosmetic. ask user if they would like to equip it to their raccoon
            while (!validResponse) {
                std::cout << "\nWould you like to equip this " << selected.nameOfItem << " to your Raccoon?";
                std::cin >> response;
                //user must give either Y or N as response otherwise it will keep asking them for one, Y or N turns validResponse true so they can exit the loop
                if (response.compare("Y") == 0) {
                    //user has chosen to equip the item to the raccoon
                    selected.equipped = true;
                    std::cout << "Your Raccoon looks fabulous in his new " << selected.nameOfItem << "!";
                    validResponse = true;
                } else if (response.compare("N") == 0) {
                    //do nothing? test out what happens first
                    std::cout << "\nReturning to inventory.\n";
                    validResponse = true;
                }
            }
        }
    if (selected.typeOfItem == 1) {
        //item must be food. ask user if they would like to feed it to their raccoon
        while (!validResponse) {
            std::cout << "\nWould you like to feed this " << selected.nameOfItem << " to " << this->name << "? Y/N\n";
            std::cin >> response;
            //user must give either Y or N as response otherwise it will keep asking them for one, Y or N turns validResponse true so they can exit the loop
            if (response.compare("Y") == 0) {
                //item is fed to the raccoon, if item has multiple uses, uses decrease. if uses hits 0, deconstructor is called and item is deleted
                if (selected.uses > 1) {
                    selected.uses--;
                    //adjusts hunger based on the change in stats stored in the item
                    this->adjustHunger(selected.changeInStats, true);
                    std::cout << "Your raccoon greedily consumes the food, raising his hunger stat by "
                              << selected.changeInStats << "!\n";
                } else {
                    //adjusts hunger based on the change in stats stored in the item
                    this->adjustHunger(selected.changeInStats, true);
                    std::cout << "Your raccoon greedily consumes the food, raising his hunger stat by "
                              << selected.changeInStats << "!\n";
                    //trashItem removes item from vector because no uses left
                    trashItem(selected);
                }
                //raccoon has been fed today, so bool fedToday turns to true and prevents user from feeding pet again for today only
                this->fedToday = true;
                validResponse = true;
            } else if (response.compare("N") == 0) {
                //do nothing? test out what happens first
                std::cout << "\nReturning to inventory.\n";
                validResponse = true;
            }
        }

    }
    if (selected.typeOfItem == 2) {
        //item must be a toy. ask user if they would like to use it to play with their raccoon
        while (!validResponse) {
            std::cout << "\nWould you like to use this " << selected.nameOfItem << " to play with " << this->name
                      << "? Y/N\n";
            std::cin >> response;
            //user must give either Y or N as response otherwise it will keep asking them for one, Y or N turns validResponse true so they can exit the loop
            if (response.compare("Y") == 0) {
                //item is used to play with the raccoon, if item has multiple uses, uses decrease. if uses hits 0, deconstructor is called and item is deleted
                if (selected.uses > 1) {
                    selected.uses--;
                    //adjusts fun based on the change in stats stored in the item
                    this->adjustFun(selected.changeInStats, true);
                    std::cout << "Your raccoon bats around the toy for a few minutes. His fun stat has increased by "
                              << selected.changeInStats << "!";
                } else {
                    //adjusts fun based on the change in stats stored in the item
                    this->adjustFun(selected.changeInStats, true);
                    std::cout << "Your raccoon bats around the toy for a few minutes. His fun stat has increased by "
                              << selected.changeInStats << "!";
                    //trashItem removes item from vector because no uses left
                    trashItem(selected);
                }
                //raccoon has been played with today, so bool playedToday turns to true and prevents user from playing with pet again for today only
                this->playedToday = true;
                validResponse = true;
            } else if (response.compare("N") == 0) {
                //do nothing? test out what happens first
                std::cout << "\nReturning to inventory.\n";
                validResponse = true;
            }
        }
    }
    if (selected.typeOfItem == 3) {
        //item must be for care. ask user if they would like to use it to care for their raccoon.
        while (!validResponse) {
            std::cout << "\nWould you like to care for your Raccoon using this " << selected.nameOfItem
                      << "? Y/N\n";
            std::cin >> response;
            //user must give either Y or N as response otherwise it will keep asking them for one, Y or N turns validResponse true so they can exit the loop
            if (response.compare("Y") == 0) {
                //item is used to care for the raccoon, if item has multiple uses, uses decrease. if uses hits 0, deconstructor is called and item is deleted
                if (selected.uses > 1) {
                    selected.uses--;
                    //adjusts care based on the change in stats stored in the item
                    this->adjustCare(selected.changeInStats, true);
                    std::cout
                            << "Your raccoon fights it at first, but after a minute allows you to take care of him. His care stat has been increased by "
                            << selected.changeInStats << "!";
                } else {
                    //adjusts care based on the change in stats stored in the item
                    this->adjustCare(selected.changeInStats, true);
                    std::cout
                            << "Your raccoon fights it at first, but after a minute allows you to take care of him. His care stat has been increased by "
                            << selected.changeInStats << "!";
                    //trashItem removes item from vector because no uses left
                    trashItem(selected);
                }
                //raccoon has been cared for today, so bool caredToday turns to true and prevents user from caring for pet again for today only
                this->caredToday = true;
                validResponse = true;
            } else if (response.compare("N") == 0) {
                //do nothing? test out what happens first
                std::cout << "\nReturning to inventory.\n";
                validResponse = true;
            }
        }
    }
}
//inspectItem which gives the user information about the item and asks them if they want to use it
void Raccoon::inspectItem(Item& selected){
    //shows item name, description, and gives user the option to use the item or return to the item list1
    std::string userEntry;

    //present item information to user
    std::cout << "\n\nInspect Item";
    std::cout << "\nName: " << selected.nameOfItem;
    std::cout << "\nDescription: " << selected.description;
    std::cout << "\nChange stat value: " << selected.changeInStats;
    std::cout << "\nUses left: " << selected.uses;

    //ask user if they want to use item or delete item
    std::cout<< "\nOptions\n";
    std::cout << "1. Use Item";
    std::cout << "2. Delete item";
    trashItem(selected);
    useItem(selected);
}

void Raccoon::trashItem(Item& selected){
    std::string target = selected.nameOfItem;
    std::string userEntry;
    bool validEntry;
    //deletes item from inventory

    //FIXME: this doesn't even compile, completely redo it

    //requires either Y or N confirmation that user wants to delete item
    while(!validEntry) {
        std::cout << "Are you sure you want to delete this " << target << "? This action is irreversible! Y/N \n";
        std::cin >> userEntry;
        if (userEntry.compare("Y") == 0) {
            if (selected.typeOfItem == 0) {
                //cosmetic so must be stored in closet vector
                //erase-remove idiom
                this->closet.erase(std::remove(this->closet.begin(), this->closet.end(), target), this->closet.end());
                std::cout << "\nItem trashed!\n";
            } else if (selected.typeOfItem == 1) {
                //food so must be stored in food vector
                //erase-remove idiom
                this->food.erase(std::remove(this->food.begin(), this->food.end(), target), this->food.end());
                std::cout << "\nItem trashed!\n";
            } else if (selected.typeOfItem == 2) {
                //care item so must be stored in care vector
                //erase-remove idiom
                this->cares.erase(std::remove(this->cares.begin(), this->cares.end(), target), this->cares.end());
                std::cout << "\nItem trashed!\n";
            } else if (selected.typeOfItem == 3) {
                //toy so must be stored in fun vector
                //erase-remove idiom
                this->play.erase(std::remove(this->play.begin(), this->play.end(), target), this->play.end());
                std::cout << "\nItem trashed!\n";
            }
            validEntry = true;
        } else if (userEntry.compare("N") == 0) {
            //just go back to menu
            validEntry = true;
        }
    }
}


