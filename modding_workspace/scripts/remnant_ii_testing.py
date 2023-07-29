import sys
import time
import shutil
import pathlib
import win32gui
import subprocess


game_exe = "C:/games/manual_install/Remnant2/Remnant2/Binaries/Win64/Remnant2-Win64-Shipping.exe"
new_mod_pak = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk1-Windows.pak")
old_mod_pak = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_AmongUsPlayers_P.pak")
new_mod_ucas = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk1-Windows.ucas")
old_mod_ucas = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_AmongUsPlayers_P.ucas")
new_mod_utoc = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk1-Windows.utoc")
old_mod_utoc = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_AmongUsPlayers_P.utoc")
new_mod_pak_1 = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk2-Windows.pak")
old_mod_pak_1 = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_PSX_Graphics_P.pak")
new_mod_ucas_1 = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk2-Windows.ucas")
old_mod_ucas_1 = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_PSX_Graphics_P.ucas")
new_mod_utoc_1 = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk2-Windows.utoc")
old_mod_utoc_1 = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_PSX_Graphics_P.utoc")
new_mod_pak_2 = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk3-Windows.pak")
old_mod_pak_2 = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_ExampleMod_P.pak")
new_mod_ucas_2 = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk3-Windows.ucas")
old_mod_ucas_2 = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_ExampleMod_P.ucas")
new_mod_utoc_2 = pathlib.Path("C:/Users/Mythical/Downloads/Output/Windows/Remnant2/Content/Paks/pakchunk3-Windows.utoc")
old_mod_utoc_2 = pathlib.Path("C:/games/manual_install/Remnant2/Remnant2/Content/Paks/LogicMods/Z_ExampleMod_P.utoc")


def find_window_by_title(window_title):
    hwnd = win32gui.FindWindow(None, window_title)
    return hwnd
 
def move_window(hwnd, left, top, width, height):
    win32gui.MoveWindow(hwnd, left, top, width, height, True)


if pathlib.Path.is_file(new_mod_pak):
    if pathlib.Path.is_file(old_mod_pak):
        pathlib.Path.unlink(old_mod_pak)
    shutil.copy(new_mod_pak, old_mod_pak)


if pathlib.Path.is_file(new_mod_ucas):
    if pathlib.Path.is_file(old_mod_ucas):
        pathlib.Path.unlink(old_mod_ucas)
    shutil.copy(new_mod_ucas, old_mod_ucas)    
    
    
if pathlib.Path.is_file(new_mod_utoc):
    if pathlib.Path.is_file(old_mod_utoc):
        pathlib.Path.unlink(old_mod_utoc)
    shutil.copy(new_mod_utoc, old_mod_utoc)


if pathlib.Path.is_file(new_mod_pak_1):
    if pathlib.Path.is_file(old_mod_pak_1):
        pathlib.Path.unlink(old_mod_pak_1)
    shutil.copy(new_mod_pak_1, old_mod_pak_1)


if pathlib.Path.is_file(new_mod_ucas_1):
    if pathlib.Path.is_file(old_mod_ucas_1):
        pathlib.Path.unlink(old_mod_ucas_1)
    shutil.copy(new_mod_ucas_1, old_mod_ucas_1)    
    
    
if pathlib.Path.is_file(new_mod_utoc_1):
    if pathlib.Path.is_file(old_mod_utoc_1):
        pathlib.Path.unlink(old_mod_utoc_1)
    shutil.copy(new_mod_utoc_1, old_mod_utoc_1)


if pathlib.Path.is_file(new_mod_pak_2):
    if pathlib.Path.is_file(old_mod_pak_2):
        pathlib.Path.unlink(old_mod_pak_2)
    shutil.copy(new_mod_pak_2, old_mod_pak_2)


if pathlib.Path.is_file(new_mod_ucas_2):
    if pathlib.Path.is_file(old_mod_ucas_2):
        pathlib.Path.unlink(old_mod_ucas_2)
    shutil.copy(new_mod_ucas_2, old_mod_ucas_2)    
    
    
if pathlib.Path.is_file(new_mod_utoc_2):
    if pathlib.Path.is_file(old_mod_utoc_2):
        pathlib.Path.unlink(old_mod_utoc_2)
    shutil.copy(new_mod_utoc_2, old_mod_utoc_2)    
    
   
subprocess.Popen(game_exe)


time.sleep(1) 


if __name__ == "__main__":
    window_title_to_find = "UE4SS Debugging Tools (OpenGL 3)"
    hwnd = find_window_by_title(window_title_to_find)

    if hwnd != 0:
        print("Window found. Moving to the secondary screen.")
        screen_1_width = -1920
        screen_2_width = 1540
        screen_2_length = 900


        move_window(hwnd, screen_1_width, 0, screen_2_width, screen_2_length)
    else:
        print("Window not found.")
        

sys.exit()
