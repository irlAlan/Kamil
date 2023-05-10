# Kamil Editor

A Text Editor for kamil

## Analysis

### Background and Identifying the problem

The Project I will be developing will be in answer to the challenge set out by
the end user and friend of mine, Kamil. He challenged me to make a light weight
editor that he can use in his day to day life and when doing python projects.

This leads me on to identifying the base problems at hand and summing them into
3 questions:

    1) What is a text editor and how does it differ from an IDE?
    2) How do I make a text editor or IDE for kamil
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
|               | Resource efficient,|                             |
|               | Very Modular       |                             |
|               |                    |                             |
| IDE           | Has everything out | Slow                        |
|               | the box,           | Not very Resource efficient |
|               | Modular            |                             |
|               |                    |                             |



Here are pictures of some text editors and IDE's:

\image html neovimLook.png
\image latex neovimLook.eps


\image html baseVimLook.png
\image latex baseVimLook.eps



### End User needs

When talking to Kamil about his needs it was apparant that he wanted something modular
in the sense that it comes with what he needs so its not a hassle to work with and it
works with multiple different file types.

\image html Kamil_info.png
\image latex Kamil_info.eps


To conclude the User needs:
Kamil would like:

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

## Structure

Kamil.cpp - Main window (text window is used)
-Window (has the text box window and the line number)
-inupts (handles events like keyboard clicks and mouse events, state changes happen here)
-textdoc (handles the file like saving it)

window
    - Main Window
Editor
    - Where text is handled (same size as window)
    - Rectangle on left for margin
    - font
    - line info
    - drawn on main window
Input
    - mouse and keyboard window
TextDocument

-- Disliked buttons no button in mine
-- Dislike having to hunt for library to get stuff done
-- doesnt like writing code - no response
-- maybe, stong yes
