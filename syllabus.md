---
layout: page
title:  Syllabus
---

## Interactive Art / Creative Code, ARTTECH 3135

Semester, Year
:   Fall, 2016

Meeting Times
:   Wednesday 9am-4pm

Meeting Location
:   MacLean 401

Instructor
:   [Christopher Baker](http://christopherbaker.net)

Class Forum
:   [https://ats.community/c/courses/arttech-3135](https://ats.community/c/courses/arttech-3135)

Class Website
:   [http://saic-ats.github.io/ARTTECH-3135/](http://saic-ats.github.io/ARTTECH-3135/)

Code Examples
:   [https://github.com/SAIC-ATS/ARTTECH-3135/](https://github.com/SAIC-ATS/ARTTECH-3135/)


TA
:   [Billie Pate](http://www.billiepate.com/)

--------------------------------------------------------------------------------

### Instructor Bio
[Christopher Baker](http://christopherbaker.net) is an artist whose work engages the rich collection of social, technological and ideological networks present in the urban landscape. He creates artifacts and situations that reveal and generate relationships within and between these networks.  Christopher’s work has been presented worldwide and he contributes to the open source community at [http://github.com/bakercp](http://github.com/bakercp).

### TA Bio
[Billie Pate](http://www.billiepate.com/) is an LA based experimental media artist. She creates technology-driven visual art.

--------------------------------------------------------------------------------

### Course Description
This studio course investigates the creative possibilities in programming, from interactivity to information visualization. Students explore interactive narratives and games, software art, simulations and emergent behaviors, and other code-based forms. Lectures, discussions, and demonstrations provide a conceptual, aesthetic and technical foundation in programming as a creative practice.

### Course Goals

__Key goals include:__

- Working knowledge of contemporary open source coding tools.
- Working knowledge of contemporary open hardware tools
- Working knowledge of contemporary artists and groups that shape the fields of interactive art and creative code.
- Working knowledge of intermediate linux/unix OS features (scripting, terminal, automation, etc)

### Course Values
- Sharing / Open
    - Documentation
    - [DIWO](http://furtherfield.org/projects/diwo-do-it-others-resource)
    - Publish
    - Cult of Done (http://www.brepettis.com/blog/2009/3/3/the-cult-of-done-manifesto.html)

### Methodology
Students will engage in individual in-lab and home assignments, class presentations, lectures, discussions, assigned readings, group and individual projects and desk critiques.  Visiting artists / faculty may enhance the experience and offer additional perspectives.

### Assignments
The course may include workshops and several projects, relevant technical and theoretical reading, written online responses, technical research and outings.

### Class Text

- [ofBook](https://github.com/openframeworks/ofBook)

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
Students wait-listed for classes will be admitted on a space available basis determined by instructors’ discretion (in consultation with the department chair).

### Grading Procedure/Criteria
- Grades are credit / no-credit for this course. Credit is based on several factors: 30% participation (discussions, critiques, etc), 70% projects / assignments.
- Incomplete grades will not be offered.

### Writing Assistance
[Writing Center](http://www.saic.edu/webspaces/portal/advising/write\_center.html)

### Special Needs
[Disability and Learning Resource Center](http://www.saic.edu/lifeatsaic/wellnesscenter/disabilityandlearningresourcecenter/)

### Course Schedule

_(subject to change based on incoming skills and experience)_

#### Week 1
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
  - Patch Based / Visual
    - [Max](https://cycling74.com/products/max/)
    - [Grasshopper](http://www.grasshopper3d.com/)
  - Procedural
    - [Processing](https://processing.org/)
      - Getting started: http://hello.processing.org/
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
    - Code Comments (e.g. why? [this](http://qz.com/726338/the-code-that-took-america-to-the-moon-was-just-published-to-github-and-its-like-a-1960s-time-capsule/))
    - What is compiling?
    - Hello World?!
    - Framework
    - Shapes
    - Colors
    - Interactivity
- Common Errors
  - What is your compiler target?
  - Did you accidentally add a break point?
  - How do I start over?
  - What about variable "scope"?
  - Why won't my if-statement do what I wanted it to?

#### Week 2

- Discussion
    - Discuss "What is Code"
    - Week 1 artists.

- Drawing
  - `ofPath`
  - `ofPolyline`
  - `ofSetColor`
  - `ofFill`
  - `ofDraw*`
  - for loops
  - if statements

- Workshop: Introduction to the Terminal.
    - [Terminal Intro](https://github.com/olab-io/microWorkshops/blob/master/Terminal_Intro/Terminal_Intro.md)
- Bookkeeping / Workshop
    - [Discourse](http://discourse.org)
    - [http://talk.olab.io](http://talk.olab.io) Review
    - Terminal Intro
        - [Terminal](https://github.com/olab-io/microWorkshops/blob/master/Terminal_Intro/Terminal_Intro.md)
    - How to share and stay sane with git / github.
        - [Git Intro](https://github.com/olab-io/microWorkshops/blob/master/Git_Intro/Git_Intro.md)
        - [ofBook](https://github.com/openframeworks/ofBook/blob/master/chapters/version_control_with_git/chapter.md)

#### Week 3
- Introduction to C++
- Introduction to the ofSketch IDE.
    - [https://github.com/olab-io/](https://github.com/olab-io/)
    - Program flow and state, Pong Example

#### Week 4
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
    - Structured -> top down approach
    - OOP -> create models problem
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
        - OOP isn't the solution to everything.  Most advanced programs are a combination of structured and object oriented approaches.
- Particle System Examples
    - Replace ball variables with a Ball class.
    - Replace x / y / z variables with `ofPoint` (which is an alias for `ofVec3f` or in 0.10.0+ `glm::vec3`).
        - `ofPoint` is a "vector" of values, x, y, z and vector math can be performed in one line.
        - `ofPoint` is a class!
    - Particle systems in 3D!
- Arrays are collections of variables.
    - In C++ we usually use a `std::vector` to hold a collection of variables.
    - We must define the contents of the `std::vector` using a template argument like `std::vector<int>` for a collection of integers.

#### Week 5
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

#### Week 6
- Brief Intro to XCode / IDEs
- Pixels
- Textures
- Meshes
- Mid Term Project Proposals Due + Discussion

#### Week 7
- Intro to computer vision / Machine Learning.
- Optional IO Lab Training  
- Mid Term Project Work

#### Week 9
- Computer Vision / Machine Learning Continued.
- Mid Term Project Work

#### Week 10
- Mid Term Project Work

#### Week 11
- Mid Term Project Critiques

#### Week 13
- Final Project Work

#### Week 14
- Final Project Work

#### Week 15
- Final Project Critiques
