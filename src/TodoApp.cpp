#include "include/TodoApp.hpp"

TodoApp::TodoApp(const std::string& fname)
    : filename(fname)
{
}

void TodoApp::load()
{
    list.loadFromFile(filename);
}

void TodoApp::save()
{
    list.saveToFile(filename);
}

void TodoApp::addItem(const std::string& desc)
{
    list.addItem(desc);
}

void TodoApp::completeItem(size_t index)
{
    list.markItemComplete(index);
}

const std::vector<TodoItem>& TodoApp::getItems() const
{
    return list.getItems();
}

size_t TodoApp::getItemCount() const
{
    return list.getItemCount();
}
