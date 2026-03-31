//
// Created by hell0ve on 25.03.2026.
//

#ifndef CLI_TASK_MANAGER_TASK_H
#define CLI_TASK_MANAGER_TASK_H
#include <string>

class Task {
private:
    std::string title;
    bool completed;
public:
    Task(const std::string& title);
    Task(const std::string& title, bool completed);


    std::string toString() const;
    void setComplete();
    bool getComplete() const;
    std::string getTitle() const;
};
#endif //CLI_TASK_MANAGER_TASK_H
