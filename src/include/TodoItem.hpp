#ifndef TODOITEM_HPP
#define TODOITEM_HPP

#include <string>

class TodoItem {
private:
    std::string description;
    bool completed;

public:
    TodoItem(const std::string& desc);
    void markComplete();
    std::string getDescription() const;
    bool isCompleted() const;
};

#endif
