<h1 align="center">
    study-xmake
</h1>

<p align="center">
    A study project to learn the xmake build system, by rebuilding
    <a href="https://github.com/kutaycoskuner/study_cmake">study-cmake</a> layer by layer
    with Clang on Windows (MSYS2 CLANG64).
</p>

<p align="center">
    <img alt="xmake" src="https://img.shields.io/badge/xmake-3.1-blue" />
    <img alt="Clang" src="https://img.shields.io/badge/Clang-22-blue?logo=llvm&logoColor=white" />
    <img alt="C++" src="https://img.shields.io/badge/C++-20-blue?logo=cplusplus&logoColor=white" />
    <img alt="Project Version" src="https://img.shields.io/badge/Project_Version-0.14-blue" />
    <img alt="Start Date" src="https://img.shields.io/badge/project_start-07_Oct_2026-blue" />
    <img alt="Last Update" src="https://img.shields.io/github/last-commit/kutaycoskuner/study-xmake" />
</p>

------------------------------------------------------------------------------------------

## Folders

```bash
study-xmake/
├── headers/                    # Header files, found through add_includedirs("headers")
├── libs/                       # Libraries built from source (header-hello-1.0.0: static library hello)
├── source/                     # Program source code (main.cpp, my_functions.cpp)
├── xmake.lua                   # Build description: targets, files, include folders, modes
├── bin/                        # Program output: bin/<plat>/<arch>/<mode>/ (generated, not committed)
├── build/                      # Object files and intermediates (generated, not committed)
└── .xmake/                     # Stored configuration from `xmake f` (generated, not committed)
```

------------------------------------------------------------------------------------------

## Installation and Usage

### Prerequisites
- **Windows 10/11**
- **Git**: [Install Git](https://git-scm.com/downloads)
- **MSYS2**: [Install MSYS2](https://www.msys2.org/), then in the **MSYS2 CLANG64** shell:
    ```bash
    pacman -S mingw-w64-clang-x86_64-clang mingw-w64-clang-x86_64-lld mingw-w64-clang-x86_64-xmake
    ```

### Build and run

Run these in the **MSYS2 CLANG64** shell.

```bash
# 1. Clone the repository
git clone https://github.com/kutaycoskuner/study-xmake.git
cd study-xmake

# 2. Configure: platform, toolchain and mode (stored in .xmake/)
xmake f -c -p mingw --toolchain=clang -m release

# 3. Build (-v prints the full compiler and linker commands)
xmake -v

# 4. Run the program (built to bin/mingw/x86_64/release/tutorial.exe)
xmake run
```

> `-p mingw` is required: inside MSYS2, xmake guesses the platform `msys`, which builds
> programs that depend on `msys-2.0.dll`.
>
> Switch to a debug build with `xmake f -p mingw --toolchain=clang -m debug`, then `xmake` again.
> The output goes to `bin/mingw/x86_64/debug/`.

------------------------------------------------------------------------------------------

## Exercises

Each exercise adds one xmake concept, in the order study-cmake was built.

- [x] 1. One program: `target`, `set_kind("binary")`, `add_files`
- [x] 2. A second source file and a header folder: `add_files("source/*.cpp")`, `add_includedirs`
- [x] 3. Static library `hello`: `set_kind("static")`, `add_deps`
- [x] 4. Defines, build modes and output folder: `add_defines`, `xmake f -m debug/release`, `set_targetdir`
- [ ] 5. Packages instead of submodules: `add_requires("glfw", "assimp")`, `add_packages`, `add_syslinks("opengl32")`

------------------------------------------------------------------------------------------

## References

- **Learning**
    - xmake documentation, [xmake.io](https://xmake.io)
    - `xmake show -l apis`: lists every xmake API name
- **Related projects**
    - [study-cmake](https://github.com/kutaycoskuner/study_cmake): the CMake project rebuilt here
    - [study-opengl](https://github.com/kutaycoskuner/study-opengl): the renderer this toolchain is being learned for
- **Dependencies**
    - Tools: MSYS2 (CLANG64), Clang, LLD, xmake, Visual Studio Code
