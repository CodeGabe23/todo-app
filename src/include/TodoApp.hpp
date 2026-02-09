#ifndef TODOAPP_HPP
#define TODOAPP_HPP

#include <string>
#include "TodoList.hpp"

class TodoApp
{
private:
    TodoList list;
    std::string filename;

public:
    TodoApp(const std::string& fname);
    void load();
    void save();
    void addItem(const std::string& desc);
    void completeItem(size_t index);
    const std::vector<TodoItem>& getItems() const;
    size_t getItemCount() const;
};

#endif
