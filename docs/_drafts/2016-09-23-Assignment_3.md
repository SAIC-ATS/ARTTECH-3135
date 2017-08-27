---
layout:     assignment
categories: assignment
title:      Assignment 3
subtitle:   Particle Systems
author:     bakercp
date:       2016-09-23 18:00:00
due:        2016-09-30
---


- Read: [Computer Vision for Artists And Designers](http://www.flong.com/texts/essays/essay_cvad/).

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


1. Bookkeeping!
    - Make sure you can access the class forum here: http://talk.olab.io/c/saic/ats-3135-interactive-art.
    - Make sure you have cleaned up your previous repository and joined the new private repository.  If you can't see [this](https://github.com/SAIC/ARTTECH-3135-Fall-2016-Private), then go [here](http://talk.olab.io/t/class-3-assignment-part-1/907) for instructions.



1. Bookkeeping!
    - Upload you assignment 2 part 3 (Pong Mod) to our new private gihtub repository.
    - For specific instructions, see the video linked on forum [here](http://talk.olab.io/t/assignment-2-github-screencast/).
2. Review Object Oriented Programming
    - If you haven't read the OOP chapter from Assignment 1, do it.
    - Prepare for next week.  We will be talking about:
        - Classes and Objects - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm) is recommended.
        - Inheritance - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm) is recommended.
        - Function Overloading - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) is recommended.
        - Polymorphism - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm) is recommended.
        - Abstraction - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_data_abstraction.htm) is recommended.
        - Encapsulation - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_data_encapsulation.htm) is recommended.
        - Interfaces - [this tutorial](http://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm) is recommended.
    - If you'd prefer a video tutorial over text tutorials, I'd recommend the Lynda.com tutorials [here](http://www.lynda.com/C-tutorials/C-Essential-Training/182674-2.html), specifically section 4 _Classes and Objects_.  In fact, I'd highly recommend the whole video course if you're feeling a little behind or need a bigger picture.

3. Extend the 2D or 3D Particle System created in class.
    - Modify the `BaseParticle` to ...
        - ... have different drawing output based on variables such as velocity or age.
        - ... have different size or rotation based on the particle's age.
        - (optional) ... are represented with as text or video.
    - When your mouse is pressed, the particles should be repelled from it.
    - When your mouse is not pressed, the particles should behave normally.
    - When your mouse is pressed and the 'p' key is pressed, the particles should "pulse" being attracted and repelled around the mouse.
        - (consider connecting the mouse's acceleration to a sin function).
    - (advanced) Implement a Boids flocking algorithm in 2D or 3D (you might start by translating [this](https://processing.org/examples/flocking.html) Processing example. `PVector` is very similar to our `ofPoint`).
    - or another demo that proves you understand the material and are thinking creatively ...

4. Submit the results of step 3 to our new private github repository.  Follow the same instructions posted in the video, but this time place it in the `Assignment_3` folder.  Please do this before class starts.

3. Extend the Pong game created in class.  If you have trouble getting started, let us know on the forum!  Work together with others.  You can find starting code here.  Your job is to extend the game in a way that you will find interesting and may contribute to research for your future project.  Extend it in 3 or more of the following ways:
    - Video / Image:
        - When the game is complete, play a video in the background of the pong field (see `ofVideoPlayer`).
        - Instead of drawing the pong ball and paddles as white rectangles, use images or videos in their place (see `ofImage`).
    - Sound (see `ofSoundPlayer`)
        - Add a sound track.
        - Make the sound track speed up or change with every point scored.
        - Add sound effects when the ball collides with the wall or the paddle.
    - Typography
        - Create a scoreboard that uses a True Type Fonts, rather than a bitmap string (see `ofTrueTypeFont`).
    - Artificial Intelligence
        - Implement a computer controlled paddle.
            - Create a paddle that never misses.  
            - Create a paddle that always misses.
            - Create a paddle that misses 50% of the time.
            - Create a paddle that gets harder with every point.
        - Implement a ball that exhibits more complex movements.
            - Implement a ball with "a mind of its own".
            - Implement a ball that changes size depending on the score.
    - Playing field
        - Implement "obstacles" on the field that the ball can bounce off of.
        - Implement "spin", allowing the player to slice with the paddle and add Y velocity to the ball.
    - Game Play
        - Make a 4 player version of pong.  Each player defends on wall.
        - Make a "circular" version of pong.
    - Interface
        - Use an Arduino + two potentiometers and two buttons to control the paddles (see `ofSerial` or for communication with the arduino).
        - Control the paddle with the mouse.

4. Submit the results of step 3 to our new private github repository (this is how I'll know if you did it and how your friends will benefit from seeing everyone's code).  We will go over how I want you to do this in class.

4. Project Proposal
    - Post four ideas for _Project 0: A Clock With Benefits_ on a blog post on our class.
    - To make a blog post, use the `2016-09-04-HelloWorld.md` as a template.  Duplicate the file, change the name and the metadata to match your project and `git add`, `git commit`, `git push`, then pull request.

