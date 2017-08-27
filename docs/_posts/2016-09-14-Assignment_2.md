---
layout:     assignment
categories: assignment
title:      Assignment 2
subtitle:   Transformations, Looping, and Maths!
author:     bakercp
date:       2016-09-14 00:00:00
due:        2016-09-21
---

1. Read!
  - Read: ofBook [OOps!](http://openframeworks.cc/ofBook/chapters/OOPs!.html)
    - Why? _This gives an overview of the important concept of Object Oriented Programming. We'll be covering this in class._

2. Coding!
 - Create an animated "scene" that runs on its own.
 - You must must keep your scene "under control", meaning that I want you to understand how the different behaviors are emerging.  This may mean that you have to keep your scene simple!
 - You must "energize" the scene using _periodic signals_. A "periodic signal" is a variable that changes over time (usually) in a predictable repeating way (see your `openFrameowrks/examples/math/periodicSignalsExample` folder for examples).
 - In addition to periodic signals, you must also use Perlin Noise (`ofNoise` or `ofSignedNoise`).  (see your `openFrameowrks/examples/math/noise1d...` folders for examples).  Learn more about Perlin Noise [here](https://www.youtube.com/watch?v=Qf4dIN99e2w).  
     - Note that the openFrameworks equivalent of P5.js' `random()` is `ofRandom()` and the equivalent of `noise()` is `ofNoise()` (or similarly `ofSignedNoise`).
  - Use `ofImage` to include images.  Take a look at the Graphics Examples for use.
  - (optional) use `ofTrueTypeFont` to animate Typography.
  - Consider using [this example](https://github.com/SAIC-ATS/ARTTECH-3135/tree/master/Week_2/Flailer) as a starting point.
