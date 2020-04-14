

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    //declarE variable for storing the//
    //reading AS WELL AS writing descriptor values//
    
    int df[2];
	int fileSize;
	pid_t pid;

    char text[1024];
	char copy[1024];  

    //Create two pointers for the sorce and destination files
    char* sourceFile = argv[1];
    char* destFile = argv[2];

  
    
    pipe(df);
    if (pipe(df)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    }  
    
    pid = fork();
     if (pid < 0) 
    { 
        fprintf(stderr, "Fork Failed" ); 
        return 1; 
    } 
    
    if (pid > 0) 
    {
       
	   int sourceFileNumm;
	   ssize_t numBytes; 
        // close the reading end of pipe, read the file and write content to child
        close(df[0]);
        sourceFileNumm=open(sourceFile, O_RDONLY);
        numBytes=read(sourceFileNumm, text,sizeof(text));
       
        write(df[1],text, numBytes);
        
        close(df[1]);

    }else if (pid == 0){
    	
    	int destDev;
       
        close(df[1]);
        ssize_t numBytesCh;
        numBytesCh =read(df[0], copy,sizeof(copy));
        // close  the reading end of pipe//
        close(df[0]);
        // Opening a file for writing content to newfile descriptor//
        destDev=open(destFile, O_CREAT | O_WRONLY);
        
        write(destDev, copy, numBytesCh);
    }

    return 0;
}
