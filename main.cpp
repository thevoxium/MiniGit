#include <iostream>
#include "Git.h"

using namespace std;

int main(int argc, char* argv[]){
  if (argc < 3){
    cerr << "Usage: " << argv[0] << " <command> <path>" << endl;
  }

  string command = argv[1];
  string path = argv[2];

  Git git;

  if (command == "init"){
    if(!git.init(path)){
      cerr <<"Failed to initialize the repository" << endl;
      return 1;
    }
  }else{
    cerr << "Unknow Command: " << command << endl;
    return 1;
  }

  return 0;
}
