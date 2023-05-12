# Kamil Editor

A Text Editor for kamil

## Analysis

### Background and Identifying the problem

The Project I will be developing will be in answer to the challenge set out by
the end user and friend of mine, Kamil. He challenged me to make a light weight
editor that he can use in his day to day life and when doing python projects.

The challenge started when he commented on my use of neovim and how it would be better if i used an actual IDE.
I told him that ive used IDE's in the past and overall prefer the look and feel of a customised neovim. I then suggested him
to learn vim himself and that he wouldnt regret it, but he declined. Kamil then told me that I should create something easier
for him to use and that could potentially change his use of IDE's.

Upon being issues this challenge I had a few initial questions that I needed answering:

1) What is a text editor and how does it differ from an IDE?
2) How do I make a text editor for kamil
3) How do I make it efficient enough to meet his standards?

To kick things along I began to do research on Text editors and IDE's and
found out that the difference between isnt limited to Operating System platforms
or by how much better one is at a specific task but by the features each can do.
Text Editors, as the name suggest are specifically desinged for manipulting any form of text
that it can open. While an IDE (Integrated Development Environment) is specifically desinged
for software development and comes with a multitude of features that engineers can make use of
to streemline their workflow.

A table of pros and cons:

|               | Pros               | cons                        |
|---------------|--------------------|-----------------------------|
| Text Editor   | Light weight,      | Limited in capability       |
|               | Fast,              |                             |
|               | Resource efficient |                             |
|               | Very Modular       |                             |
|               |                    |                             |
| IDE           | Has everything out | Slow                        |
|               | the box            | Not very Resource efficient |
|               | Modular            | Too many menus              |
|               |                    | Limited in compatability    |



Here are pictures of some text editors and IDE's:

\image html neovimLook.png
\image latex neovimLook.eps "My Neovim" width=10cm


\image html baseVimLook.png
\image latex baseVimLook.eps "My Vim" width=10cm

(annotate hte image)

### End User needs

When talking to Kamil about his needs it was apparant that he wanted something modular
in the sense that it comes with what he needs so its not a hassle to work with and it
works with multiple different file types.

\image html Kamil_info.png
\image latex Kamil_info.eps


Since this is a project that could quickly grow in scale due to all the different parts of handling the editor, text and documents etc.
I am willing to set a few minimum requirements my program can achieve to be usable to Kamil.
The requirements are: the prgram can load and save files, change text and background colour, change font and font size.

To conclude, the objectives of the projet:

We need a program that is not laggy and has minimal delay between text being pressed and it being displayed on the screen.
This can be measured by taking the time taken between a key press and the setString function by SFML.

We also need the ability to load and use multiple fonts and for it to load dynamically and save when we close the program.
This is easier to check since all we need is to check the font save folder and make sure it is there when saved and loaded.

All the dynamic editor features like
zooming in/out; changing the text colour and size
moving around the text and text selection can be checked at runtime and can be benched mark to ensure
it is still decently fast so it is not laggy and meets Kamil's preferences.




- Not laggy
- multple fonts
- import own fonts
- change colour of text
- change size of font
- select and format characters

Extra Features:

- Zoom in / Out
- Scroll up and down
- change background colour
- change text colour
- (potentially) load default colourScheme
- Handle commands such as cmd + s to save etc
- Use arrorw keys and H,J,K,L to move through the text
- Use mouse position to place cursor in text
- select text using mouse

- Save files
- Load files
- create directory tree
- traverse directory
- handled in .txt format

Minimum Requirements:
- Load/Save files
- Change txt and background colours
- Change font and font size

### Limitations

The Limitations of my program are what give it a general architecure to work with.
The Limits include: Time, Programming Language, formating standards, Operating System, Libraries

The project is due on 16th May 2023 leaving me only 1month and 2weeks to get everything together.


When it comes to the Programming Language I wrote my project in C++ (Cpp, Cxx, cc) with access to the C++17 language standard.
I chose this language becauase I am most familiar with it and prefer it over python for larger projects like this.
It is fast, efficient and allows the use of pointers for memory and data management. An example of this can be shown when passing Classes
to other Classes via pointer.

The formatting standard im using is own defined by LLVM in a .clang-format file, it essentially dictates
the formatting of files from how many spaces are used in a tab to length of lines and how many parameters apear on one line.

By having a seperate program keep track of all code formatting and making sure its all standardised it makes the code more modular
and easy to work with since any new programmers will have an easier time understanding code if its all similar.

(include the clang-format file here)

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

The operating System is a default limiter and denotes how everything comes together.
By default I use Linux. This has the benefit of having more support for C++ coding and development in general
with the caveat of programs not being very portable to other devices like windows machines.
This means that I will either need to cross-compile my program or convert Kamil, who is a windows user, over to Linux.

In addition to the operating system, Libraries, specifically graphical Libraries in conjuction with config files can decide wheather a program
is cross-platform or not. Some libraries make use of Os specific functionality and function calls that arent available elsewhere.

The issue for me here is that I use Linux and Kamil uses Windows, so how do I get my program to him on windows?
Well the answer is by choosing libraries that are cross-compatible and using configuration files.

For the Libraries ill be using SFML to handle the events and graphics and fmt for normal printing to standard out. Both are cross platform
and are built using a cmake file.


The cmake file I use to compile and build my project is:
(link to cmake file)


### Design

Throught the creation of the project I utilised an iterative deseign procedure where I would develop a basic version of the code,
test it then improve on it.This form of design procedure requires a very modular and heavily commented code base so we dont get lost when
adding new features and testing and checking old ones.

(show pics of the program before and after for iterative)

My workflow is as:

- Identify feature I want to add
- Write out features it should be able to do
- Create the class in a seperate file around a template SFML project i.e. similar style to main project but not 1-1 copy
- Make sure the class follows DRY (Dont Repeat Yourself)
- Test the code against what-if cases
- Implement the code to the main project and check if it runs
- Test program
- Repeat

(example of written work for TextBox class)


Moreover, when designing the project I made use of OOP and Geneic programming using templates.
Each section of my code is modular so that if someone where to take parts of it like the TextBox class, It would be similar
in style to a normal SFML class with little to no difference.

(TextBox)

#### Design Choices

When developing the project I made a series of design choices that I thought would be best for the project.

In SFML when writing text to a screen it takes a, const sf::String& string, which devolves into std::string types and char[] arrays.
Due to this and a need to be efficient I made the choice to manipulate all text input and output in a dynamic one dimensional character array
(std::string), By doing this any changes that can be made I just need to loop through the string checking each character for what im looking for.
They take up minimal space since it is stored as a single string which is by default 24 bytes.

This also has the added benefit of always knowing its length and size as well as being able to convert into other types when needed.

Furthermore, I also made some optimisation decisions like, passing classes used through by pointer and dynamically allocating them on the heap when created.
I did this because when they are passed through by pointer the program is only accessing one instance of it and not copying the class, manipulating
it and then passing the values back to it when its done like what happens by default when passing a class through parameters. This choice speeds up the program
since it doesnt need to copy and directly access the class.

finish commenting the header file

include teh cmake file
show python thing

