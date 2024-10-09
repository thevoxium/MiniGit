#ifndef GIT_H
#define GIT_H

#include <string> 

class Git{
  public:
    Git();
    ~Git();

    bool init(const std::string &path);

  private:
    std::string repoPath;
};


#endif // !GIT_H
