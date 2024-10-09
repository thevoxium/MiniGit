#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <string> 
#include <vector> 

using namespace std;

namespace fileOps {
  bool writeFile(const string &path, const string &content);
  string readFile(const string &path);
  bool createDirectory(const string &path);
  bool removeDirectory(const string &path);
  vector<string> listDirectory(const string &path);
}

#endif
