---
layout:     assignment
categories: assignment
title:      Assignment 1
subtitle:   Drawing!
author:     bakercp
date:       2016-09-06 18:00:00
due:        2016-09-14
---

1. Bookkeeping!
    - Make sure you can access the class forum [here](https://ats.community/c/courses/arttech-3135). If you can't, talk to me.  From this week forward, all class announcements will be posted on our private forum.  You are responsible for making sure that you get the announcements, so make sure you've got everything configured correctly.

2. Read!
    - Read: ofBook: [Graphics](http://openframeworks.cc/ofBook/chapters/intro_to_graphics.html)
        - Why? _You have to know how to draw!_
        - Become familiar with:
          - `ofPath`
            - some [documentation](http://openframeworks.cc/documentation/graphics/ofPath/)
            - an [example](https://github.com/openframeworks/openFrameworks/tree/master/examples/graphics/polygonExample)

3. Learn about "Git" and "Github"
  - Why? _Git is a tool that you'll use all the time in this class and in your future lives as Creative Coders. It's by far the most popular way to share and manage code and should become a bit like breathing as you develop code._
    - If you learn by **reading**, consider this: [Version Control with Git](http://openframeworks.cc/ofBook/chapters/version_control_with_git.html)
    - If you learn best by **watching videos**, check out [Up and Running with Git and GitHub](https://www.lynda.com/Git-tutorials/Up-Running-Git-GitHub/409275-2.html) (about 1.25 hours).
      - _Remember that you have "free" access to Lynda.com through SAIC. Go [here](http://www.saic.edu/academics/computing/lyndaonlinesoftwaretraining/) to log in._

4. Review!
    - Check out my [homework 0 solutions](https://github.com/SAIC-ATS/ARTTECH-3135/tree/master/Assignment_0).
      - _Remember, these are just a few different ways.  I'm assuming you also know that as artists, using "brute-force" (i.e. manually entering each and every line) was also a valid option._
    - Do you know what the following terms mean?
      - _Iterating with a for-loop_ ([hint](https://www.lynda.com/C-tutorials/Iterating/182674/366536-4.html))
      - _Range-based for-loop_ ([hint](https://www.lynda.com/C-tutorials/Using-range-based-loop/182674/366537-4.html))
      - _Conditional statements `if`, `then`, `else`, `else if`_ ([hint](https://www.lynda.com/C-tutorials/Conditionals/182674/366533-4.html))
      - _Variable "scope"_ ([hint](https://www.youtube.com/watch?v=qz_W4wlP-cg) and [hint](http://www.tutorialspoint.com/cplusplus/cpp_variable_scope.htm))

5. Create an Interactive Experimental Drawing Application
    - An experimental drawing application **should** ...
      - ... allow users / participants to "draw" using the mouse.
      - ... allow users / participants to affect the "drawing" using the keyboard.
      - ... allow the user to `clear()` the screen using a keyboard command.
        - e.g. For a vector called `std::vector<ofPoint> points;` consider clearing it using `points.clear();`.
      - Explore color, opacity, lines, shapes.
    - An experimental drawing application **should not** ...
      - ... attempt to do all of the things that existing drawing applications (e.g. Photoshop) already do.
      - ... make excessive use of `ofRandom` ... (ok, that's just my preference, it's not required).
      - ... take more than a few hours to build.
    - Take several screen shots of your best "drawing" and submit them with your code (**we will talk about how to do this next week**. Hold on to your code and screenshots for now).