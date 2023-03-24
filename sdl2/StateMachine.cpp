// StateMachine.cpp
#include "StateMachine.h"

//init objects
State * State:: mainMenu = new MainMenu;
State * State:: manageAccount = new ManageAccount;
State * State:: viewMyCourses = new ViewMyCourses;
State * State:: viewTask = new ViewTask;
State * State:: sortTask = new SortTask;
State * State:: viewAllAvailableCourses = new ViewAllAvailableCourses;
State * State:: manageCourseSubscription = new ManageCourseSubscription;
State * State:: manageTask = new ManageTask;
State * State:: instructorMainMenu = new InstructorMainMenu;
State * State:: viewConsolidatedDeadlines = new ViewConsolidatedDeadlines;
State * State:: manageCourse = new ManageCourse;

//start in the respective menu
State * State:: currStateStu = mainMenu;
State * State:: currStateIns = instructorMainMenu;

//////////Main Menu//////////////

void MainMenu::Enter(){

    cout << "===== MENU =====" << std::endl;
    cout << "1. Manage Account" << std::endl;
    cout << "2. Manage Tasks" << std::endl;
    cout << "3. View My Courses" << std::endl;
    cout << "4. View Tasks" << std::endl;
    cout << "5. Sort Tasks" << std::endl;
    cout << "6. View All Courses" << std::endl;
    cout << "7. Manage Course Subscriptions" << std::endl;
    cout << "8. Quit" << std::endl;

}
void MainMenu::Update(){

    int choice;
    cout << "Enter a number to select an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            currStateStu = manageAccount;
            break;
        case 2:
            currStateStu = manageTask;
            break;
        case 3:
            currStateStu = viewMyCourses;
            break;
        case 4:
            currStateStu = viewTask;
            break;
        case 5:
            currStateStu = sortTask;
            break;
        case 6:
            currStateStu = viewAllAvailableCourses;
            break;
        case 7:
            currStateStu = manageCourseSubscription;
            break;
        case 8:
            exit(0);
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }

}
void MainMenu::Exit(){}

//////////Instructor Main Menu//////////////

void InstructorMainMenu::Enter(){

    cout << "===== MENU =====" << std::endl;
    cout << "1. Manage Account" << std::endl;
    cout << "2. Manage Tasks" << std::endl;
    cout << "3. View My Courses" << std::endl;
    cout << "4. View Tasks" << std::endl;
    cout << "5. Sort Tasks" << std::endl;
    cout << "6. View Consolidated Deadlines" << std::endl;
    cout << "7. Manage Course" << std::endl;
    cout << "8. Quit" << std::endl;

}
void InstructorMainMenu::Update(){

    int choice;
    cout << "Enter a number to select an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            currStateIns = manageAccount;
            break;
        case 2:
            currStateIns = manageTask;
            break;
        case 3:
            currStateIns = viewMyCourses;
            break;
        case 4:
            currStateIns = viewTask;
            break;
        case 5:
            currStateIns = sortTask;
            break;
        case 6:
            currStateIns = viewConsolidatedDeadlines;
            break;
        case 7:
            currStateIns = manageCourse;
            break;
        case 8:
            exit(0);
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }    

}
void InstructorMainMenu::Exit(){}

//////////View Task//////////////

void ViewTask::Enter() {
    std::cout << "Entering View Tasks state" << std::endl;
}

void ViewTask::Update() {

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }

}

void ViewTask::Exit() {
    std::cout << "Exiting View Tasks state" << std::endl;
}
///////////View My Course////////////

void ViewMyCourses::Enter(){
    std::cout << "Entering View My Course state" << std::endl;
}
void ViewMyCourses::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }

}
void ViewMyCourses::Exit(){
    std::cout << "Exiting View My Course state" << std::endl;
}

///////////Manage Account////////////

void ManageAccount::Enter(){
    std::cout << "Entering Manage Account state" << std::endl;
}
void ManageAccount::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }

}
void ManageAccount::Exit(){
    std::cout << "Entering Manage Account state" << std::endl;
}

///////////Sort Task////////////

void SortTask::Enter(){
    std::cout << "Entering Sort Task state" << std::endl;
}
void SortTask::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }

}
void SortTask::Exit(){
    std::cout << "Exiting Sort Task state" << std::endl;
}

///////////View All Available Courses////////////

void ViewAllAvailableCourses::Enter(){
    std::cout << "Entering View All Available Courses state" << std::endl;
}
void ViewAllAvailableCourses::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }
}
void ViewAllAvailableCourses::Exit(){
    std::cout << "Exiting View All Available Courses state" << std::endl;
}

///////////Manage Course Subscription////////////

void ManageCourseSubscription::Enter(){
    std::cout << "Entering Manage Course Subscription state" << std::endl;
}
void ManageCourseSubscription::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }
}
void ManageCourseSubscription::Exit(){
    std::cout << "Exiting Manage Course Subscription state" << std::endl;
}

///////////Manage Task////////////

void ManageTask::Enter(){
    std::cout << "Entering Manage Task state" << std::endl;
}
void ManageTask::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }
}
void ManageTask::Exit(){
    std::cout << "Exiting Manage Task state" << std::endl;
}

///////////View Consolidated Deadlines////////////

void ViewConsolidatedDeadlines::Enter(){
    std::cout << "Entering View Consolidated Deadlines state" << std::endl;
}
void ViewConsolidatedDeadlines::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }
}
void ViewConsolidatedDeadlines::Exit(){
    std::cout << "Exiting View Consolidated Deadlines state" << std::endl;
}

///////////Manage Course////////////

void ManageCourse::Enter(){
    std::cout << "Entering Manage Course state" << std::endl;
}
void ManageCourse::Update(){

    std::cout << "use case routine :" << std::endl;
    int choice;
    std::cout << "Press 1 to go back to the main menu: ";
    std::cin >> choice;

    if (choice == 1) {
        if (State::currStateStu == this) {
            State::currStateStu = State::mainMenu;
        } else if (State::currStateIns == this) {
            State::currStateIns = State::instructorMainMenu;
        }
    }
}
void ManageCourse::Exit(){
    std::cout << "Exiting Manage Course state" << std::endl;
}