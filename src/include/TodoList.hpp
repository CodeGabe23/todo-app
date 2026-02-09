#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <vector>
#include "TodoItem.hpp"

class TodoList {
private:
    std::vector<TodoItem> items;

public:
    void addItem(const std::string& desc) {
        items.emplace_back(desc);
    }

    void markItemComplete(size_t index) {
        if (index < items.size()) {
            items[index].markComplete();
        }
    }

    const std::vector<TodoItem>& getItems() const {
        return items;
    }

    size_t getItemCount() const {
        return items.size();
    }

    void saveToFile(const std::string& filename) {
        nlohmann::json j;
        for (const auto& item : items) {
            j.push_back({{"description", item.getDescription()}, {"completed", item.isCompleted()}});
        }
        std::ofstream file(filename);
        file << j.dump(4); 
    }

    void loadFromFile(const std::string& filename) {
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
};

#endif
