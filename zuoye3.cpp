//
// Created by fyz on 2024/1/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Adventurer {
    int id;
    string name;
    int strength;
};

vector<Adventurer> adventurers;

void insertAdventurer(int id, const string& name, int strength) {
    Adventurer adventurer = {id, name, strength};
    adventurers.push_back(adventurer);
    sort(adventurers.begin(), adventurers.end(), [](const Adventurer& a, const Adventurer& b) {
        return a.id < b.id;
    });
}

void deleteAdventurer(int id) {
    adventurers.erase(remove_if(adventurers.begin(), adventurers.end(), [id](const Adventurer& a) {
        return a.id == id;
    }), adventurers.end());
}

void deleteAdventurersInRange(int id1, int id2) {
    adventurers.erase(remove_if(adventurers.begin(), adventurers.end(), [id1, id2](const Adventurer& a) {
        return a.id >= id1 && a.id <= id2;
    }), adventurers.end());
}

void queryAdventurerById(int id) {
    auto it = find_if(adventurers.begin(), adventurers.end(), [id](const Adventurer& a) {
        return a.id == id;
    });
    if (it != adventurers.end()) {
        cout << it->id << " " << it->name << " " << it->strength << endl;
    }
}

void queryAdventurerByName(const string& name) {
    for (const Adventurer& adventurer : adventurers) {
        if (adventurer.name == name) {
            cout << adventurer.id << " " << adventurer.name << " " << adventurer.strength << endl;
        }
    }
}

void queryAdventurersByStrength(int id1, int id2, char comparison, int value) {
    for (const Adventurer& adventurer : adventurers) {
        if (adventurer.id >= id1 && adventurer.id <= id2) {
            bool conditionMet = false;
            switch (comparison) {
                case '>':
                    conditionMet = adventurer.strength > value;
                    break;
                case '>=':
                    conditionMet = adventurer.strength >= value;
                    break;
                case '<':
                    conditionMet = adventurer.strength < value;
                    break;
                case '<=':
                    conditionMet = adventurer.strength <= value;
                    break;
                case '!=':
                    conditionMet = adventurer.strength != value;
                    break;
                case '=':
                    conditionMet = adventurer.strength == value;
                    break;
            }
            if (conditionMet) {
                cout << adventurer.id << " " << adventurer.name << " " << adventurer.strength << endl;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        int id, strength;
        string name;
        cin >> id >> name >> strength;
        insertAdventurer(id, name, strength);
    }

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "INSERT") {
            int id, strength;
            string name;
            cin >> id >> name >> strength;
            insertAdventurer(id, name, strength);
        } else if (command == "DELETE") {
            int id1, id2;
            cin >> id1 >> id2;
            if (id2 == 0) {
                deleteAdventurer(id1);
            } else {
                deleteAdventurersInRange(id1, id2);
            }
        } else if (command == "QUERY") {
            char comparison;
            int id1, id2, value;
            string temp;
            cin >> id1 >> temp;
            if (temp == "=") {
                cin >> value;
                queryAdventurerById(id1);
            } else if (temp == "name") {
                string name;
                cin >> temp >> name;
                queryAdventurerByName(name);
            } else {
                cin >> id2 >> comparison >> temp >> value;
                queryAdventurersByStrength(id1, id2, comparison, value);
            }
        }
    }

    return 0;
}
