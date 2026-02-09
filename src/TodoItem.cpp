#include "include/TodoItem.hpp"

TodoItem::TodoItem(const std::string& desc)
    : description(desc), completed(false)
{
}

void TodoItem::markComplete()
{
    completed = true;
}

std::string TodoItem::getDescription() const
{
    return description;
}

bool TodoItem::isCompleted() const
{
    return completed;
}
