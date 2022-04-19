// Buffer.h

#ifndef _Buffer_h_
#define _Buffer_h_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct anchor {
  std::string name;
  std::string file;
};

class Buffer
{
public:
    void display() const;
    const std::string & file_name() const { return file_name_; }
    void move_to_next_page();
    void move_to_previous_page();
    bool go(const int & link_number);
    bool open_go(const std::string file_name);
    bool open(const std::string & file_name);
    bool back();
    void set_window_height(int h) { window_height_ = h; }
    void set_window_length(int l) { window_length_ = l; }

private:
    std::vector<std::string> v_lines_;
    int ix_top_line_ = 0;
    std::string file_name_;
    int window_height_;
    int window_length_;
    std::vector<anchor> anchors;
    std::vector<std::string> file_history_;
};

inline void Buffer::move_to_next_page()
{
    ix_top_line_ += window_height_;
    if (ix_top_line_ >= v_lines_.size())
        ix_top_line_ -= window_height_;
}

inline void Buffer::move_to_previous_page()
{
    ix_top_line_ -= window_height_;
    if (ix_top_line_ < 0)
        ix_top_line_ = 0;
}

inline bool Buffer::back() {
  return open_go(file_history_.back());
}

inline bool Buffer::go(const int & link_number)
{
  if (link_number > 0 && link_number-1 <= anchors.size()) {
    return open_go(anchors[link_number-1].file);
  } else {
    return false;
  }
}

#endif
