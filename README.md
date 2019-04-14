# ASCII-filter

The works on project are underway. Main goal is to make console application that will work like a filter for JPG image(given as first 
parameter of command line) and produce ASCII image(saved in path given as a second parameter of command line).
Following effect whats to be reached : 

![alt text](https://kann8a.db.files.1drv.com/y4mLN1AipeQN2XxWkCNKtWwMrINP8uHcLnShPIx7-_NH8BJ7tPnxOuaiFCZMTUbwELwSkHBMmU7CXMyujNhH9sE635GptS3isG8SEcmQmuOXfn-YwwA7CVq5s0XLW2TDVL9932Jy55LSxM7JyDN7jumZpF6NKYoIX1JpeYqZrTwvwVisPex46G-7HJWk6NXsNH8wYhdGEF73oKqek_cIO70oA/ex-1-0.gif?download&psid=1)

Source of image : http://picascii.com/

### Path of project implementation 

1) Load/Save image - DONE

2) Convert RGB image to binary image - DONE

3) **REFACTORIZARION OF DONE WORK - Multithread programming and class organization**

4) Convert binary image to ASCII - Main Problem :
   * Think how to adjust sizes of glyps ?
   * How to generate text on image ?
   * How to convert ASCII which are numbered from 33 to 127 - I am not considering those ASCII values which represents particular keys
   * Probably much more...
  
5) Extending application to allow filtering videos in MP4 format in release 2.0
