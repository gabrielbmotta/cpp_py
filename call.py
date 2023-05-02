import time
import random
import threading


def callback_function(number):
    print("Received number:", number)


callback = callback_function
continue_thread = True


def threaded_function():
    global callback
    global continue_thread
    callback_counter = 0;
    while continue_thread:
        number = random.randint(1, 100)
        callback_counter += 1
        print("--------------------------------")
        print(f"I'm here calling callback -- {callback_counter}")
        callback(number)
        print("--------------------------------")
        print("")
        print("")
        time.sleep(.5)


def start(a):
    t = threading.Thread(target=threaded_function)
    t.start()
    return 1000


def stop():
    global continue_thread
    continue_thread = False


if __name__ == "__main__":
    start()
