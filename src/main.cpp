#include "include/includes.hpp"
#include <iostream>
#include <limits>

int main()
{
    TodoList list;
    std::string filename = "todos.json";
    list.loadFromFile(filename);

    std::cout << "Welcome to Todo App!" << std::endl;

    while (true)
    {
        std::cout << "\nCommands: list, add <desc>, complete <index>, save, quit" << std::endl;
        std::cout << "Enter command: ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "list")
        {
            const auto& items = list.getItems();
            if (items.empty())
            {
                std::cout << "No todos." << std::endl;
            }
            else
            {
                for (size_t i = 0; i < items.size(); ++i)
                {
                    std::cout << i << ": " << items[i].getDescription()
                              << (items[i].isCompleted() ? " [DONE]" : "") << std::endl;
                }
            }
        }
        else if (command.substr(0, 4) == "add ")
        {
            std::string desc = command.substr(4);
            if (!desc.empty())
            {
                list.addItem(desc);
                std::cout << "Added: " << desc << std::endl;
            }
            else
            {
                std::cout << "Description cannot be empty." << std::endl;
            }
        }
        else if (command.substr(0, 9) == "complete ")
        {
            try
            {
                size_t index = std::stoul(command.substr(9));
                list.markItemComplete(index);
                std::cout << "Marked as complete." << std::endl;
            }
            catch (...)
            {
                std::cout << "Invalid index." << std::endl;
            }
        }
        else if (command == "save")
        {
            list.saveToFile(filename);
            std::cout << "Saved to " << filename << std::endl;
        }
        else if (command == "quit")
        {
            list.saveToFile(filename);
            std::cout << "How dare you leave me gabe you stupid silly stupid bum" << std::endl;
            break;
        }
        else
        {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}
