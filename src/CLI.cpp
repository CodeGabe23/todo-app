#include "include/CLI.hpp"
#include <iostream>
#include <limits>

void runCLI(TodoApp& app)
{
    std::cout << "Welcome to Todo App!" << std::endl;

    while (true)
    {
        std::cout << "\nCommands: list, add <desc>, complete <index>, save, quit" << std::endl;
        std::cout << "Enter command: ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "list")
        {
            const auto& items = app.getItems();
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
                app.addItem(desc);
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
                app.completeItem(index);
                std::cout << "Marked as complete." << std::endl;
            }
            catch (...)
            {
                std::cout << "Invalid index." << std::endl;
            }
        }
        else if (command == "save")
        {
            app.save();
            std::cout << "Saved." << std::endl;
        }
        else if (command == "quit")
        {
            app.save();
            std::cout << "How dare you leave me gabe you stupid silly stupid bum" << std::endl;
            break;
        }
        else
        {
            std::cout << "Unknown command." << std::endl;
        }
    }
}
