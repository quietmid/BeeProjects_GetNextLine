# BeeProjects_GetNextLine
Hive 42 My attempts at creating GetNextLine - Passed 100/100

The goal of this project is to understand how files are opened, read and closed in an OS. The project Get_Next_Line should return one line at a time from a FD (file descriptor).

My solution introduced two static variable so it is not suitable for the bonus section where only one static variable is allowed. My second static variable act as an switch to make sure that I don't double free my static variable that holds all bytes that were read. 
