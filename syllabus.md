---
layout: page
title:  Syllabus
---

## Interactive Art / Creative Code, ARTTECH 3135

Semester, Year
:   Fall, 2015

Meeting Times
:   Wednesday 9am-4pm

Meeting Location
:   MacLean 416

Instructor
:   [Christopher Baker](http://christopherbaker.net)

Class Forum
:   [http://talk.olab.io/c/saic/ats-3135-interactive-art](http://talk.olab.io/c/saic/ats-3135-interactive-art)

Class Website
:   [http://bakercp.github.io/InteractiveArt/](http://bakercp.github.io/InteractiveArt/)

TA
:   TBA

--------------------------------------------------------------------------------

### Instructor Bio
[Christopher Baker](http://christopherbaker.net) is an artist whose work engages the rich collection of social, technological and ideological networks present in the urban landscape. He creates artifacts and situations that reveal and generate relationships within and between these networks.  Christopher’s work has been presented worldwide and he contributes to the open source community at [http://github.com/bakercp](http://github.com/bakercp).

--------------------------------------------------------------------------------

### Course Description
This studio course investigates the creative possibilities in programming, from interactivity to information visualization. Students explore interactive narratives and games, software art, simulations and emergent behaviors, and other code-based forms. Lectures, discussions, and demonstrations provide a conceptual, aesthetic and technical foundation in programming as a creative practice.

### Course Goals

-foundation in creative coding.
-projects spanning conceptual and creative ideas.
-interfacing of both hardware and software in creative practice.

__Key goals include:__

- Working knowledge of contemporary open source coding tools.
- Working knowledge of contemporary open hardware tools
- Working knowledge of contemporary artists and groups that shape the fields of interactive art and creative code.
- Working knowledge of intermediate linux/unix OS features (scripting, terminal, automation, etc)

### Course Values
- Sharing / Open
    - Documentation
    - DIWO
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
- Survey of Creative Coding Platforms.
- So what are we going to focus on?
    - Software
        - [openFrameworks](http://openframeworks.cc/) using [ofSketch](https://github.com/olab-io/ofSketch) (C/C++)

- Workshop: Introduction to the Terminal.
    - https://github.com/olab-io/microWorkshops/blob/master/Terminal_Intro/Terminal_Intro.md

- Basic ofSketch Intro
    - Framework
    - Shapes
    - Colors
    - Interactivity

#### Week 2

- Discussion
    - Discuss "What is Code"
    - Week 1 artists.

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
    - [https://github.com/openframeworks/ofBook/blob/master/chapters/ofSketch/chapter.md](https://github.com/openframeworks/ofBook/blob/master/chapters/ofSketch/chapter.md)

    - Program flow and state, Pong Example

#### Week 4
- Review Pong Mods
- Review helper functions and classes
    - ofLerp, ofMap, and ofNormalize all help us scale linearly scale numbers.
    - ofSoundPlayer allows us to play sounds.
    - ofVideoPlayer allows us to play video.
    - ofTrueTypeFont allows us to do more sophisticated typography.
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
    - Replace x / y / z variables with ofPoint (which is an alias for ofVec3f).
        - ofPoint is a "vector" of values, x, y, z and vector math can be performed in one line.
        - ofPoint is a class!
    - Particle systems in 3D!
- Arrays are collections of variables.
    - In C++ we usually use a `std::vector` to hold a collection of variables.
    - We must define the contents of the `std::vector` using a template argument like `std::vector<int>` for a collection of integers.

#### Week 5
- OOP continued
    - Inheritance
- Pointers, memory
- Pixels
- Textures
- Intro to computer vision.

#### Week 6
- Intro to XCode / IDEs
- Project 2 Proposals

#### Week 7
- "Game States"
- Project 2 Work

#### Week 9
- Project 2 Critiques

#### Week 10
- Project 3 Proposal
- Computer Vision - Teaching Computers to See
- Project 3 Work

#### Week 11
- Computer Vision - Lets get serious.
- Project 3 Work

#### Week 13
- Advanced Topics and Integration.
- Project 3 Work

#### Week 14
- Advanced Topics and Integration (continued)
- Project 3 Work

#### Week 15
- Project 3 Critiques
