## ECEN5623_Final_Project

# Overview
For our project we plan to build a simple real-time machine vision synchronome and time-lapse monitoring design of a clock. We will be recording the images from a Logitech XXX webcam connected to a Raspberry PI 3B+ running Raspbian OS. Our program will process captured images of the clock, recognize the change using the V4L2 driver of the second, minute and hour hands, and change the output image to match the clock. First our implementation will utilize an analog clock and operate >1Hz frequency, then expand to a digital clock with a 10Hz frequency. We will also implement an On/Off toggle from the terminal for different features and a pseudo-coloring formula for the saved images. 

# Schedule 
This page is for final project related scheduling tasks

## Status Icons
Status icons used in the status column:

:x: Not started 

:heavy_check_mark: Complete 

:heavy_plus_sign: In Progress 

:red_circle: Blocked 

| Target Milestone | Status            | Owner    | Date Completed |
| ---------------- | -------------     | -------- | -------------- |
| Submit Project Proposal | :heavy_check_mark:| Ayden & Joey | 07/24/2020 |
| Initialize git Repo     | :heavy_check_mark:| Ayden & Joey | 07/24/2020 |                
| Syslogging              | :heavy_check_mark: | Ayden        | 07/24/2020 |
| Requirement 1           | :heavy_plus_sign: | Ayden        |     N/A    |
| Requirement 2           | :heavy_plus_sign:               | Joey         |     N/A    |
| Calculation of jitter   | :x:               | Ayden        |     N/A    |
| Calculation of drift    | :x:               | Ayden        |     N/A    |
| Circular Buffer         | :heavy_plus_sign:               | Joey         |     N/A    |
| TBD                     | :x:               |              |     N/A    |
| TBD                     | :x:               |              |     N/A    |
