#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <vector>
#include <string>
#include "TodoItem.hpp"

class TodoList {
private:
    std::vector<TodoItem> items;

public:
    void addItem(const std::string& desc);
    void markItemComplete(size_t index);
    const std::vector<TodoItem>& getItems() const;
    size_t getItemCount() const;
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

#endif
