//
// Created by fyz on 2024/1/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Adventurer {
    int id;
    std::string name;
    int strength;

    Adventurer(int i, const std::string& n, int s) : id(i), name(n), strength(s) {}
};

class AdventurerManager {
private:
    std::vector<Adventurer> adventurers;
    std::map<int, int> idToIndex; // 用于快速查找特定ID的冒险家在vector中的位置

public:
    void insert(int id, const std::string& name, int strength) {
        adventurers.emplace_back(id, name, strength);
        idToIndex[id] = adventurers.size() - 1;
    }

    void remove(int id) {
        if (idToIndex.find(id) != idToIndex.end()) {
            int index = idToIndex[id];
            adventurers.erase(adventurers.begin() + index);
            idToIndex.erase(id);
            // 更新索引映射（如果需要的话）
            for (auto& pair : idToIndex) {
                if (pair.second > index) {
                    pair.second--;
                }
            }
        }
    }

    void removeRange(int id1, int id2) {
        for (int id = id2; id >= id1; --id) {
            remove(id);
        }
    }

    std::vector<Adventurer> queryById(int id) {
        std::vector<Adventurer> result;
        if (idToIndex.find(id) != idToIndex.end()) {
            int index = idToIndex[id];
            result.push_back(adventurers[index]);
        }
        return result;
    }

    std::vector<Adventurer> queryByName(const std::string& name) {
        std::vector<Adventurer> result;
        for (const auto& adventurer : adventurers) {
            if (adventurer.name == name) {
                result.push_back(adventurer);
            }
        }
        return result;
    }

    std::vector<Adventurer> queryByStrength(char op[], int value) {
        std::vector<Adventurer> result;
        for (const auto& adventurer : adventurers) {
            switch (op[0]) {
                case '>':
                    if(op[1]=='='){
                        if (adventurer.strength >= value) result.push_back(adventurer);
                        break;
                    }
                    else{
                        if (adventurer.strength > value) result.push_back(adventurer);
                        break;
                    }

                case '<':
                    if(op[1]=='='){
                        if (adventurer.strength <= value) result.push_back(adventurer);
                        break;
                    }
                    else {
                        if (adventurer.strength < value) result.push_back(adventurer);
                        break;
                    }
                case '=':
                    if (adventurer.strength == value) result.push_back(adventurer);
                    break;
                case '!':
                    if (adventurer.strength != value) result.push_back(adventurer);
                    break;
            }
        }
        return result;
    }

    std::vector<Adventurer> queryRangeByStrength(int id1, int id2, char op[], int value) {
        std::vector<Adventurer> result;
        for (int id = id1; id <= id2; ++id) {
            if (idToIndex.find(id) != idToIndex.end()) {
                int index = idToIndex[id];
                const auto& adventurer = adventurers[index];
                switch (op[0]) {
                    case '>':
                        if(op[1]=='='){
                            if (adventurer.strength >= value) result.push_back(adventurer);
                            break;
                        }
                        else{
                            if (adventurer.strength > value) result.push_back(adventurer);
                            break;
                        }

                    case '<':
                        if(op[1]=='='){
                            if (adventurer.strength <= value) result.push_back(adventurer);
                            break;
                        }
                        else {
                            if (adventurer.strength < value) result.push_back(adventurer);
                            break;
                        }
                    case '=':
                        if (adventurer.strength == value) result.push_back(adventurer);
                        break;
                    case '!':
                        if (adventurer.strength != value) result.push_back(adventurer);
                        break;
                }
            }
        }
        return result;
    }

    void printAdventurers(const std::vector<Adventurer>& adventurers) {
        for (const auto& adventurer : adventurers) {
            std::cout << adventurer.id << " " << adventurer.name << " " << adventurer.strength << std::endl;
        }
    }
};

int main() {
    int m, n;
    std::cin >> m >> n;

    AdventurerManager manager;

    // 读入并插入冒险家信息
    for (int i = 0; i < m; ++i) {
        int id, strength;
        std::string name;
        std::cin >> id >> name >> strength;
        manager.insert(id, name, strength);
    }

    // 处理指令
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "INSERT") {
            int id, strength;
            std::string name;
            std::cin >> id >> name >> strength;
            manager.insert(id, name, strength);
        } else if (command == "DELETE") {
            int id1, id2;
            std::cin >> id1;
            if (std::cin.peek() == ' ') {
                std::cin >> id2;
                manager.removeRange(id1, id2);
            } else {
                manager.remove(id1);
            }
        } else if (command == "QUERY") {
            std::string param;
            std::cin >> param;
            if (param == "name") {
                std::string name;
                char op;
                std::cin >>op>> name;
                auto adventurers = manager.queryByName(name);
                manager.printAdventurers(adventurers);
            }
            else if (param == "strength") {
                char op[2];
                int value;
                std::cin >> op >> value;
                auto adventurers = manager.queryByStrength(op, value);
                manager.printAdventurers(adventurers);
            }
            else if (std::cin.peek()!=' ') {
                int id = std::stoi(param);
                auto adventurers = manager.queryById(id);
                manager.printAdventurers(adventurers);
            }
            else {
                int id1=std::stoi(param), id2, value;
                char op[2];
                std::string s;
                std::cin >> id2 >> s >> op >> value;
                auto adventurers = manager.queryRangeByStrength(id1, id2, op, value);
                manager.printAdventurers(adventurers);
            }
        }
    }

    return 0;
}