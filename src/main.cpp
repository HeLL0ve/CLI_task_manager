#include <iostream>
#include <sstream>
#include <cstdlib>
#include "TaskManager.h"

int main() {
    std::string path = "tasks.txt";
    TaskManager taskManager;
    std::cout << "Welcome to CLI Task Manager" << std::endl;

    while (true) {
        std::string command;
        std::getline(std::cin, command);
        std::stringstream ss(command);
        ss>>command;
        std::string rest;
        std::getline(ss, rest);
        if (!rest.empty() && rest[0] == ' ') {
            rest.erase(0, 1);
        }
        try {
            if (command == "add") {
                if (rest.empty()) {
                    std::cout << "Task cannot be empty\n";
                    continue;
                }
                taskManager.addTask(rest);
            }else if (command == "delete") {
                int index = std::stoi(rest);
                taskManager.deleteTask(index);
            }else if (command == "list") {
                taskManager.listTasks();
            }else if (command == "complete") {
                int index = std::stoi(rest);
                taskManager.completeTask(index);
            }else if (command == "save") {
                taskManager.saveToFile(path);
            }else if (command == "load") {
                taskManager.loadFromFile(path);
            }else if (command == "help") {
                std::cout<<"Commands:\n";
                std::cout<<"\tadd\tadd task\n";
                std::cout<<"\tdelete\tdelete task\n";
                std::cout<<"\tlist\tlist tasks\n";
                std::cout<<"\tcomplete\tcomplete task\n";
                std::cout<<"\tfind\tfind task\n";
                std::cout<<"\tsave\tsave task to file\n";
                std::cout<<"\tload\tload task from file\n";
                std::cout<<"\texit\texit programm\n"<<std::endl;

            }else if (command == "exit") {
                break;
            }else if (command == "find") {
                if (rest.empty()) {
                    std::cout << "Task cannot be empty\n";
                    continue;
                }
                taskManager.findTask(rest);
            }
            else {
                std::cout << "Unknown command" << std::endl;
            }
        }catch (std::exception& e) {
            std::cout<<"Uncorrect command: "<<e.what()<<std::endl;
        }



    }



    return 0;
}
