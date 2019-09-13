---
layout: page
title:  Syllabus
---

## Interactive Art / Creative Code, ARTTECH 3135 / 5135

Semester, Year
:   Fall, 2019

Meeting Times
:   (-001) Fridays 9am-4pm

Meeting Location
:   MacLean 401

Instructor
:   [Christopher Baker](https://new.christopherbaker.net)

Teaching Assistant(s)
:   (-001) Kate Smith

Class Forum
:   [{{ site.forum}}]({{site.forum}})

Class Website
:   [{{ site.url }}]({{ site.url }})

Code Examples
:   [{{ site.github }}]({{ site.github }})

--------------------------------------------------------------------------------

### Instructor Bio

[Christopher Baker](https://new.christopherbaker.net) is an artist whose work engages the rich collection of social, technological and ideological networks present in the urban landscape. He creates artifacts and situations that reveal and generate relationships within and between these networks.  Christopher’s work has been presented worldwide and he contributes to the open source community at [https://github.com/bakercp](https://github.com/bakercp).

--------------------------------------------------------------------------------

### Course Description

This studio course investigates the creative possibilities in programming, from interactivity to information visualization. Students explore interactive narratives and games, software art, simulations and emergent behaviors, and other code-based forms. Lectures, discussions, and demonstrations provide a conceptual, aesthetic and technical foundation in programming as a creative practice.

### Course Goals

__Key goals include:__

- Intermediate working knowledge of creative coding tools and techniques.
- Working knowledge of the landscape of contemporary open source coding tools.
- Working knowledge of coding tools such as Git, Xcode, Terminal, etc.
- Working knowledge of contemporary artists and groups that shape the fields of interactive art and creative code.

### Course Values

- Sharing / Open
  - Documentation
  - [DIWO](http://furtherfield.org/projects/diwo-do-it-others-resource)
  - Publish
  - [Cult of Done Manifesto](https://medium.com/@bre/the-cult-of-done-manifesto-724ca1c2ff13)

### Methodology

Students will engage in individual in-lab and home assignments, class presentations, lectures, discussions, assigned readings, group and individual projects and desk critiques.  Visiting artists / faculty may enhance the experience and offer additional perspectives.

### Assignments

The course may include workshops and several projects, relevant technical and theoretical reading, written online responses, technical research and outings.

### Class Text

- [ofBook](http://openframeworks.cc/ofBook/chapters/foreword.html)

### Reading and other Resources

Posted on the course website.

### Materials

Provided by the student as needed.

### Attendance

1. Students are best served by attending all classes.
2. Missing three classes will result in a class failure.  This is strictly enforced.
3. Six or more unexcused late arrivals or early departures will result in class failure.

_Tip: If you are going to be absent, late to class, or need to depart early, please contact me BEFORE class starts.  This is so I can make sure you have what you need to succeed!_

### Wait Lists

Students wait-listed for classes will be admitted on a space available basis determined by instructor’s discretion (in consultation with the department chair).

### Grading Procedure/Criteria

- Grades are credit / no-credit for this course. Credit is based on several factors: 30% participation (discussions, critiques, etc), 70% projects / assignments.
- All assignments must be completed and submitted as instructed.
- Incomplete grades will not be offered.

### Writing Assistance

[Writing Center](https://www.saic.edu/academics/writing-center)

### Special Needs

[Disability and Learning Resource Center](https://www.saic.edu/life-at-saic/wellness-center/disability)

### Course Schedule

_(subject to change based on incoming skills and experience)_

#### Session 00

- Before we get Started ...
  - Begin download Xcode 8 from the App Store (will require OS 10.12+)

- Introduction to course / syllabus.
- Introduction to each other.
- Interesting Recent Creative Coding Work
  - [Claire Hentschker](http://www.clairesophie.com/)
  - [TerraPattern](http://www.terrapattern.com/)
  - [Alt-AI exhibition](http://alt-ai.net/#exhibition)
  - [w/ openFrameworks](http://openframeworks.cc/gallery/)
  - [w/ Processing](https://processing.org/exhibition/)
  - Online
    - [Creative Applications](http://www.creativeapplications.net/)
- Survey of Creative Coding Platforms.
  - Visual Programming Languages
    - [Max](https://cycling74.com/products/max/)
    - [Grasshopper](http://www.grasshopper3d.com/)
    - [Touch Designer](https://www.derivative.ca)
  - Non-visual Programming Language
    - [Processing](https://processing.org/)
      - Getting started: [http://hello.processing.org/](http://hello.processing.org/)
      - Variations
        - Javascript: [https://p5js.org/](https://p5js.org/)
        - Android: [http://android.processing.org/](http://android.processing.org/)
        - Python: [http://py.processing.org/](http://py.processing.org/)
    - [libCinder](https://libcinder.org/)
    - [openFrameworks](http://openFrameworks.cc)
  - Hybrid
    - [Unity3d](https://unity3d.com/)
    - [Unreal Engine](https://www.unrealengine.com)
- So what are we going to focus on?
  - Software
    - [openFrameworks](http://openframeworks.cc/) (C/C++)
- Getting Started
  - C++
    - Brief Intro to Xcode / IDEs
    - Code Comments (e.g. why? [this](http://qz.com/726338/the-code-that-took-america-to-the-moon-was-just-published-to-github-and-its-like-a-1960s-time-capsule/))
    - What is compiling?
    - Hello World! in C++
    - What is a framework?
  - openFrameworks
    - Installing openFrameworks
      - Where does the folder go?
      - Where do the projects go?
      - What is in the openFrameworks folder?
    - Project Generator
    - Basic Program Structure
    - "Painting" metaphor
      - Drawing "accumulates"
      - Brush color doesn't change unless you tell it to.
    - Drawing Shapes
      - `ofDrawRectangle(...)`
      - `ofDrawLine(...)`
    - Colors
      - `ofSetColor(...)`
    - Fill vs. Stroke
      - `ofSetFill()` and `ofNoFill()`
    - Interactivity
      - `ofGetMouseX()` and `ofGetMouseY()`
  - Common Errors
    - What is your compiler target?
    - Did you accidentally add a break point?
    - How do I start over?
      - Project Generator
    - What about variable "scope"?
    - Why won't my if-statement do what I want it to?

#### Session 01

- Review Assignment 00
  - Questions from Assignment 00?

- Discussion
  - Discuss "What is Code"
  - Week 1 artists.

- C++
  - Variables and Types
    - Identifiers, reserved keywords
    - Saving information!
    - Foundational / POD
      - `bool`
      - `int`
      - `float`
    - Other
      - `std::string`
      - `auto`
  - Operators
    - Math `+`, `-`, `*`, `/`, `%`
    - Assignment `=` (tell) vs. `==` (ask)
    - Order Operation
    - Prioritize with Parenthesis!
  - Program Flow
    - Typically execute statements, top to bottom, left to right.
    - Single statements vs. compound statements `{ ... }`
    - Flow Control
      - Selection
        - `if` / `else if` / `else`
        - `switch`
      - Iteration / Repetition
        - `while (...) { ... };`
          - Iterate while a condition is true.
        - `do { ... } while (...);`
          - Evaluate condition after contents of loop are executed.
        - `for (...) { ... };`
          - Iterate a fixed number of times.
        - Range `for` loop
      - Jumping
        - `break`
        - `continue`
        - `goto` (avoid)
    - Output
      - Standard output streams
        - `std::cout`
        - `std::cerr`
      - oF output
        - `ofLogXXX()`
          - Finer-grained control of output.
        - `ofSetLogLevel(...)`

- openFrameworks
  - `ofSetColor`
  - `ofFill`
  - `ofDraw*`

#### Session 02

- Review Assignment 01
  - Show & Tell
  - What was hard? What was easy?
- C++ Syntax
  - Reminder that tutorials are available ...
    - [https://www.lynda.com/C-tutorials/Up-Running-C/167922-2.html](https://www.lynda.com/C-tutorials/Up-Running-C/167922-2.html)
    - [https://www.lynda.com/C-tutorials/C-Essential-Training/182674-2.html](https://www.lynda.com/C-tutorials/C-Essential-Training/182674-2.html)
  - `if` statements
  - `for` loops
  - `%` modulo operator

- openFrameworks
  - `ofSetWindowShape(...)`
  - Coordinate System Review
  - `ofSetBackgroundAuto(...)`
  - `ofBackground(...)`
  - Fading Background
    - `ofDrawRectangle(...)`
  - `ofRandom(...)`
  - `ofGetMousePressed(...)`
  - `ofGetKeyPressed(...)`
  - `ofPushMatrix()`
  - `ofPopMatrix()`

- `ofPixels`
  - Quick review of binary numbers ...
  - How are pixels / color represented?
  - Looping
  - Manually setting colors.
  - Saving and loading images.
    - Raw vs. encoded.
    - Importance of encoding for "glitch".

#### Session 03

- Simple State Machines
- Traffic Lights
- Review Pong Mods
- Review helper functions and classes
  - `ofLerp`, `ofMap`, and `ofNormalize` all help us scale linearly scale numbers.
  - `ofSoundPlayer` allows us to play sounds.
  - `ofVideoPlayer` allows us to play video.
  - `ofTrueTypeFont` allows us to do more sophisticated typography.
- How to Upload Pong Examples to Private Repo
- Object Oriented Programming.  
- OOP vs Structured Programming
  - C++ is often described as C + object oriented code.
  - Structured → top down approach
  - OOP → create models problem
  - Why OOP?
    - Duplicate code can be confusing and lead to bug if it is modified in the future. You will always forget something!
    - Modeling the world using objects can often be more intuitive, better differentiating between form and function.
  - Classes
    - Classes are user defined data structures.
    - Classes are reusable between programs.
    - Classes are a way to aggregate or model form (attributes) and function (methods) into reusable units.
    - Classes are often used to easily represent multiples of a complex object.
    - Classes are "extensible" through inheritance.
    - An class "instance" is an independent "instantiated" variable form of a class.
    - In the same way that an `int` is a variable type and it is instantiated by calling `int i = 0;`, a class variable type like `Ball ball1;`  Now the `ball1` variable is its own "instance" that can be manipulated.  Other "instances" e.g. `Ball ball2;` will have the same capabilities as `ball1`, but it will behave independently by default.
    - Example: Writing a class definition for a ball.
      - What are the "attributes" (that can be represented as variables) of a ball?
        - Position
        - Velocity
        - Color
        - ...
      - What are the "actions" associated with a human?
        - update
        - draw
    - Create default instances like you would with other variables.
    - Create custom instances by defining custom constructors.
    - Dot operator give you access to "member" attributes within a class.
  - Warnings:
    - Don't try to model the world!
    - Design your classes and represent only salient attributes and actions that you need for your project.
    - OOP isn't the solution to everything.  Most advanced programs are a combination of functional and object oriented approaches.
- Particle System Examples
  - Replace ball variables with a Ball class.
  - Replace x / y / z variables with `ofPoint` (which is an alias for `ofVec3f` or in 0.10.0+ `glm::vec3`).
    - `ofPoint` is a "vector" of values, x, y, z and vector math can be performed in one line.
    - `ofPoint` is a class!
  - Particle systems in 3D!
- Arrays are collections of variables.
  - In C++ we usually use a `std::vector` to hold a collection of variables.
  - We must define the contents of the `std::vector` using a template argument like `std::vector<int>` for a collection of integers.

#### Session 04

- Semantics
  - Difference between Functions and Methods / Member Functions.
  - Difference between parameters and arguments.
- OOP (continued)
  - Review Classes
    - Difference between a `class` (a user defined type) and an `object` (instance of a class).
    - Abstraction
      - Why abstraction?
    - Encapsulation
      - Why encapsulation?
    - "Dot" syntax to access member functions / member variables.
  - Function Overloading
  - Operator Overloading
  - Polymorphism "having many forms"
- Pointers, memory

#### Session 05

- Pixels
- Textures
- Meshes
- Mid Term Project Proposals Due + Discussion

#### Session 06

- Intro to computer vision / Machine Learning.
- Optional IO Lab Training  
- Mid Term Project Work

#### Session 07

- Computer Vision / Machine Learning Continued.
- Mid Term Project Work

#### Session 08

- Mid Term Project Work

#### Session 09

- Mid Term Project Work

#### Session 10

- Mid Term Project Critiques

#### Session 11

- Final Project Work

#### Session 13

- Final Project Critiques
