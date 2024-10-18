I am deprecating this project for now, will try to continue this in future

# MiniGit

## Overview

The **MiniGit** project is a simplified implementation of a version control system inspired by Git. It allows users to initialize a Git-like repository at a specified path. The project creates the necessary directories and files for a basic repository structure, and is implemented in C++ using standard libraries and filesystem features.

## Directory Structure

The project contains the following files:

```
.
├── CMakeLists.txt
├── FileOps.cpp
├── FileOps.h
├── Git.cpp
├── Git.h
└── main.cpp
```

## File Descriptions

### `main.cpp`
- **Purpose**: Entry point of the application.
- **Functionality**: Processes command line arguments to handle commands (currently only supports repository initialization). It calls the MiniGit class to create a new repository at the specified path.

### `Git.h`
- **Purpose**: Header file for the MiniGit class.
- **Functionality**: Declares methods for repository initialization and manages member variables.

### `Git.cpp`
- **Purpose**: Implements the MiniGit class methods.
- **Functionality**: Handles repository initialization by creating necessary directories and configuration files. It manages the `.git` directory structure and ensures proper setup of basic repository components.

### `FileOps.h`
- **Purpose**: Header file for file operations utilities.
- **Functionality**: Declares functions for creating directories, writing to files, and other file manipulations.

### `FileOps.cpp`
- **Purpose**: Implements file operations utility functions.
- **Functionality**: Provides functionality for creating directories, writing files, and listing directory contents, using C++'s filesystem and I/O libraries.

### `CMakeLists.txt`
- **Purpose**: CMake build configuration file.
- **Functionality**: Specifies the project name, required C++ version, and build instructions. It conditionally links against the filesystem library if necessary, based on the compiler version.

## Usage

### Building the Project

1. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```

2. Configure and build the project using CMake:
   ```bash
   cmake ..
   make
   ```

### Running the Application

To initialize a new MiniGit repository, run the following command:
```bash
./mini_git init <path>
```
Replace `<path>` with the directory path where the repository should be created.

## Future Work

- Expand functionality to include commands for staging, committing, and branching.
- Improve error handling and user feedback.
- Implement unit tests for better reliability and maintainability.

## Conclusion

The **MiniGit** project serves as a basic implementation of core Git-like functionality, laying the foundation for a version control system. Future improvements can evolve this into a more complete and robust version control tool.
