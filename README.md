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
| Requirement 1           | :heavy_check_mark: | Ayden        | 07/27/2020 |
| Requirement 2           | :heavy_check_mark: | Joey         | 08/01/2020 |
| Time Analysis Calcs     | :heavy_check_mark: | Ayden        | 07/29/2020 |
| Circular Buffer         | :heavy_check_mark: | Joey         | 07/31/2020 |
| Sequencer               | :heavy_check_mark: | Ayden        | 07/31/2020 |
| Report                  | :heavy_check_mark: | Joey & Ayden | 08/03/2020 |
