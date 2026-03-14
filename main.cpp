#include <iostream>
#include "flight.h"
using namespace std;
int main(){
    //Console loop
    string raw_command;
    while(true){
        cout << "Please enter a command (/h for help):" << endl;
        getline(cin, raw_command);

        if(raw_command == "/h"){
            cout << "|HELP| List of functions" << endl;
            //ADD MORE COMMANDS HERE
        }
        else if(raw_command == "/quit"){
            break;
        }
        else{
            cout << "Command not recognized" << endl;
        }
    }
    return 0;
}