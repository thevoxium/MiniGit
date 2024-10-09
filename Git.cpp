#include "Git.h"
#include "FileOps.h"
#include <iostream>
#include <filesystem>
#include<string> 
#include <vector> 

namespace fs = std::filesystem;

Git::Git(){}

Git::~Git(){}


bool Git::init(const std::string &path){
  repoPath = path;
  std::string gitDir = fs::path(repoPath) / ".git";

  if(!fileOps::createDirectory(gitDir)){
    std::cerr << "Failed to create .git directory"<<std::endl;
    return false;
  }

  std::vector<std::string> subdirs = {"objects", "refs", "refs/heads"};

  for (const auto& subdir: subdirs){
    if(!fileOps::createDirectory(fs::path(gitDir) / subdir)){
      std::cerr<<"Failed to create subdir : " <<subdir <<std::endl;
      return false;
    }
  }

  std::string headContent = "ref: refs/heads/master\n";
  if(!fileOps::writeFile(fs::path(gitDir) / "HEAD", headContent)){
    std::cerr<<"Failed to create head file." <<std::endl;
    return false;
  }

  std::string configContent = 
        "[core]\n"
        "\trepositoryformatversion = 0\n"
        "\tfilemode = false\n"
        "\tbare = false\n";
  if (!fileOps::writeFile(fs::path(gitDir) / "config", configContent)) {
      std::cerr << "Failed to create config file" << std::endl;
      return false;
  }

  std::cout << "Initialized empty Git repository in " << gitDir << std::endl;
  return true;
}
