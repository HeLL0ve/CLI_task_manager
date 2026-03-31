//
// Created by hell0ve on 25.03.2026.
//
#include "Task.h"

#include <iostream>
#include <ostream>

Task::Task(const std::string& title) {
    this->title = title;
    this->completed = false;
}
Task::Task(const std::string& title, bool completed) {
    this->title = title;
    this->completed = completed;
}

std::string Task::toString() const {
    std::string result;
    if (completed == true) {
        result = " [x] " + title;
    }
    else {
        result = " [ ] " + title;
    }
    return result;
}

void Task::setComplete() {
    this->completed = true;
}

bool Task::getComplete() const{
    return this->completed;
}
std::string Task::getTitle() const {
    return this->title;
}

