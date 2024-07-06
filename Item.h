#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Item {
	public:
		string name;
		double price;
		vector<string> exclude_people;

		void createItem(string _name, double _price, vector<string> _exclude_people) {
			name = _name;
			price = _price;
			exclude_people = _exclude_people;
		}

};

