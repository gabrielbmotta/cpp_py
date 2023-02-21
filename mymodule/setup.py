from setuptools import setup, Extension


def main():
    setup(name="add_module",
          version="1.0.0",
          description="Adds numbers",
          author="<your name>",
          author_email="your_email@gmail.com",
          ext_modules=[Extension("add_module", ["add_module.cpp"])])


if __name__ == "__main__":
    main()
