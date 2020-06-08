from serial import Serial
import serial
import time
import pyautogui

ArduinoSerial = serial.Serial("/dev/tty.usbmodem14201", 9600)
time.sleep(2)

while 1:
    incoming = str(ArduinoSerial.readline())
    print (incoming)
    if "Play/Pause" in incoming:
        pyautogui.typewrite(['space'], 0.2)
    if 'Forward 10' in incoming:
        pyautogui.hotkey("l")
    if "Backwards 10" in incoming:
        pyautogui.hotkey("j")

    incoming = ""
