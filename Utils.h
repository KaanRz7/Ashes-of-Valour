#pragma once 
#include <cstdlib>
#include <iostream>


inline void clearConsole() {  // to clear console!!! (NOTE: in utils, by using 'inline', defining more than once error can be prevented.)
#if defined(_WIN32) || defined(_WIN64)
	std::system("cls");
	std::cout << "\033[H"; // to scroll to the top ( problem only on windows not macOS)
#else
	std::system("clear") //for linux, macOS etc...
#endif
}

//COLORS & FONTS:
inline const char* RED = "\033[1;31m"; // WE USED INLINE INSTEAD OF STATIC TO MAKE IT FASTER.(IN STATIC, EVERY FILE THAT UTILS.H INCLUDED CREATE IT'S OWN COLOR AND THAT CAUSE SLOWNESS -BUT STATIC PREVENTS LINKAGE FOR SURE-.) 
inline const char* GREEN = "\033[1;32m";
inline const char* YELLOW = "\033[1;33m";
inline const char* CYAN = "\033[1;36m";
inline const char* WHITE = "\033[1;37m";
inline const char* RESET = "\033[0m";
inline const std::string BOLD = "\033[1m";

//IN FUTURE IMPROVEMENTS, FOR MORE READABLE CODE	, INPUT AND COLOUR FUNCTIONS (MAYBE MORE TO COME) WILL BE ADDED.