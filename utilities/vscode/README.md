# Competitive Programming VSCode Setup

This guide will help you set up Visual Studio Code (VSCode) for competitive programming using the provided `tasks.json` and `keybindings.json` files.

## Prerequisites

1. Visual Studio Code installed.
2. GCC Compiler installed.

## Setup

### 1. Configure tasks

The provided `tasks.json` file contains tasks to compile and run your code using test cases.

To configure tasks in VSCode:

1. Open your competitive programming folder in VSCode.
2. In the Explorer pane, expand the `.vscode` folder. If it doesn't exist, create it.
3. Inside the `.vscode` folder, create or edit the `tasks.json` file.
4. Copy and paste the contents of the provided `tasks.json` file into your `tasks.json` file and save it.

### 2. Configure keybindings

The provided `keybindings.json` file contains custom keybindings for running tasks.

To configure keybindings in VSCode:

1. Open the Command Palette with `Ctrl+Shift+P` or `Cmd+Shift+P` (macOS).
2. Type "Open Keyboard Shortcuts (JSON)" and select the command.
3. Copy and paste the contents of the provided `keybindings.json` file into your `keybindings.json` file and save it.

## Usage

With the provided `tasks.json` and `keybindings.json` files configured, you can use the following shortcuts to compile and run your code:

- `Ctrl+Alt+0`: Execute the compiled program without any input file.
- `Ctrl+Alt+1`: Compile and run the program using `in1` as input.
- `Ctrl+Alt+2`: Compile and run the program using `in2` as input.
- `Ctrl+Alt+3`: Compile and run the program using `in3` as input.
- `Ctrl+Alt+4`: Compile and run the program using `in4` as input.
- `Ctrl+Alt+5`: Compile and run the program using `in5` as input.
- `Ctrl+Alt+6`: Compile and run the program using `in6` as input.

Make sure to create the input files (e.g., `in1`, `in2`, `in3`, etc.) in the same directory as your source code file.

Happy coding!
