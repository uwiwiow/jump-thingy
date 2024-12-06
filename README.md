# Jump Thingy

**Jump Thingy** is a simple platformer game where you control a character that must jump between platforms while avoiding falling off the screen. It is a project developed in C using [raylib](https://www.raylib.com/) as the graphics library.

---

## 📋 Description

In **Jump Thingy**, your goal is to keep the player moving across platforms without falling into the kill zone. Platforms are generated randomly, and the player can move sideways and jump to avoid obstacles and keep progressing.

---

## 🚀 Features

- Random platform generation.
- Basic physics simulation (gravity and forces).
- Collision detection with platforms and screen edges.
- Smooth movement and intuitive controls.
- Uses [raylib](https://www.raylib.com/) for graphics and input handling.

---

## ⚙️ Requirements

To compile and run the game, you need:

- **Operating System**: Linux.
- **Compiler**: GCC or any C-compatible compiler.
- **Libraries**:
    - [raylib](https://github.com/raysan5/raylib) (installed and linked).

---

## 🛠️ Compilation

1. Clone this repository:
   ```bash
   git clone https://github.com/uwiwiow/jump-thingy.git
   cd jump-thingy
    ```
2. Compile the project using CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
   ```

3. Run the generated binary:

    ```bash
    ./jumpThingy
    ```

## 📚 Generating Documentation

1. First, ensure you have [Doxygen](https://www.doxygen.nl/) installed.

2. In the project root directory, where the Doxyfile is located, run the following command to generate the documentation:

    ```bash
    doxygen Doxyfile
    ```

3. The documentation will be generated in the doxygen directory, and you can open the HTML files inside the doxygen/html folder to view the documentation.

## 🎮 Controls

    A: Move left.
    D: Move right.
    S: Reduce falling speed.
    R: Restart the game.

## 📚 Project Structure

    .
    ├── CMakeLists.txt      # Build configuration with CMake
    ├── Doxyfile            # Documentation configuration with Doxygen
    ├── includes            # Header files
    │   ├── globals.h
    │   ├── platforms.h
    │   └── player.h
    ├── src                 # Source files
    │   ├── main.c
    │   ├── platforms.c
    │   └── player.c
    └── doxygen             # Documentation output

## 🕹️ How to Play

The goal is to avoid falling into the kill zone while jumping across platforms. Use A and D to move sideways, and S to control your falling speed. Try to survive as long as possible!

## 🛡️ License

This project is licensed under the [MIT License](https://github.com/uwiwiow/jump-thingy/blob/main/LICENSE). Feel free to use, modify, and share it.

## 🤝 Contributions

Contributions are welcome! If you find a bug or have a suggestion, open an [issue](https://github.com/uwiwiow/jump-thingy/issues) or submit a pull request.

## 📧 Contact

Developed by Uwiwiow.

[GitHub](https://github.com/uwiwiow) |
[Mail](mailto:gael.perez.dev@gmail.com)