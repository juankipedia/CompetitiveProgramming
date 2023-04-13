# Competitive Programming Contest Setup

This Python script, `create_contest.py`, helps you set up a competitive programming contest workspace with directories and files for each problem, as well as configure Visual Studio Code for a better workflow.

## Usage

```
python create_contest.py <num> | clean | delete
```

### Parameters

- `<num>`: The number of problems in the contest (integer between 1 and 26). It will create the corresponding number of directories (A, B, C, ...) containing the `.cpp` file, four input files, and a test script.
- `clean`: Deletes all contest directories (A to Z) if they exist.
- `delete`: Resets the Visual Studio Code configuration (removes `tasks.json` and clears `keybindings.json`), and deletes all contest directories (A to Z) if they exist.

## Setup

1. Make sure you have Python 3 installed on your system.
2. Download the `create_contest.py` script.
3. Ensure you have internet access, as the script will download necessary files from GitHub.
4. (Optional) Configure the `keybindings_path` variable in the script for your specific operating system (the script is pre-configured for macOS; Linux and Windows paths are commented out).
5. Run the script using the command line with the desired parameters as explained above.

## Visual Studio Code Configuration

The script automatically configures Visual Studio Code for the contest. It downloads `tasks.json` and `keybindings.json` files and places them in the appropriate locations. You can customize these files as per your preference by directly modifying the content in the `create_contest.py` script or adjusting the files after they have been placed by the script.

## During Contest

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
