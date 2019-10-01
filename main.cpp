//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//


#include <iostream>
#include <fstream>
#include <sstream>
#include "Raccoon.h"
#include "RaccoonMethods.cpp"

using namespace std;


int main() {

    string userEntry;
    int actionChosen;
    fstream saveFile;
    bool gameEnded = false, validEntry = false, ok = false;
    int counter=0;
    Raccoon* pet = new Raccoon();

    //TODO: completely overhaul user greeting to make it actually interesting

    //greet user and give them option of a new game or loading a previous game
    cout<<"R A C C O O N  S I M U L A T O R  2 0 1 9\nby Danielle Drouin (github.com/dndrouin)\n\n";
    //validEntry will only become true if the user has provided either 1 or 2. anything else will prompt the user again to select an action
    while(!validEntry) {
        cout << "Select an action:\n1. New Raccoon\n2. Load Last Raccoon\n\n";
        cin >> userEntry;
        //TODO: stop letters and symbols from being entered
        actionChosen = stoi(userEntry);
        if(actionChosen > 0 && actionChosen < 3){
            validEntry = true;
        }
    }

    //reset validEntry for reuse
    validEntry = false;

    if(actionChosen == 1){
        //Create a new raccoon
	//TODO: fix raccoonTypesList method so raccoons can be described to user before they pick
        while(!validEntry) {
            //raccoonTypesList();
            cout<<"There are 3 raccoons to pick from. What one would you like? Enter the number here: ";
            cin >> userEntry;
            actionChosen = stoi(userEntry);
            if(actionChosen > 0 && actionChosen < 4){
                validEntry = true;
            }
        }
        //TODO: limit user entry to less than 3 and above 0 no letters etc
        actionChosen = stoi(userEntry);
        cout<<"Enter a name for your raccoon here: ";
        //TODO: allow spaces, do not allow symbols
        cin >> userEntry;

        //store user choices in premade raccoon object
        pet->preset = actionChosen;
        pet->name = userEntry;

        cout<<"Raccoon created successfully.\n\n";
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
                //set fun
                pet->care = stoi(token);
            }
            else if(counter == 5){
                //set fun
                pet->hyper = stoi(token);
            }
            else if(counter == 6){
                //set fun
                pet->smelly = stoi(token);
            }
            else if(counter == 7){
                //set fun
                pet->dead = stoi(token);
            }
            counter++;
        }
    }

    //while raccoon is alive and the user hasn't seelcted save and exit, keep running the program
    while(!pet->dead && !gameEnded){
        //TODO: stop letters and symbols from being entered
        //show user the navigation menu and allow them to pick what to do
        cout<<"Select an action:\n\t1. Stats \n\t2. Feed \n\t3. Play \n\t4. Care \n\t5. Store \n\t6. Inventory \n\t7. Save & Exit\n\n";
        cin >> userEntry;
        actionChosen = stoi(userEntry);

        //if user enters 1, show current raccoon stats
        if(actionChosen == 1){
            //when user is done viewing stats, must enter number 1 to go back to main menu. this will make ok true and then they can exit the while loop
            while(!ok) {
                cout << pet->name << "'s Stats\n";
                cout << "Hunger: " << pet->hunger << "/100\n";
                cout << "Fun: " << pet->fun << "/100\n";
                cout << "Care: " << pet->care << "/100\n";
                cout << "Enter '1' to return to the menu.";
                cin >> userEntry;
                if (stoi(userEntry) == 1) {
                    ok = true;
                }
            }
            //reset ok for reuse elsewhere
            ok = false;
        }
        else if(actionChosen == 2){
            //feed
            //TODO: feed, which will list possible food items in inventory to user to feed to their raccoon and will increase their hunger bar, coffee will set raccoons hyper bool to true
        }
        else if(actionChosen == 3){
            //play
            //TODO: play, which will list possible play items in inventory to user to play with their raccoon and will increase their fun bar
        }
        else if(actionChosen == 4){
            //care
            //TODO: care, which will ask user if they want to pet, cuddle or wash their raccoon and will increase care bar and wash sets raccoon's smelly bool to false
        }
        else if(actionChosen == 5){
            //store
            //TODO: lists items user can buy to put in their inventory and use on their raccoon
            //TODO: think of a way that the user can get money in the first place, because otherwise this makes no sense
        }
        else if(actionChosen == 6){
            //inventory
            //TODO: lists all items regardless of type in the user's inventory. separate subsection for items equipped to raccoon, maybe?
        }
        else if(actionChosen == 7){
            //save and exit
            //creates file and writes raccoon data to it. if file already exists, it will overwrite it.
            saveFile.open("save.txt", ios_base::out);
            saveFile << pet->preset << pet->name << "#" << pet->hunger << "#" << pet->fun << "#" << pet->care << "#" << pet->hyper << "#" << pet->smelly << "#" << pet->dead << "#";
            saveFile.close();
            cout << "Save successful.\n";
            cout << "Come back and play again soon! Your raccoon will miss you.";
            //end the game
            gameEnded = true;

        }
        else if(actionChosen > 7 || actionChosen < 1){
            //user has entered a number that isn't a choice
            //TODO: account for letters and symbols
            cout << "Invalid selection.";
        }




    }





    return 0;
}

