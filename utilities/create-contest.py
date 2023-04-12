import os
import shutil
import sys
import requests
import json
import platform

    
keybindings_path = '~/Library/Application Support/Code/User'
# For Linux, uncomment the following line:
# keybindings_path = '~/.config/Code/User'
# For Windows, uncomment the following line:
# keybindings_path = r'%APPDATA%\Code\User'

def download_file(url):
    response = requests.get(url)
    if response.status_code == 200:
        return response.text
    else:
        print(f"Error downloading {url}: HTTP {response.status_code}")
        sys.exit(1)

def create_contest_files(num, template_content, test_content):
    if num < 1 or num > 26:
        print("Please provide a number between 1 and 26.")
        return

    for i in range(num):
        dir_name = chr(ord('A') + i)
        os.makedirs(dir_name, exist_ok=True)

        cpp_file = os.path.join(dir_name, f"{dir_name}.cpp")
        with open(cpp_file, "w") as f:
            f.write(template_content)

        test_file = os.path.join(dir_name, "test.bsh")
        with open(test_file, "w") as f:
            f.write(test_content)

        for j in range(1, 5):
            input_file = os.path.join(dir_name, f"in{j}")
            with open(input_file, "w") as f:
                pass  # Creates empty input files

def delete_contest_files():
    for i in range(26):
        dir_name = chr(ord('A') + i)
        if os.path.exists(dir_name):
            shutil.rmtree(dir_name)

def setup_vscode(tasks_content, keybindings_content):
    vscode_dir = os.path.join(os.getcwd(), '.vscode')

    if not os.path.exists(vscode_dir):
        os.makedirs(vscode_dir)

    tasks_file = os.path.join(vscode_dir, 'tasks.json')
    if not os.path.exists(tasks_file):
        with open(tasks_file, "w") as f:
            f.write(tasks_content)

    if keybindings_path:
        keybindings_file = os.path.join(os.path.expanduser(keybindings_path), 'keybindings.json')
        with open(keybindings_file, "w") as f:
            f.write(keybindings_content)

def reset_vscode_config():
    vscode_dir = os.path.join(os.getcwd(), '.vscode')

    tasks_file = os.path.join(vscode_dir, 'tasks.json')
    if os.path.exists(tasks_file):
        os.remove(tasks_file)
        
    if keybindings_path:
        keybindings_file = os.path.join(os.path.expanduser(keybindings_path), 'keybindings.json')
        if os.path.exists(keybindings_file):
            with open(keybindings_file, "w") as f:
                f.write("[]")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python create_contest.py <num> | clean | delete")
        sys.exit(1)

    if sys.argv[1].lower() == "clean":
        delete_contest_files()
    elif sys.argv[1].lower() == "delete":
        reset_vscode_config()
        delete_contest_files()
    else:
        num = int(sys.argv[1])
        template_content = download_file("https://raw.githubusercontent.com/juankipedia/CompetitiveProgramming/master/utilities/template.cpp")
        test_content = download_file("https://raw.githubusercontent.com/juankipedia/CompetitiveProgramming/master/utilities/test.bsh")
        tasks_content = download_file("https://raw.githubusercontent.com/juankipedia/CompetitiveProgramming/master/utilities/vscode/tasks.json")
        keybindings_content = download_file("https://raw.githubusercontent.com/juankipedia/CompetitiveProgramming/master/utilities/vscode/keybindings.json")

        create_contest_files(num, template_content, test_content)
        setup_vscode(tasks_content, keybindings_content)

