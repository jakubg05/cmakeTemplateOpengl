# OpenGL Template Repository

This template repository is designed to **get your OpenGL projects off the ground quickly**, with essential graphics programming libraries pre-included:

* **GLFW:**  Window creation and input management
* **GLEW:** OpenGL extension loading
* **GLM:** Mathematics for graphics
* **ImGui (with docking branch):** User interface creation
* **stb_image:** Loading image files
* **stb_truetype:** Loading TrueType fonts

## Operating System Support

This project is tailored for:

* **Windows** using Visual Studio
* **Linux** using VS Code (or other compatible IDE)

## Project Structure

* **core:**  Write common, reusable rendering code here.
* **app:**  Create code for specific scenes or applications.
* **thirdparty:** Houses all third-party libraries.

This separation keeps your project organized and promotes code reusability.

## Building Your Project

### Windows (Visual Studio)

1. Clone this repository:
```
git clone --recursive https://github.com/jakubg05/cmakeTemplateOpengl your-project-name
cd your-project-name
git submodule update --init --recursive 
```
2. Right-click the cloned folder and select "Open with Visual Studio," or open Visual Studio and navigate to File -> Open -> CMake... and choose the root CMakeLists.txt.
3. Run the Debug build.
4. Create a Release configuration by clicking the x64-Debug dropdown and adding x64-Release.
5. Choose your desired executable from the box on the right and hit the run button.

### Linux

1. Create a build directory: `mkdir build`
2. Navigate to the build directory: `cd build`
3. Generate build files: `cmake ..`
4. Build the project: `cmake --build .`
5. Run the executable: `./cmakeMain`

**Linux Troubleshooting:** If you encounter OpenGL errors, try the following:
   `sudo apt-get install libgl1-mesa-dev libegl1-mesa-dev`

### Visual Studio Code Intellisense

To resolve Intellisense squiggles:

1. Press Ctrl + Shift + P
2. Choose "C/C++: Edit Configurations (UI)"
3. Ensure your compiler path and IntelliSense mode are set correctly (e.g., "g++-11")

## Project Structure and CMake

This project uses a slightly more advanced CMake setup to promote code organization and reusability:

* **Core as a Static Library:** The `core` directory contains its own CMakeLists.txt file and is configured to be built as a static library. This means the compiled code from the `core` directory is packaged into a single `.lib` (Windows) or `.a` (Linux) file.

* **Application Linking:** The `app` directory doesn't have its own CMakeLists.txt. Instead, the root CMakeLists.txt handles:
* Building the executable for the application
* Linking the application's executable against the `core` static library
* Linking the application's executable against the third-party libraries (GLFW, GLEW, etc.)

**Benefits of this approach:**

* **Code Reusability:** The `core` library can potentially be used in other OpenGL projects without modification.
* **Clean Separation:** There's a clear distinction between reusable rendering logic (`core`) and the application-specific code (`app`).

*This project is derived from https://github.com/meemknight/openglConfiguration*
