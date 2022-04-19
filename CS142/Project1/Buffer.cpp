// Buffer.cpp

#include <sstream>
#include "Buffer.h"

using namespace std;

void Buffer::display() const
{
    int ix_stop_line_ = ix_top_line_ + window_height_;
    for (int i = ix_top_line_; i < ix_stop_line_; ++i) {
        if (i < v_lines_.size())
            cout << std::setw(6) << i+1 << "  " << v_lines_[i];
        cout << '\n';
    }
}

// Only make a copy of new_file_name if we are opening
// via the go method, which forwards to the regular
// method.
bool Buffer::open_go(const string new_file_name) {
  return Buffer::open(new_file_name);
}

bool Buffer::open(const string & new_file_name)
{
    std::ifstream file(new_file_name);
    if (!file)
        return false;

    // Note: the vector is cleared only after we know the file
    // opened successfully.
    v_lines_.clear();
    anchors.clear();

    string line;
    while (getline(file, line)) {
      std::string word;
      std::string newLine;
      std::stringstream ss;
      // Read each line of the file into a string stream
      ss.str (line);
      // While a word still exists in the string steam
      while (ss >> word) {
        if (word == "<a") {
          // An anchor is beginning, capture the values as store them in our anchors vecor
          anchor a;
          std::string name;
          // Set values in our anchor variable
          ss >> a.file;
          ss >> a.name;
          anchors.push_back(a);
          // Override how the anchor will be displayed to the user
          newLine += '<'+a.name+'['+to_string(anchors.size())+']';
        } else if (word == "<br>" || word == "<p>") {
          v_lines_.push_back(newLine);
          newLine = "";
        } else {
          // No anchor, continue as usual
          newLine += word;
        }
        // Add spaces after each word
        newLine += ' ';
      }
      // Make sure the line isn't longer than the window length and if it is, add it to it's own line
      if (newLine.length() > window_length_) {
        // Find the space to split the line at
        int lastSpaceLocation = 0;
        for (int i = 0; i < newLine.length(); i++) {
          if (newLine[i] == ' ') {
            lastSpaceLocation = i;
          }
          if (i > window_length_) {
            break;
          }
        }
        std::string lineOne = newLine.substr(0, lastSpaceLocation);
        std::string lineTwo = newLine.substr(lastSpaceLocation+1, newLine.length());
        v_lines_.push_back(lineOne);
        v_lines_.push_back(lineTwo);
      } else {
        v_lines_.push_back(newLine);
      }
    }

    // Set new filename
    file_history_.push_back(file_name_);
    file_name_ = new_file_name;
    ix_top_line_ = 0;

    return true;
}
