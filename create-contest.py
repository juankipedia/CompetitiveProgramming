import os
import shutil
import sys
import requests

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

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python create_contest.py <num> | clean")
        sys.exit(1)

    if sys.argv[1].lower() == "clean":
        delete_contest_files()
    else:
        num = int(sys.argv[1])
        template_content = download_file("https://raw.githubusercontent.com/juankipedia/CompetitiveProgramming/master/template.cpp")
        test_content = download_file("https://raw.githubusercontent.com/juankipedia/CompetitiveProgramming/master/test.bsh")
        create_contest_files(num, template_content, test_content)
