#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;

void diaplay_main_menu();
void diaplay_admin_menu();
void list_all_entities();
void create_entity();
void delete_entity();
int check_admin_password();
void Edit_entity();
int avoid_entity_match();
int avoid_Voter_match();
void cast_vote();
void voting_termination();


int input;
string password = "admin12345";
string input_password;


int EntityList[10] = {0};
string EntityName[10] = {"N","N","N","N","N","N","N","N","N","N"};
string EntityProperty1[10] = {"N","N","N","N","N","N","N","N","N","N"};
string EntityProperty2[10] = {"N","N","N","N","N","N","N","N","N","N"};

int VoterList[100] = {0};
string VoterName[100] = {""};
string VoterCNIC[100] = {""};
string VoterSelection[100] = {""};


int main() {
    diaplay_main_menu();
    return 0;
}

void diaplay_main_menu() {
    system("cls");
    cout << "Smart Voting System\n\n";
    cout << "\tMain Menu\n";
    cout << "Enter 1 to go to Admin\n";
    cout << "Enter 2 to cast Vote\n";
    cout << "Enter 3 to Exit\n";

    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

    if(input == 1){
    	if(check_admin_password() == 1){
    		diaplay_admin_menu();
		}
		else if(check_admin_password() == 0){
			        cout << "Wrong Password!" << endl;
        Sleep(1500);
        diaplay_main_menu();
		}
        
    }
    else if(input == 2){
        cast_vote();
    }
    else if(input == 3){
        exit(0); // Exit cleanly
    }
    else {
        cout << "Wrong Input!" << endl;
        Sleep(1500);
        diaplay_main_menu();
    }
}

int check_admin_password() {
	    system("cls");
            cout << "Enter Admin Password: ";
            getline(cin, input_password);
            if(input_password == password){
            	return 01;
            	}
    else {
        return 0;
        
    }

}


void diaplay_admin_menu() {
	

    system("cls");
    cout << "Smart Voting System\n\n";
    cout << "\tAdmin Menu\n";
    cout << "Enter 1 to create Entity\n";
    cout << "Enter 2 to Edit Entity\n";
    cout << "Enter 3 to Delete Entity\n";
    cout << "Enter 4 to terminate Voting\n";
    cout << "Enter 5 to go to Main Menu\n";

    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

    if(input == 1){
        create_entity();
    }
    else if(input == 2){
        Edit_entity();
    }
    else if(input == 3){
        delete_entity();
    }
    else if(input == 4){
        voting_termination();
    }
    else if(input == 5){
        diaplay_main_menu();
    }
    else {
        cout << "Wrong Input!" << endl;
        Sleep(1500);
        diaplay_admin_menu();
    }

}

void delete_entity() {
	list_all_entities();
    cout << "\nEnter serial number of entity to be delated.\nor 0 to go back: ";
    
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

    if(input == 0){
        diaplay_admin_menu();
    }
    else if(input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6 || input == 7 || input == 8 || input == 9 || input == 10){
EntityName[input-1] = "";
EntityProperty1[input-1] = "";
EntityProperty2[input-1] = "";
EntityList[input-1] = 0;
        cout << "Entity Deleted!" << endl;
        Sleep(1500);
        diaplay_admin_menu();
    }
    else {
        cout << "Wrong Input!" << endl;
        Sleep(1500);
        diaplay_admin_menu();
    }
}


void list_all_entities() {
    system("cls");
    cout << "\tEntity List\n\n";
    bool found = false;
    for(int i = 0; i < 10; i++) {
        if(EntityList[i] == 1) {
            cout << i + 1 << ". " << EntityName[i] << endl;
            found = true;
        }
    }
    if(!found) {
        cout << "No entities available.\n";
    }
//    cout << "\nPress Enter to return to menu...";
//    cin.get();
//    diaplay_main_menu();
}

void create_entity() {
    system("cls");
    for (int i = 0; i < 10; i++) {
        if (EntityList[i] == 0) {
            cout << "Enter Name of Entity: ";
            getline(cin, EntityName[i]);

            cout << "Enter Property 1: ";
            getline(cin, EntityProperty1[i]);

            cout << "Enter Property 2: ";
            getline(cin, EntityProperty2[i]);

            EntityList[i] = 1;
            cout << "Entity Created Successfully!\n";
            Sleep(1500);
            break; // Only one entity created per call
        }
    }
    diaplay_admin_menu();
}


void Edit_entity() {
		list_all_entities();
    cout << "\nEnter serial number of entity to be Edited.\nor 0 to go back: ";
    
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

    if(input == 0){
        diaplay_admin_menu();
    }
    else if(input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6 || input == 7 || input == 8 || input == 9 || input == 10){
    	system("cls");
		cout << "Name: "<<EntityName[input-1] << endl;
		cout << "EntityProperty1: "<<EntityProperty1[input-1] << endl;
		cout << "EntityProperty2: "<<EntityProperty2[input-1] << endl;
		
		

        cout << "Enter New Name: ";
        getline(cin, EntityName[input-1]);
        cout << "Enter New EntityProperty1: ";
        getline(cin, EntityProperty1[input-1]);
        cout << "Enter New EntityProperty2: ";
        getline(cin, EntityProperty2[input-1]);
        
                    
         cout << "Entity Edited Successfully!\n";
        
        
        Sleep(1500);
        diaplay_admin_menu();
    }
    else {
        cout << "Wrong Input!" << endl;
        Sleep(1500);
        diaplay_admin_menu();
    }
	
	}
	
	
	
	
	void cast_vote() {
	list_all_entities();
    cout << "\nEnter serial number of entity to be Voted.\nor 0 to go back: ";
    
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
	
	
	    if(input == 0){
        diaplay_admin_menu();
    }
    else if(input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6 || input == 7 || input == 8 || input == 9 || input == 10){
    	
    	    for(int i = 0; i < 100; i++) {
        if(VoterList[i] == 0) {
VoterSelection[i] = EntityName[input-1];
        cout << "Enter your Name: ";
        getline(cin, VoterName[i]);
        cout << "Enter your CNIC: ";
        getline(cin, VoterName[i]);
        VoterList[i] = 1;
        break;
        }
    }
    	
        cout << "Vote Casted Successfully!" << endl;
        Sleep(1500);
        diaplay_main_menu();
    }
    else {
        cout << "Wrong Input!" << endl;
        Sleep(1500);
        diaplay_main_menu();
    }	
		
		
	}
	
	
void voting_termination() {
			
	system("cls");
    cout << "\tVoting Terminationt\n\n";
    cout <<" " << "Entity Name"<<"\t" << "No Of Votes" << endl;
    for(int i = 0; i < 10; i++) {
    	if(EntityList[i] == 1){
		
    	int NoOfVotes = 0;
    	for(int j = 0; j < 100; j++) {
		if(VoterSelection[j] == EntityName[i]){ NoOfVotes++;}
		
		}
    	
        cout << i + 1 << ". " << EntityName[i]<<"\t" << NoOfVotes << endl;
            
        }
        
        
    }
}
