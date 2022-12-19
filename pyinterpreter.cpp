#include <iostream>

#include <python3.10/Python.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <deque>

#include <termios.h> 
#include <unistd.h> 
#include <stdio.h> /* reads from keypress, doesn't echo */ 
int getch(void) 
{ 
    struct termios oldattr, newattr; 
    int ch; 
    tcgetattr(STDIN_FILENO, &oldattr); 
    newattr = oldattr; 
    newattr.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); 
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); 
    return ch; 
} /* reads from keypress, echoes */ 
int getche(void) 
{ 
    struct termios oldattr, newattr; 
    int ch; 
    tcgetattr(STDIN_FILENO, &oldattr); 
    newattr = oldattr; 
    newattr.c_lflag &= ~(ICANON); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); 
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); 
    return ch; 
}

int main()
{
    std::cout << "My Simple Python Interpreter in a cpp app.\n";

    Py_Initialize();

    bool done = false;
    std::deque<std::string> history;
    while(!done){

        int history_index = -1;

        std::cout << "[python] << ";

        std::string input;
        bool input_done = false;
        // while (!input_done) {
        //     int in = getche();

        //     if(input.size() >= 3){
        //         if(input[input.size()-1] == 65
        //         && input[input.size()-2] == 91
        //         && input[input.size()-3] == 27){
        //             std::cin.clear();
        //                 input.clear();
        //                 history_index++;
        //                 std::cout << std::flush;
        //                 std::cout << "[python] << ";
        //                 if(history_index < history.size()){
        //                     for(int i = history[history_index].size() - 1; i >= 0 ; --i){
        //                         std::cin.putback(history[history_index][i]);
        //                     }
        //                 }
        //                 continue;
        //         }
        //     }
        //     if(in == '\n'){
        //         input_done = true;
        //         continue;
        //     }

        //     input.push_back(in);
        // }

        
        while (!input_done) {
            int in = getchar();
            // std::cout << (char)in << " - " << (int)in << "\n";
            if(in == '\n'){
                input_done = true;
            } 
            // else if (in == 27 ){
            //     std::cin.ignore(1);
            //     std::cout << "1]]]" << std::cin.peek() << "\n";
            //     if(std::cin.peek() == 91){
            //         std::cin.ignore(1);
            //         std::cout << "2]]]" << std::cin.peek() << "\n";
            //         if(std::cin.peek() == 65){
            //             std::cin.ignore(1);
            //             std::cout << "3]]]" << in << "\n";
            //             std::cin.clear();
            //             input.clear();
            //             history_index++;
            //             std::cout << std::flush;
            //             std::cout << "[python] << ";
            //             if(history_index < history.size()){
            //                 for(int i = history[history_index].size() - 1; i >= 0 ; --i){
            //                     std::cin.putback(history[history_index][i]);
            //                 }
            //             }
            //         }
            //     } else{
            //         std::cin.putback(27);
            //     }
            // }
            else {
                input.push_back(in);
            }
        }
        // std::cout << "input: " << input << "\n"; 
        // for(auto character : input){
        //     std::cout << (int)character << "\n";
        // }

        // std::getline(std::cin, input);
        if(input == "exit" || input == "quit"){
            done = true;
        } else {
            history.push_front(input);
            PyRun_SimpleString(input.c_str());
        }
    }

    std::cout << "Goodbye!\n";

    Py_Finalize();

    return 0;
}