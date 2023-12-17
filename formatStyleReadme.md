# Brief how to setup. Additionally check A+ project guidelines.

# Find in VScode:
>Preferences: Open User Settings
C_Cpp: Clang_format_style
set it to ./.clang-format
which is in our git. We are using google standard recommended by A+.

# Set up the style warnings
install miniconda
create a new environment
conda install -c conda-forge cpplint
find where the executable cpplint is located (somewhere in envs of new env that you created)
install extension in vscode - cpplint
open settings and locate the executable.
check that it reads the correct style.

# For doxy comments let's use Doxygen Documentation Generator

# Make sure you have extensions (these are the ones that are on my MacComp, some might be unnecessary):
ms-vscode.cpptools
ms-vscode.cpptools-extension-pack
ms-vscode.cpptools-themes
twxs.cmake
ms-vscode.cmake-tools
formulahendry.code-runner
streetsidesoftware.code-spell-checker
vadimcn.vscode-lldb
mine.cpplint
cschlosser.doxdocgen
DavidSchuldenfrei.gtest-adapter
wayou.vscode-todo-highlight


# Unit tests with google
Please see this:
https://www.youtube.com/watch?v=Lp1ifh9TuFI

We use cmake tools for testing.
When you create a new files for code, you should do that within src folder.
After that open CMakeLists.txt in the cpp-pt-4 folder. 


TO WRITE/RUN TESTS

Implement tests in cpp-pt-4/tests folder.
create testtt.cpp file.


git submodule update --init for missing submodule documents
Now running the project with cmake will also run your tests.