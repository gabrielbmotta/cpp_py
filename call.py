import time
import random
import threading


def callback_function(number):
    print("Received number:", number)


def threaded_function():
    while True:
        number = random.randint(1, 100)
        callback_function(number)
        time.sleep(2)


def start(a):
    print("Here is your number")
    print(a)
    t = threading.Thread(target=threaded_function)
    t.start()


if __name__ == "__main__":
    start()
