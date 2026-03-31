//
// Created by hell0ve on 25.03.2026.
//
#include "TaskManager.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Task.h"

void TaskManager::addTask(const std::string& title) {
    tasks.push_back(Task(title));
    std::cout << "Task added." << std::endl;
}

void TaskManager::deleteTask(int index) {
    if (index < 1 || index > static_cast<int>(tasks.size())) {
        throw std::out_of_range("Invalid task index");
    }
    tasks.erase(tasks.begin() + (index - 1));
    std::cout << "Task deleted." << std::endl;
}

void TaskManager::completeTask(int index) {
    if (index < 1 || index > static_cast<int>(tasks.size())) {
        throw std::out_of_range("Invalid task index");
    }
    tasks[index - 1].setComplete();
    std::cout << "Task completed." << std::endl;
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
        return;
    }
    int counter = 1;
    for (const Task& task : tasks) {
        std::cout << counter << "." << task.toString() << std::endl;
        counter++;
    }
}

void TaskManager::loadFromFile(const std::string& filename) {
    tasks.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "No saved tasks found.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string completedStr;
        if (!std::getline(ss, completedStr, '|')) {
            continue;
        }

        bool completed = std::stoi(completedStr) != 0;
        std::string title;
        std::getline(ss, title);
        tasks.push_back(Task(title, completed));
    }

    file.close();
    std::cout << "Tasks loaded." << std::endl;
}

void TaskManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ofstream::out | std::ofstream::trunc);
    std::string line;
    for (const Task& task : tasks) {
        line = std::to_string(task.getComplete()) + "|" + task.getTitle();
        file << line << std::endl;
    }
    file.close();
    std::cout << "Tasks saved." << std::endl;
}
void TaskManager::findTask(const std::string& title) {
    int counter = 1;
    for (const Task& task : tasks) {
        if (task.getTitle().find(title) != std::string::npos) {
            std::cout << counter << "." << task.toString() << std::endl;
        }
        counter++;
    }
}