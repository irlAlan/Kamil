
##
# @file hey.py
# @brief The base class
#
# miew detaio
#
class Base():
    def __init__(self):
            print("From Class base")
    def noise(self):
        print("Calling from Base: mooo")


##
# @brief App class
class App(Base):
    def __init__(self):
        super().__init__()
        print("From App")

    def noise(self):
        print("Calling from App: meow")


app = App()
