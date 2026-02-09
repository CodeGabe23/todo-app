#ifndef TODOITEM_HPP
#define TODOITEM_HPP

#include <string>

class TodoItem {
private:
    std::string description;
    bool completed;

public:
    TodoItem(const std::string& desc) : description(desc), completed(false) {}

    void markComplete() { completed = true; }

    std::string getDescription() const { return description; }

    bool isCompleted() const { return completed; }
};

#endif
