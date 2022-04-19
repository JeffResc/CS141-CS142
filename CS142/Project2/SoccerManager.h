/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Project 2, SoccerManager.h
  https://people.clarkson.edu/~alexis/CS142/Assignments/project2.pdf
*/

#ifndef _SoccerManager_h_
#define _SoccerManager_h_

#include <cstdlib>
#include <iostream>
#include <string>

#include "Buffer.h"

const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's

class SoccerManager
{
public:
    void run();

private:
    void display();
    void execute_command(char command, bool & done);

    Buffer buffer_;
    std::string message_;
};

#endif
