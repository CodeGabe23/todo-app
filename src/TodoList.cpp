#include "include/TodoList.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

void TodoList::addItem(const std::string& desc) {
    items.emplace_back(desc);
}

void TodoList::markItemComplete(size_t index) {
    if (index < items.size()) {
        items[index].markComplete();
    }
}

const std::vector<TodoItem>& TodoList::getItems() const {
    return items;
}

size_t TodoList::getItemCount() const {
    return items.size();
}

void TodoList::saveToFile(const std::string& filename) {
    nlohmann::json j;
    for (const auto& item : items) {
        j.push_back({{"description", item.getDescription()}, {"completed", item.isCompleted()}});
    }
    std::ofstream file(filename);
    file << j.dump(4);
}

void TodoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    nlohmann::json j;
    file >> j;
    items.clear();
    for (const auto& obj : j) {
        std::string desc = obj["description"];
        bool comp = obj["completed"];
        TodoItem item(desc);
        if (comp) item.markComplete();
        items.push_back(item);
    }
}
