#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include "Item.h"
using namespace std;

class Receipt {
    public:
        string owner;
        vector<pair<string,double>> people;
        vector<Item> items;
        double discount;

        void createReceipt() {
            cout << "called";
        }

        void setOwner() {
            cout << "Who paid?: ";
            getline(cin, owner);
        }

        void setPayees() {
            string input;
            cout << "Enter names of people separated by commas: ";
            getline(cin, input);

            stringstream ss(input);

            string person;
            while (getline(ss, person, ',')) { // Tokenize by commas
                people.push_back(make_pair(person, 0));
            }

            // Print the list of names
            cout << "List of people:\n";
            for (const pair<string,double>& p : people) {
                cout << p.first << endl;
            }

        }

        int setItem() {
            cout << "Enter (item, price) or type 'x' to finish: ";

            string input;
            getline(cin, input);
            
            if (input == "x") {
                cout << "bye" << "\n";
                return 0;
            }

            stringstream ss(input);
            string token;
            vector<string> line;

            while (getline(ss, token, ',')) {
                line.push_back(token);
            }

            if (line.size() < 2) {
                cout << "Error: Insufficient input data.";
                return 1;
            }

            Item item;
            string item_name = line[0];
            double price = stod(line[1]);
            vector<string> exclude_people;

            for (size_t i = 2; i < line.size(); ++i) {
                exclude_people.push_back(line[i]);
            }

            item.createItem(item_name, price, exclude_people);
            items.push_back(item);

            // Printing item_name, price, and exclude_people
            read();
            return 1;
        }

        void read() {
            for (const auto& item : items) {
                cout << "Item: " << item.name << " ";
                cout << "$" << item.price << " ";
                cout << "Excluded People: ";
                for (const auto& person : item.exclude_people) {
                    cout << person << " ";
                }
                cout << "\n";
            }
        }

        double subtotal() {
            double _subtotal = 0;
            for (const auto& item : items) {
                _subtotal += item.price;
            }
            return _subtotal;
        }

        void calculate() {
            auto start = chrono::high_resolution_clock::now();

            int splitTo = people.size() + 1;
            cout << "people size " << splitTo << "\n";
            vector < pair < string, double >> debtors = people;

            for (const Item& item : items) {
                double split = item.price / splitTo;
                for (auto& person : debtors) {
                    person.second += split;
                }
            }

            people = debtors;

            auto end = chrono::high_resolution_clock::now();
            chrono::duration < double > duration = end - start;
            cout << "Calculated in: " << duration.count() << " seconds" << "\n";
        };

        void debtors() {
            for (const auto& person : people) {
                cout << person.first << " owes $" << person.second << " to " << owner << "\n";
            }
        }

        //void setDiscount(double ) {
        //    double discount
        //}

};