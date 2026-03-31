//
// Created by hell0ve on 25.03.2026.
//

#ifndef CLI_TASK_MANAGER_TASKMANAGER_H
#define CLI_TASK_MANAGER_TASKMANAGER_H
#include <vector>

#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;
public:
    void addTask(const std::string& title);
    void deleteTask(int index);
    void completeTask(int index);
    void listTasks() const;
    void findTask(const std::string& title);

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};
#endif //CLI_TASK_MANAGER_TASKMANAGER_H
