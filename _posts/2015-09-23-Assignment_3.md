---
layout:     assignment
categories: assignment
title:      Assignment 3
subtitle:   Particle Systems
author:     bakercp
date:       2015-09-23 18:00:00
due:        2015-09-30
---

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
