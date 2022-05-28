# FileWordFinder

## What is here?

Here is my project which helps to find word in txt files and objects where this word is found in xml files. All you need to do is specify the path to the directory with the files and\or word to find.

## Source of ideas

I was training in OOP and needed an idea for some project that might be useful. And to make it more interesting, I added one condition - use all pillars of the OOP.

So, while I was studying OOP, I needed to find one word in a text file that was among a thousand others and I was too lazy to search for it. From that moment I had an idea for a project that would allow me to search conveniently. And after that, i decided to add functionality in searching objects in xml files. 

## Functionality

So, to work with this programm you need:
1. Choose file type to work with (txt or xml)
2. Choose working option (with subdirectories or without it)
3. Enter a word

That's all. Working with TXT, we will get a list showing 
- which file the word is in
- the path to it
- the line itself 
- line number
  
Working with XML we will get other list showing 
- which file the word is in
- the path to it
- object path to the word
- word`s object
- the line itself
- line number

To get more information, go to the `examples` dir.

## Technical part

There is a preconfigured console application and you can use it, but if you want to create your own, there is also a preconfigured library(lib_src/lib_include) for that. Part for library compiling marked in CMakeLists.txt with relevant commentary. 

- Minimum cmake version: 3.13.4
- Minimum C++ version: 17 

To build ready app:
```
mkdir build
cd build
cmake ..
cmake --build . --config Release (or Debug)
```
## Xml file requirements

All text need to store in one line. Here is example
```
///////// correct /////////
<Book>
    <Name>TestBook</Name>
    <Created>2000-01-01</Created>
</Book>

///////// incorrect /////////
<Book>
    <Name>
        TestBook
    </Name>
    <Created>
        2000-01-01
    </Created>
</Book>
```

I don't think the second is common, but sometimes you need to move very_long_sentence to next line in order to make it readable. So, algorithm will not show correct result in case.