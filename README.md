# BeeProjects_GetNextLine
Hive 42 My attempts at creating GetNextLine - Passed 100/100

The goal of this project is to understand how files are opened, read and closed in an OS. The project Get_Next_Line should return one line at a time from a FD (file descriptor).

For example, 
the file descriptor:

11111\n
1111\n
1111111\n
111111\n

if I set my GNL to read 10 bytes at a time, it will read the first two lines right before the second \n character. Writes the first line out and then read 10 more bytes and then print the second line out.

My approach is to first read and using a while loop to check if the read that we have read has the \n char. It will keep reading and store all the bytes that have been read in s_buff. With update_line, I used the output from read_line and then I find the first \n to substr from the next char to the end of string to store the remaining bytes that was read, so we don't lose them. In fix_line, I also take the output from read_line and use substr from the beginning to get the first line that was correctly read till the first \n. 

My solution introduced two static variable so it is not suitable for the bonus section where only one static variable is allowed. My second static variable act as an switch to make sure that I don't double free my static variable that holds all bytes that were read. As you can see that I include check == 0 in the very first check. This was an error that happened with the francinette checker.  
