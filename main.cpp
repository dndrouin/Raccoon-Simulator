//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//


#include <iostream>
#include <sstream>
#include <limits>
#include "Raccoon.h"
#include "RaccoonMethods.h"
#include "ProgramMethods.h"
#include "Item.h"

using namespace std;


int main() {

    string userEntry;
    int actionChosen;
    fstream saveFile;
    bool gameEnded = false, validEntry = false, goBack = false;
    int counter=0;
    Raccoon* pet = new Raccoon();


    //greet user and give them option of a new game or loading a previous game
    cout<<"R A C C O O N  S I M U L A T O R\nby Danielle Drouin (github.com/dndrouin)\n\n";

    //validEntry will only become true if the user has provided either 1 or 2. anything else will prompt the user again to select an action
    while(!validEntry) {
        cout << "MAIN MENU\n1. New Raccoon\n2. Load Last Raccoon\nWhat action would you like to take? Enter it here: ";
        cin >> userEntry;
        if(userEntry.compare("1") == 0 || userEntry.compare("2") == 0){
            actionChosen = stoi(userEntry);
            validEntry = true;
        }
    }

    //reset validEntry for reuse
    validEntry = false;

    if(actionChosen == 1){

        //Create a new raccoon
        while(!validEntry) {

            //list the available types of raccoons to allow the user to pick which one they would like to adopt
            raccoonTypesList();
            cout<<"\n What number raccoon would you like? Enter it here: ";
            cin >> userEntry;

            //limit user entry to just the available options
            if(userEntry.compare("1") == 0 || userEntry.compare("2") == 0  || userEntry.compare("3") == 0 ){
                actionChosen = stoi(userEntry);
            }
            validEntry = true;
        }

        //reset validEntry for later reuse
        validEntry = false;

        while(!validEntry){

            //do not allow user to name raccoon null, because "null" is the default name of a raccoon object and how the program tells if a saved raccoon exists to load when Load Last Raccoon is selected
            cout<<"Enter a name for your raccoon here: ";

            //flush cin buffer so getline functions correctly
            cin.ignore (numeric_limits<std::streamsize>::max(), '\n');

            //receive user entry (allows spaces!)
            getline(cin,userEntry);
            if(userEntry.compare("null") != 0 && !userEntry.empty()){
                validEntry = true;
            }
            else{
                cout << "You can't name your pet that. Try again.\n";
            }
        }

        //reset validEntry for later reuse
        validEntry = false;

        //store user choices in premade raccoon object
        pet->preset = actionChosen;
        pet->name = userEntry;

        //give user some items to start with in their inventory
        giveStarterItems(pet);

        //save game
        cout<<"\nRaccoon adopted successfully.\n";
        saveGame(pet);
        cout <<"Autosaved!\n\n";

    }
    else if(actionChosen == 2){

        //open the most recent save file
        saveFile.open("save.txt", ios_base::in);
        string parseSave, token;

        //put contents of file into a string called parseSave and then split it up and store each piece in raccoon's stats because data is separated by delimiter '#'
        getline(saveFile, parseSave);
        stringstream ss(parseSave);

        while(getline(ss, token, '#')){

            //store the split pieces of data depending on what number counter is at
            if(counter == 0){
                // set preset number
                pet->preset = stoi(token);
            }
            else if(counter == 1){
                // set name
                pet->name = token;
            }
            else if(counter == 2){
                //set hunger
                pet->hunger = stoi(token);
            }
            else if(counter == 3){
                //set fun
                pet->fun = stoi(token);
            }
            else if(counter == 4){
                //set care
                pet->care = stoi(token);
            }
            else if(counter == 5){
                //set hyper
                pet->hyper = stoi(token);
            }
            else if(counter == 6){
                //set smelly
                pet->smelly = stoi(token);
            }
            else if(counter == 7){
                //set dead
                pet->dead = stoi(token);
            }
            else if(counter == 8){
                //set age
                pet->age = stoi(token);
            }
            counter++;
        }
        if(pet->name.compare("null") == 0){
            cout << "Save file not found. Please restart the game and select 'New Raccoon' instead.";
            gameEnded = true;
        }
    }

    //while raccoon is alive and the user hasn't selected save and exit, keep running the program
    while(!pet->dead && !gameEnded){

        //show user the navigation menu and allow them to pick what to do
        cout<<"\nMAIN MENU\n\t1. Stats \n\t2. Feed \n\t3. Play \n\t4. Care \n\t5. Store \n\t6. Advance to the next day\n\t7. Save & Exit\n";
        cout<<"Select an action:\n";
        cin >> userEntry;

        //try and catch to ensure only numbers are entered
        try {
            actionChosen = stoi(userEntry);
        }
        catch (const std::invalid_argument &e){
            std::cout << "That isn't a number.\n";
        }

        //if user enters 1, show current raccoon stats
        if(actionChosen == 1){

            //when user is done viewing stats, must enter the word "ok" to go back to main menu. this will make goBack true and then they can exit the while loop
            while(!goBack) {
                cout << pet->name << "'s Stats\n";
                cout << "Age: " << pet->age;

                    //proper grammar - if age is 1 then don't add an 's' to the end of 'day'
                    if(pet->age == 1){
                        cout << " day";
                    }
                    else{
                        cout << " days";
                    }
                    cout << " old\n";
                cout << "Hunger: " << pet->hunger << "/100\n";
                cout << "Fun: " << pet->fun << "/100\n";
                cout << "Care: " << pet->care << "/100\n";
                while(!validEntry) {
                    cout << "Enter 'ok' to return to the menu: ";
                    cin >> userEntry;

                    //if user enters "ok", bring user back to navigation menu by setting goBack to true. any other input will repeat the instruction
                    if(userEntry.compare("ok") == 0){
                        validEntry = true;
                    }

                }
                goBack = true;
            }

            //reset goBack and validEntry for reuse elsewhere
            goBack = false;
            validEntry = false;

            //newline to make everything a little more readable and spaced out
            cout << "\n";
        }
        else if(actionChosen == 2){
            //feed
            cout << "Food in your inventory:\n";
            pet->listItems(1);

        }
        else if(actionChosen == 3){
            //play
            cout << "Toys in your inventory:\n";
            pet->listItems(2);
        }
        else if(actionChosen == 4){
            //care
            cout << "Care items in your inventory:\n";
            //TODO: figure out why this lists the wrong items
            pet->listItems(3);
        }
        else if(actionChosen == 5){
            //store
            //TODO: lists items user can buy to put in their inventory and use on their raccoon but first probably think
            // of a way that the user can get money, because otherwise this makes no sense
        }
        else if(actionChosen == 6){
            //advance to next day

            //user must type 'ok' when prompted to leave the while loop and continue back to the menu
                cout << "\n\nTaking care of " + pet->name + " is exhausting work, so you decide to take a quick nap.\n";
                statDecay(pet);
                cout << "Suddenly, you open your eyes and you realize it's the next day! So much for a quick nap...\n";

                //check if pet died after statdecay
                if(pet->checkIfDead() > 0){
                    //pet has died, set to true so the game will end
                    pet->dead = true;
                }

                //proper grammar - if age is 1 then don't add an 's' to the end of 'day'
                if (pet->age == 1) {
                    cout << pet->name << " is now " << pet->age << " day old!\n";
                } else {
                    cout << pet->name << " is now " << pet->age << " days old!\n";
                }
            while(!goBack) {
                cout << "Enter 'ok' to continue to the menu: ";
                cin >> userEntry;

                //if user enters "ok", bring user back to navigation menu by setting goBack to true
                if (userEntry.compare("ok") == 0) {
                    goBack = true;
                }
            }

        //formatting
        cout << "\n";

        //reset goBack for future use
        goBack = false;

        }
        else if(actionChosen == 7){
            //save and exit
            saveGame(pet);
            cout << "Save successful.\n";
            cout << "Come back and play again soon! Your raccoon will miss you.";
            //end the game
            gameEnded = true;

        }
        else if(actionChosen > 7 || actionChosen < 1){

            //user has entered a number that isn't a choice
            cout << "Invalid selection.\n";
        }
    }

    //if the raccoon dies, end the game and inform the user what they did to kill them
    if(pet->dead){
        if(pet->checkIfDead() == 1) {

            //raccoon died from hunger
            cout << "\n\nUnfortunately, " << pet->name << " has passed away at the ripe old age of " << pet->age
                 << " from starvation.\n";
            cout << "TIP: Much like cats, dogs, fish, and even humans, raccoons have to regularly eat to stay alive.\n";
            cout << "GAME OVER";
        }
        if(pet->checkIfDead() == 2) {

            //raccoon died from care
            cout << "\n\nUnfortunately, " << pet->name << " has passed away at the ripe old age of " << pet->age
                 << " from heartbreak caused by lack of care.\n";
            cout << "TIP: It's generally considered cruel to adopt an animal and then not take care of it.\n";
            cout << "GAME OVER";
        }
        if(pet->checkIfDead() == 3) {

            //raccoon died from boredom
            cout << "\n\nUnfortunately, " << pet->name << " has passed away at the ripe old age of " << pet->age
                 << " from boredom due to lack of fun.\n";
            cout << "TIP: Fish have no concept of fun, and therefore might be a better pet for you.\n";
            cout << "GAME OVER";
        }
        if(pet->checkIfDead() == 0) {

            //pet is alive therefore the game should still be running and this message should never show under any circumstance
            cout << "If you see this, you've broken the game. Try not to do whatever you just did again. Thanks! - Danielle";
        }
    }

    return 0;
}

