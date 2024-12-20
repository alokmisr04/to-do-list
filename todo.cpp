#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool isCompleted;
};
void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, taskDescription);
    tasks.push_back({taskDescription, false});
    cout << "Task added successfully!" << endl;
}
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the to-do list." << endl;
    } else {
        cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " - " << (tasks[i].isCompleted ? "Completed" : "Pending") << endl;
        }
    }
}
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed." << endl;
    } else {
        viewTasks(tasks);
        int taskNumber;
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks[taskNumber - 1].isCompleted = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
    } else {
        viewTasks(tasks);
        int taskNumber;
        cout << "Enter the task number to remove: ";
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}
int main() {
    vector<Task> tasks;
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}