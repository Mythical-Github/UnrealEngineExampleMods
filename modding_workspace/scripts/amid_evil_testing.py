import os
import sys
import time
import shutil
import psutil
import pathlib
import hashlib
import win32gui
import subprocess


os.system("title Amid Evil Mod Testing")


pak_list = (
    r"Paks\LogicMods", "Z_ExampleMod_P",     1, "off",
    r"Paks\LogicMods", "Z_Testing_P",        2, "off",
    r"Paks\LogicMods", "Z_PSX_Graphics_P",   3, "on",
    r"Paks\LogicMods", "Z_FreeCamera_P",     4, "on"
)
pak_list_width =  4


process_list = (
    r"Fmodel.exe",
    r"AmidEvil-Win64-Shipping.exe"
)


screen_1_width =  -1920
screen_2_width =  1235
screen_2_length = 800
old_prefix =      r"C:\Users\Mythical\Downloads\Output\WindowsNoEditor\AmidEvil\Content\Paks\pakchunk"
old_suffix =      r"-WindowsNoEditor"
new_prefix =      r"C:\Program Files (x86)\Steam\steamapps\common\Amid Evil\AmidEvil\Content"
game_exe =        r"C:\Program Files (x86)\Steam\steamapps\common\Amid Evil\AmidEvil\Binaries\Win64\AmidEvil-Win64-Shipping.exe"


# -----------------------------------------------------------------------------------------------------------------------


def get_hash_of(file_to_hash):
    with open(file_to_hash, "rb") as f:
        f_byte = f.read()
        result = hashlib.sha256(f_byte)
        return result.hexdigest()


def is_process_running(process_name):
    for proc in psutil.process_iter():
        try:
            if process_name.lower() in proc.name().lower():
                return True
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass
    return False


for i in process_list:
    if is_process_running(i):
        os.system("taskkill /f /im " + i)


i = 0


while i < len(pak_list):
    old_suffix = r"-WindowsNoEditor.pak"
    old = old_prefix + str(pak_list[i + 2]) + old_suffix
    test_1 = pak_list[i + 1]
    test_2 = f"{test_1}.pak"
    new = os.path.join(new_prefix, pak_list[i], test_2)

    if os.path.isfile(old) and pak_list[i + 3] == "on":

        if os.path.isfile(new):
            if get_hash_of(old) != get_hash_of(new):
                shutil.copyfile(old, new)
        else:
            shutil.copyfile(old, new)
    else:
        if pak_list[i + 3] == "off":
            if os.path.isfile(new):
                pathlib.Path.unlink(new)            
    i += pak_list_width


i = 0


subprocess.Popen(game_exe)


time.sleep(1)


def find_window_by_title(window_title):
    hwnd = win32gui.FindWindow(None, window_title)
    return hwnd


def move_window(hwnd, left, top, width, height):
    win32gui.MoveWindow(hwnd, left, top, width, height, True)


window_title_to_find = "UE4SS Debugging Tools (OpenGL 3)"
hwnd = find_window_by_title(window_title_to_find)
move_window(hwnd, screen_1_width, 0, screen_2_width, screen_2_length)


pause


sys.exit()
