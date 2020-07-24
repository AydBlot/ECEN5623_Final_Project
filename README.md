## ECEN5623_Final_Project

# Overview
For our project we plan to build a simple real-time machine vision synchronome and time-lapse monitoring design of a clock. We will be recording the images from a Logitech XXX webcam connected to a Raspberry PI 3B+ running Raspbian OS. Our program will process captured images of the clock, recognize the change using the V4L2 driver of the second, minute and hour hands, and change the output image to match the clock. First our implementation will utilize an analog clock and operate >1Hz frequency, then expand to a digital clock with a 10Hz frequency. We will also implement an On/Off toggle from the terminal for different features and a pseudo-coloring formula for the saved images. 

# Schedule 
This page is for final project related scheduling tasks

## Status Icons
Status icons used in the status column:

:x: Not started (Issue should include DoD)

:heavy_check_mark: Complete (Issue should contain detail about implementation, DoD in description should be up to date)

:heavy_plus_sign: In Progress (Issue have up to date DoD, should contain detail about status)

:red_circle: Blocked (Issue should include DoD and contain link to blocker)

| Target Milestone | Status            | Owner    | Date Completed |
| ---------------- | -------------     | -------- | -------------- |
| Submit Project Proposal | :heavy_check_mark:| Ayden & Joey | 07/24/2020 |
| Initialize git Repo     | :heavy_check_mark:| Ayden & Joey | 07/24/2020 |                
| Syslogging              | :heavy_plus_sign: | Ayden        | 07/24/2020 |
| Requirement 1           | :heavy_plus_sign: | Ayden        |            |
| Requirement 2           | :x:|              | Joey         |            |
| Calculation of jitter   | :x:|              | Ayden        |            |
| Calculation of drift    | :x:|              | Ayden        |            |
| Circular Buffer         | :x:|              | Joey         |            |
| TBD                     | :x:|              |              |            |
| TBD                     | :x:|              |              |            |
