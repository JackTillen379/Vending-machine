#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

// Function/Class declaration
void display();
void buy();
void recommend(string prevItem);

// Item Class
struct Item {
	string position;
	string itemName;
	double price;
	int stock;
	string type;

	Item(string position_, string itemName_, double price_, int stock_, string type_) {
		itemName = itemName_;
		price = price_;
		stock = stock_;
		position = position_;
		type = type_;
	}
};

// Pointer vector to 'Item' class items
vector<Item*> items;

// Banking system for the user
double cash = cash;

int main() {

	// Creates objects for our vending machine
	Item coke("A1", "Coke", 0.50, 4, "Cold Drink"); items.push_back(&coke);
	Item fanta("A2","Fanta", 0.75, 7, "Cold Drink"); items.push_back(&fanta);
	Item sprite("A3", "Sprite", 0.69, 8, "Cold Drink"); items.push_back(&sprite);
	Item water("B1", "Water", 1.00, 9, "Cold Drink"); items.push_back(&water);
	Item snickers("B2", "Snickers", 1.25, 3, "Snacks"); items.push_back(&snickers);
	Item marsBar("B3", "Mars Bar", 1.20, 5, "Snacks"); items.push_back(&marsBar);
	Item yorkie("C1", "Yorkie", 1.20, 7, "Snacks"); items.push_back(&yorkie);
	Item rolos("C2", "Rolos", 1.35, 2, "Snacks"); items.push_back(&rolos);
	Item galaxy("C3", "Galaxy", 1.15, 4, "Snacks"); items.push_back(&galaxy);
	Item tea("D1", "Tea", 2.50, 5, "Hot Drink"); items.push_back(&tea);
	Item coffee("D2", "Coffee", 2.50, 7, "Hot Drink"); items.push_back(&coffee); 
	Item hotChocolate("D3", "Hot Chocolate", 2.50, 2, "Hot Drink"); items.push_back(&hotChocolate);
	
	cout << "--------------" << endl;
	cout << "Welcome to my vending machine!" << endl;
	cout << "Please input how much money you have on you " << char(156);
	cin >> cash;
	cout << "--------------" << endl;
	

	
	while (true) {
		display();
	}

	return 0;
}

void display() {
	system("cls");
	string choice;
	cout << "What catagory of items do you want to see?" << endl;
	cout << "OPTIONS: 'All', 'Snacks', 'Cold Drink', 'Hot Drink': " << endl;
	getline(cin, choice);

	cout << "=================================================================" << endl;
	if (choice == "Snacks" || choice == "Cold Drink" || choice == "Hot Drink") {
		for (int i = 0; i < items.size(); i++) {
			if (choice == items[i]->type) {
				cout << items[i]->position << ": " << items[i]->itemName << " | Price: " << char(156) << items[i]->price << " | Stock: " << items[i]->stock << endl;
			}
		}
	}
	else if (choice == "All") {
		for (int i = 0; i < items.size(); i++) {
			cout << items[i]->position << ": " << items[i]->itemName << " | Price: " << char(156) << items[i]->price << " | Stock: " << items[i]->stock << endl;
		}
	}
	else {
		if (choice != "") {
			cout << "Invalid Catagory!" << endl;
		}
		return;
	}

	cout << "=================================================================" << endl;

	cout << "Your cash balance: " << char(156) << cash << endl;

	buy();
	
}

void buy() {
	string buyItem;
	cout << "What would you like to buy?: " << endl;
	cout << "Type 'exit' if you wish to exit the program." << endl;
	cin >> buyItem;

	// Checks to see if the user wants to exits the program
	if (buyItem == "exit") {
		cout << "Exiting program!";
		exit(1);
	}

	// Loops through all class pointers in the 'items' vector 
	for (int i = 0; i < items.size(); i++) {
		if (buyItem == items[i]->position) {
			if (items[i]->stock >= 1) {
				if (cash >= items[i]->price) {
					// Outputs what user has purchased
					cout << "You have purchased: " << items[i]->itemName << endl;
					// Removes 1 from the items stock
					items[i]->stock--;
					// What the user had in cash
					cout << "You had " << char(156) << cash << ", ";
					// Removes cost amount from users cash 
					cash -= items[i]->price;
					// What the user has after in cash
					cout << "you now have " << char(156) << cash << endl;
					// Recommends a relevant item to the user
					recommend(items[i]->type);
					// Allows a delay for the user to read the text
					Sleep(3500);
				}
				else {
					cout << "You do not have enough cash to purchase this item!" << endl;
				}
			}
			else {
				cout << "This item is not in stock!" << endl;
			}
			break;
		}
	}
}

void recommend(string prevItem) {
	string target;

	// Used to recommend food or drink to the user after they have brought an item
	if (prevItem == "Cold Drink" || prevItem == "Hot Drink") {
		target = "Food";
	}
	else if (prevItem == "Snacks" || prevItem == "Hot Food") {
		target = "Drink";
	}
	else {
		cout << "Error: No recommendation has been given to you!" << endl;
		return;
	}

	vector<Item*> validRecommends;
	for (int i = 0; i < items.size(); i++) {
		if (target == "Food") {
			if (items[i]->type == "Snacks" || items[i]->type == "Hot Food") {
				validRecommends.push_back(items[i]);
			}
		}
		else if (target == "Drink") {
			if (items[i]->type == "Cold Drink" || items[i]->type == "Hot Drink") {
				validRecommends.push_back(items[i]);
			}
		} 
	}
	cout << "Our automated recommendation system recommends you also purchase: " << validRecommends[rand() % validRecommends.size()]->itemName << endl;
}
