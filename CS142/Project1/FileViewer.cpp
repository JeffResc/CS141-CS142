// FileViewer.cpp

#include "FileViewer.h"

using namespace std;

void FileViewer::display()
{
    const string long_separator(50, '-');
    const string short_separator(8, '-');

    //system(clear_command);

    if (!error_message_.empty()) {
        cout << "ERROR: " + error_message_ << endl;
        error_message_.clear();
    }

    string file_name = buffer_.file_name();
    if (file_name.empty())
        cout << "<no file opened>\n";
    else
        cout << file_name << endl;

    cout << long_separator << endl;
    buffer_.display();
    cout << long_separator << endl;
    cout << "  back  go  next  previous  open  quit\n";
    cout << short_separator << endl;
}

void FileViewer::execute_command(char command, bool & done)
{
    switch (command) {
        case 'b': {
          if (!buffer_.back())
              error_message_ = "Unable to go back, was there a previously opened document?";
          break;
        }
        case 'g': {
          cout << "link number: ";
          // Converting link_number_str to link_number using stoi in order to throw an
          // error rather than continously looping through the program if a user inputs
          // a string rather than and int
          string link_number_str;
          getline(cin, link_number_str);
          int link_number = stoi(link_number_str);
          if (!buffer_.go(link_number))
              error_message_ = "Link number " + to_string(link_number) + " does not exist, or the file that it points to is invalid.";
          break;
        }
        case 'n': {
            buffer_.move_to_next_page();
            break;
        }

        case 'o': {
            cout << "file name: ";
            string file_name;
            getline(cin, file_name);
            if (!buffer_.open(file_name))
                error_message_ = "Could not open " + file_name;
            break;
        }

        case 'p': {
            buffer_.move_to_previous_page();
            break;
        }

        case 'q': {
            done = true;
            break;
        }
    }
}

void FileViewer::run()
{
    cout << "Window height? ";
    cin >> window_height_;
    cin.get();  // '\n'
    cout << '\n';
    buffer_.set_window_height(window_height_);

    cout << "Window length? ";
    cin >> window_length_;
    cin.get();  // '\n'
    cout << '\n';
    buffer_.set_window_length(window_length_);

    bool done = false;
    while (!done) {
        display();

        cout << "command: ";
        char command;
        cin >> command;
        cin.get(); // '\n'

        execute_command(command, done);

        cout << endl;
    }
}
