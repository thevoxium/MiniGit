#include "FileOps.h"
#include <fstream>
#include <filesystem>
#include <stdexcept> 

namespace fs = std::filesystem;

namespace fileOps {
  bool writeFile(const std::string &path, const std::string &content){
    std::ofstream file(path, std::ios::binary);
    if (!file){
      return false;
    }else{
      file.write(content.c_str(), content.size());
      return file.good();
    }
  }

  std::string readFile(const std::string &path){
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file){
      throw std::runtime_error("Unable to open file: " + path);
    }else{
      std::streamsize size = file.tellg();
      file.seekg(0, std::ios::beg);

      std::string content(size, '\0');
      if (!file.read(content.data(), size)){
        throw std::runtime_error("Failed to read file: " + path);
      }
      return content;
    }
  }

  bool createDirectory(const std::string &path){
    return fs::create_directories(path);
  }

  bool removeDirectory(const std:: string &path){
    return fs::remove_all(path) > 0;
  }

  std::vector<std::string> listDirectory(const std::string &path){
    std::vector<std::string> files;
    for(const auto &entry : fs::directory_iterator(path)){
      files.push_back(entry.path().string());
    }
    return files;
  }
}
