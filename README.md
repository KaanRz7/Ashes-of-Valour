Markdown

# ⚔️ Ashes of Valour | Tactical Combat Engine
### A Turn-Based Tactical RPG Console Game in C++

> A robust, text-based tactical RPG engine built purely in C++, featuring an arcade-style terminal user interface (UI) and persistent console UX flow.

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![OOP](https://img.shields.io/badge/Architecture-Object%20Oriented-orange.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

---

## 🖥️ Preview / Interface Aesthetic

Designed with a centered, block-framed ASCII aesthetic and dynamic terminal colors to provide a stable, "arcade cabinet" feel without disruptive screen clearing:

### Splash Screen & Startup Flow
```text
          =======================================================================
                                 AA       OOOOOOO   VV      VV               
                                A  A     OOO   OOO   VV    VV                
                               AAAAAA    OOO   OOO    VV  VV                 
                              A     A     OOO   OOO     VVV                  
                             A       A     OOOOOOO      VV                   
          =======================================================================
                              * A S H E S   O F   V A L O U R *                     
          =======================================================================

                               PRESS ENTER TO START...
                     ( For the best experience, play in full screen )
                            ~ Made By Kaan Tanriverdi ~ 

Main Menu Interface
Plaintext

          ===============================================================
          ||                                                           ||
          ||            ~  A S H E S   O F   V A L O U R  ~            ||
          ||                                                           ||
          ===============================================================
                    [1] Start New Game
                    [2] How to Play (Recommended)
                    [3] Version & Patch Notes
                    [4] Future Improvements
                    [5] Exit Game
          ===============================================================
                            >>> Your Choice: 
---

✨ Key Features

    Modular System Architecture (.h/.cpp): Designed a decoupled multi-file codebase enforcing strict separation of concerns across game states, core logic, and tactical combat modules.

    Polymorphic Class Hierarchies: Utilized robust object-oriented paradigms, class inheritance, and custom virtual function overrides to handle dynamic entity behaviors seamlessly.

    Resilient UX & Terminal Flow: Crafted an arcade-style command-line interface that avoids disruptive screen clearing to preserve battle history, enhanced with custom ANSI styling and terminal guidance.

    Robust Input Sanitization & Stream Safety: Implemented bulletproof console input loops leveraging std::cin.fail(), .clear(), and .ignore() to completely eliminate stream corruption and infinite loop vulnerabilities.(input validation loops for each types)

    Modern Tooling & Solution Management: Built and organized using modern Visual Studio solution layouts (.slnx), ensuring clean build configurations, reliable header dependencies, and production-grade project structure.



---

🛠️ Technologies Used

    C++

    Object-Oriented Programming (OOP)

    Visual Studio / Terminal CLI


---

🚀 How to Run

    Open the solution file (.slnx) with Visual Studio.

    Build the project.

    Run the application in *Fullscreen mode* for the optimal terminal UI experience!


---

📚 What I Learned & Technical Challenges Overcome

   Building Ashes of Valour from scratch pushed me deep into advanced systems-level C++ concepts, robust object-oriented architecture, and clean memory management. Here are the core technical takeaways and architectural pillars from this project:

   * Advanced Object-Oriented Architecture & System Hierarchy: Designed a scalable multi-file system across modular .h and .cpp files, properly managing #include directives, header dependencies, include guards, custom classes, structs, and enums. Built specialized character subclasses includes ability.h file and inheriting from a core base class, paired with a robust top-down management flow where GameManager controls states, delegating game flow to RoundSystem, which in turn coordinates tactical encounters via BattleSystem through clean instance references and object composition.

   * Inheritance & Class Hierarchies: Designed robust parent-child relationships where core attributes and shared behaviors are centralized in a versatile base class, while specialized player and enemy subclasses extend it using constructor initialization lists and custom virtual function overrides tailored to their specific roles. This maximized code reuse, eliminated redundancy, and established a clean taxonomic flow across all game entities.
   
   * Polymorphism & Virtual Functions: Leveraged dynamic polymorphism and virtual functions (including virtual destructors) to manage unified interfaces for combat actions, rendering behaviors, and entity interactions without tight coupling.

   * Pointer & Reference Management: Managed dynamic object lifecycles by instantiating characters via pointers, storing their memory addresses in vectors, and using references (&) across modular scopes for optimized data access. Implemented clean destruction logic upon character death—safely freeing allocated memory via pointers before removing stale memory addresses from collection vectors to prevent dangling pointers and memory leaks.

   * Smart Input Validation & Stream Control: Built reliable input loops across all menus to handle different data types correctly (like expecting numbers instead of random letters). Handled standard library stream errors properly using std::cin.fail(), .clear(), and .ignore() to prevent infinite loops and keep the game running smoothly.

   * Color-Coded Terminal UI & Utility Modularity (utils.h): Encapsulated helper functions—including custom ANSI color macros (CYAN, GREEN, YELLOW, RED) and screen clearing logic (clearConsole())—into a dedicated utils.h module to keep the codebase clean and the terminal interface visually engaging.
   
   * State Machine & Flow Control: Implemented robust game-loop logic and clean switch-case menu navigation structures to manage transitions smoothly between main menus, active combat loops, and informational screens.

   * Professional Tooling & Version Control: Structured the project using modern Visual Studio solution layouts (.slnx), managing clean build configurations and preparing production-ready GitHub repositories.



---

🔮 Future Improvements & Roadmap

As **Ashes of Valour** evolves, here is the roadmap of upcoming gameplay systems and architectural expansions:

- **Inventory & Item System:** Consumable items (potions, scrolls) and equippable gear to add deeper tactical layers to hero management.
- **Dynamic Round-Based Stat Scaling:** Adaptive HP, Attack, and Defense modifiers that evolve dynamically based on round progression and battle status.
- **Resource & Mana Management:** A full-fledged Mana/Energy system for high-tier Hero abilities to balance cooldowns and skill usage.
- **Level & Coin System:** A basic single-player mode including a level system and a coin system to gain coins per level and acquire items.

> **Note:** More features will be added as new creative ideas (or absurd gameplay mechanics) come to mind =))


---

📌 Version

Current Version: V1.0

This is the first stable release of the project. Future versions will include additional features and gameplay depth as I continue building my C++ and software engineering skills.



👨‍💻 Author

Developed by Kaan Tanriverdi as a personal project exploring advanced C++, Object-Oriented Programming, and robust System Design.



💡 Note

This project is a product of my ongoing journey learning software engineering, focusing on writing modular code, leveraging advanced OOP paradigms, and paying attention to small details like user experience in command-line environments.