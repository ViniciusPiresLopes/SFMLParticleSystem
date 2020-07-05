import os

SRC_FILES = "*.cpp"
OBJ_FILES = "*.o"
LIBRARIES = "-lsfml-graphics -lsfml-window -lsfml-system"
EXEC_FILE = "example"

if __name__ == "__main__":
    print("""NOTE: 
    - This just compiles for linux, if you want for windows you'll need do by yourself!
    - You need: libsfml-dev and g++
    - This file need to be run on the directory of the project!""")
    try:
        os.system("g++ -c " + SRC_FILES)
        os.system("g++ " + OBJ_FILES + " -o " + EXEC_FILE + " " + LIBRARIES)

        print("Compiled with success!")
    except:
        print("Got an error, please read the NOTE")
