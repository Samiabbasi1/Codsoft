#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
//structure for the specifications of the task
struct Task
{
    string description;
    bool completed;
    Task(string desc):description(desc),completed(0)
	{
		
	}
};
//class for making and managing a list
class TodoList
	{
		private:
    		vector<Task>tasks;
		public:
			//add a new task to the list
    		void addTask(string des)
			{
        		tasks.push_back(Task(des));
        		cout<<"Task added: "<<des<<endl;
    		}
    		//view all the tasks with their status
   			void viewTasks()
			{
        		if(tasks.empty())
				{
            		cout<<"No tasks in the list"<<endl;
            		return;
        		}
        		cout<<"Tasks:"<<endl;
        		for (int i=0;i<tasks.size();++i)
				{
            		cout<<"["<<i+1<<"] ";
            		if(tasks[i].completed)
					{
                		cout<<"[X] ";//represents that the task is completed
            		}
					else
					{
                		cout<<"[ ] ";//represents that task isn't completedd
            		}
            	cout<<tasks[i].description<<endl;
        		}
    		}
    		//mark a task as completed
    		void markCompleted(int index)
			{
        		if(index<1 || index>static_cast<int>(tasks.size()))//safing if user enters an invalid index
				{
            		cout<<"Invalid task index"<<endl;
            		return;
        		}
				tasks[index - 1].completed=1;
        		cout<<"Task marked as completed: "<<tasks[index - 1].description<<endl;
    		}
    		//remove a task from the list
    		void removeTask(int index)
			{
        		if(index<1 || index>static_cast<int>(tasks.size()))
				{
            		cout<<"Invalid task index"<<endl;
            		return;
        		}
        		cout<<"Task removed: "<<tasks[index-1].description<<endl;
        		tasks.erase(tasks.begin()+index-1);
    		}
};
int main()
{
    TodoList todoList;
    //looping until the iser wants to exit the program
    while(1)
	{
        cout<<"Menu:" <<endl;
        cout<<"1. Add Task" <<endl;
        cout<<"2. View Tasks" <<endl;
        cout<<"3. Mark Task as Completed" <<endl;
        cout<<"4. Remove Task" <<endl;
        cout<<"5. Exit" <<endl;
        int choice;
        cin>>choice;
        if(choice==1)
		{
            cout<<"Enter task description: ";
            string description;
            cin.ignore(); // Clear the newline left in the buffer
            getline(cin, description);
            todoList.addTask(description);
        }
		else if(choice==2)
		{
            todoList.viewTasks();
        } 
		else if(choice==3)
		{
            cout<<"Enter task index to mark as completed: ";
            int index;
            cin>>index;
            todoList.markCompleted(index);
        }
		else if(choice==4)
		{
            cout<<"Enter task index to remove: ";
            int index;
            cin>>index;
            todoList.removeTask(index);
        }
		else if(choice==5)
		{
            break;
        } 
		else
		{
			//incase user enters any invalid choice
            cout << "Enter a valid choice" << endl;
        }
    }
    return 0;
}

