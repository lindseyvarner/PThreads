As specified in the project description, this README includes a description of difficulties I encountered with this project.

I did not encounter many problems in the program itself after following the reference video instructions for creating and destroying pthreads/using arrays. The only issue was the warning about the unused parameter in the overlord_print function.

I was unsure of how to quit with the proper exit code if pthread creation failed, so I used this article as a reference:
https://www.geeksforgeeks.org/error-handling-c-programs/

My main problems came from Centaurus. I'm still unfamiliar with it, so I had to watch videos and look at project 1 to remember how to create files and to use Vim. 

When trying to run my bash script, I was getting a 'not found' error, so I kept updating test.sh, deleting the resulting slurm file, and trying again with different syntax. It turned out not to be a syntax error, but a failure to run make on my program first. 