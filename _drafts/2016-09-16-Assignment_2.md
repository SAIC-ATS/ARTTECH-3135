---
layout:     assignment
categories: assignment
title:      Assignment 2
subtitle:   Computer Vision + Pong
author:     bakercp
date:       2016-09-16 18:00:00
due:        2016-09-23
---

1. Bookkeeping!
    - Make sure you can access the class forum here: http://talk.olab.io/c/saic/ats-3135-interactive-art.
    - Make sure you have cleaned up your previous repository and joined the new private repository.  If you can't see [this](https://github.com/SAIC/ARTTECH-3135-Fall-2016-Private), then go [here](http://talk.olab.io/t/class-3-assignment-part-1/907) for instructions.

2. Read!
    - Read: [Computer Vision for Artists And Designers](http://www.flong.com/texts/essays/essay_cvad/).

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

