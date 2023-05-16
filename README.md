# Kamil Editor

A Text Editor for kamil

## Analysis

### Background and Identifying the problem


The Project I will be developing will be in answer to the challenge set out by
the end user and friend of mine, Kamil. He challenged me to make a lightweight
editor that he can use in his day-to-day life and when doing Python projects and general day-to-day use.

The challenge started when he commented on my use of neovim and how it would be better if I used an actual IDE.
I told him that I've used IDEs in the past and overall prefer the look and feel of a customized neovim. I then suggested that he
learn Vim himself and that he wouldn't regret it, but he declined. Kamil then told me that I should create something easier
for him to use and that could potentially change his use of IDEs.

Upon being issued with this challenge I created a few starter questions that I would research around for my NEA.

1) What is a text editor and how does it differ from an IDE?
2) How do I make a text editor for Kamil
3) How do I make it efficient enough to meet his standards?

To kick things along I began to research Text editors and IDEs and
found out that the difference between them isn't limited to Operating System platforms
or by how much better one is at a specific task but by the features each can do.
Text Editors, as the name suggests are specifically designed for manipulating any form of text
that it can open. While an IDE (Integrated Development Environment) is specifically designed
for software development and comes with a multitude of features that engineers can make use of
to streamline their workflow.


A table of pros and cons:

|               | Pros               | cons                        |
|---------------|--------------------|-----------------------------|
| Text Editor   | Light weight,      | Limited in capability       |
|               | Fast,              |                             |
|               | Resource efficient |                             |
|               | Very Modular       |                             |
|               |                    |                             |
| IDE           | Has everything out the box| Slow                        |
|               |                    | Not very Resource efficient |
|               | can view memory    | Too many menus              |
|               |                    | Limited in compatability    |



Here are pictures of some text editors and IDE's:

\image latex neovimLook.eps "My Neovim" width=10cm


\image latex baseVimLook.eps "My Vim" width=10cm


### End User needs

When talking to Kamil about his needs it was apparent that he wanted something modular
in the sense that it comes with what he needs so it is not a hassle to work with and it
works with multiple different file types.


\image latex Kamil_info.eps


Since this is a project that could quickly grow in scale due to all the different parts of the editor, text and documents.
The overall time complexity of the different algorithms coming together could increase the latency between the different commands.
To ensure that the project meets the needs of Kamil, I have a few objectives.

#### Objective 1

Optimised:

Ensure that the program is properly optimised and not laggy.
To ensure that the program is not laggy and has minimal delay we can get the time taken between function calls and their effect
like the time taken for a key press to happen and it being executed.

Furthermore, In the code youll see optimisation techniques such as passing classes by pointer which essentially allows me
to directly access the class in memory instead of accessing a copy of the class.

#### Objective 2

User configurable:

Allow it to be user configurable. We need the ability to load and use
fonts specified by the user as well as change the theme of the program based on what the user wants.

We can check this by successfully storing font files and changing them as well as having the user
use a theme through a colourscheme and successfully have the program use them.

#### Objective 3

Run Python:

Run Python programs.
Since Kamil mainly codes in Python having some python compatability would help him greatly.
With that said we would need to be able to write, save and run python code and have it be accurate.

This is easily measurable since a fully working python Implementation would be able to run and save our own files.


#### Objective 4

File I/O:

Allow for user data to be stored and recalled locally in a file system.
For the Text editor to be a text editor we need the ability to successfully access the file tree system
this allows for further I/O like file saving and writing.

To test if this feature works we need to successfully save and load a file.


#### Objective 5

Cross-platform:

Allow for cross platform support. Have the program successfully run on at least 2 of the 4 different Operating systems
tehe four being, Windows, Mac, Linux, OpenBSD.

Upon completion the program would be completely cross-platform.


To summarise the objectives, the program must be:

- Cross-platform
- User-configurable
- file I/O
- Run Python files
- Not Laggy

### Limitations

The Limitations of my program are what give it a general architecure to work with.
The Limits my program will face are:

#### Limitations 1

Programming Language:

When it comes to the Programming Language I wrote my project in C++ (Cpp, Cxx, cc) with access to the C++17 language standard.
I chose this language becauase I am most familiar with it and prefer it over python for larger projects like this.
It is a fast and performant language with good cross compatability which would make it good for the project.

#### Limitations 2

Formatting standard:

This limitation is for the reusability and modularbility of the program when different users are making changes or when
you come back to the code after a while. It is to keep everything orderly so you can focus entierly on the problem solving
without having to worry about spaces and comments.

When it comes to writing good clean code, formatting the code is a big necessity
that can help the overall functionality of the code and user experience.

An example being:

    \code{.cpp}

    //without a formatting standard

    int printAninttoOutput
    (int val) {return val;}


    int setintTooutPut
    (int val){
        reutrn val
    }
\endcode

\code{.cpp}

// with a formatting standard

int Print_Int_To_Out(int val){
    return val;
}

int Set_Int_To_Out(int val){
    return val
}
\endcode

From the examples shown above its clear that with the formatting the code is easier to read without any weird (but legal) C++ syntax,
     it also allows programmers to see a pattern and predict what the function they want to call is called without checking documentation.

#### Limitations 3

Operating System:

The operating System is a default limiter and denotes how everything comes together.
By default I use Linux. This has the benefit of having more support for C++ coding and development in general
with the caveat of programs not being very portable to other devices like windows machines.
This means that I will either need to cross-compile my program or convert Kamil, who is a windows user, over to Linux.

#### Limitations 4

Libraries:

Similar with the Operating system the functionality of a program is limited by the libraries that it calls and uses.
For this project I need to use libraries that are cross platform and efficient.


### Design

Throught the creation of the project I utilised a mix between modular and iterative design procedure where I would have a seperate test project (not one - one)
that had all the basic functionality I needed and I would make the feature I am trying to add and test it on this dummy code, using
techniques like integration and white-box testing. I would then iterate on any bugs found and fix them before moving the code to the main project. 

My workflow is as:

\image latex reg.eps workflow


Example regex:

\image latex regexTest.eps

\image latex regexAfterTest.eps After testing

#### Design Choices general

When developing the project I made a series of design choices that I thought would be best for the project.

For the Libraries I will be using I chose to go with SFML for graphics, fmtllib for formatted printing and tomlc++ for .toml I/O.

SFML is a graphics library that gives access to Opengl functions, it is also be used stand alone.

fmtlib is a formatting library for standard out printing, it gives rust and python style printing to Cpp whilst being fast and efficient.
fmtlib is faster than normal cpp standard out functions and the c-style printf whilst being safer.

\image latex fmtlibSpeed.eps

tomlc++ is a header only library that handles reading and writing to toml, json and yaml files. It handles everything in toml
but can convert to json and yaml. It is very efficient and makes it easy for the user to configure the program

\image latex tomlCDoc.eps

In SFML when writing text to a screen it takes a, const sf::String& string, which devolves into std::string types and char[] arrays.
Due to this and a need to be efficient I made the choice to manipulate all text input and output in a dynamic one dimensional character array
(std::string), By doing this any changes that can be made I just need to loop through the string checking each character for what im looking for.
They take up minimal space since it is stored as a single string which is by default 24 bytes.

This also has the added benefit of always knowing its length and size as well as being able to convert into other types when needed.

Furthermore, I also made some optimisation decisions like, passing classes used through by pointer and dynamically allocating them on the heap when created.
I did this because when they are passed through by pointer the program is only accessing one instance of it and not copying the class, manipulating
it and then passing the values back to it when its done like what happens by default when passing a class through parameters. This choice speeds up the program
since it doesnt need to copy and directly access the class.

#### Design Choices in OOP

When making the code I decided to use Object Oriented programming instead of Generic or Functional programming. This is because
I wanted to maximise the modularbility of my code and make it easily scalable since all the related data would be grouped together
and I can control how the data is modified behind the scenes leaving only the interface details to use.

I would use many different techniques such as, prefering composition over inheritance unless its necessary; polymorphic behaviour and
class dynamic heap allocation.

\image latex compOverInhertance.eps

I would instantiate classes inside other classes so i can manipulate their behaviour without inherting it directly. I did this
because if I mainly inherited the classes then when i change the values of the parent class through the child class
and i want to pass those values to a different subroutine or class I would need to copy the data over or pass in the child class and use that to access
the values in the parent class. But by having an instantiated class inside I can simply call that variable and not the whole child class.


\image latex inheritance.eps

Inhertance is only done here so the class becomes recognised as Drawable by sf::RenderTargets i.e. RenderWindow.
polymorphic behaviour is also shown here since when inheriting from sf::Drawable its mandatory to override the draw method.

\image latex polymorph.eps


Finishing off this section is Dynamic class allocation.
When instantiate classes inside others like TextBox inside Editor I would dynamically create them, add them to the heap and not stack,
this is because the classes are decently large in memory and
I would be changing the values held inside the classes fairly often and it would be more problematic to have it pushed onto the stack.


### Testing the code

When it comes to testing the project I have 3 main points of focus:

1) The data being transferred around the project
2) The data is read from and saved to a file
3) Does it meet the objectives

Focussing on the first two points youll see that:

When it comes to testing the project  when reading and saving to a file, I have made use of white-box testing.
This form of testing is most apparent when the program is handling the file data and keyboard Inputs.
Since white-box testing is the process of making the data flow apparent and that there are no broken loops through the code. I make sure that the data is
printed out at each stage in plain text and in hex so that we can view it and see if any changes have happened that shouldnt have happened.

\image latex testWhiteBox.eps

When checking how large the data I could send around the program was
I made use of light integration testing by increasing the size of file
and data the program transferes each time but I am yet to hit the maximum.
It theoretically should be the same size as the computer allows since everything is trasnfered through a string which is dynamic ini size and we are
most of the time accessing it directly in memory wich gets rid of any extra overhead.

Onto the final point of it meeting the objectives.

The program is optimised and extremly quick opening approx 1k lines immediatly.
key presses were routinely sub 1 millisecond.

\image latex timeTakenMS.eps millisecond time

\image latex timTakenNS.eps nanosecond time


The project can be loaded from a config file called config.toml

\image latex Eval.eps

The project works is cross platform and works in windows

*+(show work in linux)
