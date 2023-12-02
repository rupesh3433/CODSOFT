/*
TASK - 4
----------------------- TO-DO LIST------------------
Build a simple console-based to-do list manager that
allows users to add, view, and delete tasks.
----------------------------------------------------
1.) Task Input: Allow users to input tasks they want to add to the list.
2.) Add Task: Implement a function to add tasks to the list.
3.) View Tasks: Display the list of tasks with their status (completed or pending).
4.) Mark Task as Completed: Allow users to mark tasks as completed.
5.) Remove Task: Provide an option to remove tasks from the list.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Task
{
public:
    string description;
    bool completed;

    Task() : description(""), completed(false) {}
    Task(const string &desc, bool isCompleted = false) : description(desc), completed(isCompleted) {}
};

class ToDoListManager
{
private:
    vector<Task> tasks;
    const string filename = "tasks.txt";

public:
    ToDoListManager()
    {
        loadTasksFromFile();
    }

    ~ToDoListManager()
    {
        saveTasksToFile();
    }

    void loadTasksFromFile()
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "File '" << filename << "' not found. Creating a new file.\n";
            ofstream file(filename);
            file.close();
            return;
        }
        if (file.is_open())
        {
            Task task;
            while (getline(file, task.description))
            {
                file >> task.completed;
                file.ignore();
                tasks.push_back(task);
            }
            file.close();
        }
    }

    void
    saveTasksToFile() const
    {
        ofstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open file '" << filename << "' for writing.\n";
            return;
        }
        if (file.is_open())
        {
            for (const Task &task : tasks)
            {
                file << task.description << "\n"
                     << task.completed << "\n";
            }
            file.close();
        }
    }

    void displayTasks() const
    {
        cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].description << endl;
        }
        cout << endl;
    }

    void addTask(const string &description)
    {
        Task newTask(description);
        tasks.push_back(newTask);
        cout << "Task added successfully.\n\n";
    }

    void markTaskAsCompleted(size_t index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].completed = true;
            cout << "Task marked as completed.\n\n";
        }
        else
        {
            cout << "Invalid task index.\n\n";
        }
    }

    void removeTask(size_t index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed successfully.\n\n";
        }
        else
        {
            cout << "Invalid task index.\n\n";
        }
    }

    void eraseAllTasks()
    {
        tasks.clear();
        ofstream file(filename, ofstream::trunc);
        file.close();
        cout << "All tasks erased successfully.\n\n";
    }
};

int main()
{
    ToDoListManager toDoList;

    while (true)
    {
        cout << "To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Erase All Tasks\n";
        cout << "6. Quit\n";

        int choice;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            toDoList.addTask(description);
            break;
        }
        case 2:
            toDoList.displayTasks();
            break;
        case 3:
        {
            size_t index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            toDoList.markTaskAsCompleted(index - 1);
            break;
        }
        case 4:
        {
            size_t index;
            cout << "Enter the index of the task to remove: ";
            cin >> index;
            toDoList.removeTask(index - 1);
            break;
        }
        case 5:
            toDoList.eraseAllTasks();
            break;
        case 6:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n\n";
        }
    }

    return 0;
}
