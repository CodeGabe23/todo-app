#include "include/includes.hpp"

int main()
{
    TodoApp app("todos.json");
    app.load();
    runCLI(app);
    return 0;
}
