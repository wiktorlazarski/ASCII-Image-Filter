# ASCII-filter

The works on project are underway. Main goal is to make console application that will work like a filter for JPG image(given as first 
parameter of command line) and produce ASCII image(saved in path given as a second parameter of command line).
Following effect whats to be reached : 

![alt text](https://kann8a.db.files.1drv.com/y4mLN1AipeQN2XxWkCNKtWwMrINP8uHcLnShPIx7-_NH8BJ7tPnxOuaiFCZMTUbwELwSkHBMmU7CXMyujNhH9sE635GptS3isG8SEcmQmuOXfn-YwwA7CVq5s0XLW2TDVL9932Jy55LSxM7JyDN7jumZpF6NKYoIX1JpeYqZrTwvwVisPex46G-7HJWk6NXsNH8wYhdGEF73oKqek_cIO70oA/ex-1-0.gif?download&psid=1)

Source of image : http://picascii.com/

### Path of project implementation 

1) Load/Save image - DONE

2) Convert RGB image to binary image - DONE

3) **REFACTORIZATION OF DONE WORK - Multithread programming and class organization** - DONE

4) Convert binary image to ASCII - Main Problem : - DONE
   * Think how to adjust sizes of glyps ?
   * How to generate text on image ?
   * How to convert ASCII which are numbered from 33 to 127 - I am not considering those ASCII values which represents particular keys
   * Probably much more...
   
5) **REFACTORIZATION**

6) Release 1.0

7) Extending application to allow filtering videos in MP4 format in release 2.0

## SUCCESS - Implementation of algorithm completed successfully <3 :D
Below you can see one of firstly generated pictures

![alt text](https://db3pap002files.storage.live.com/y4mzhPKUmdDUFdaZax9S7mea7Ch4oZyF0LjJvnmRTzZ0D55V7Bbds_FKdZVhoSOXeqSzm6N4GTYx7Pd_awG43tVkz4ejcVxe9cqcW1sI1Z04FJ4KwO9wSM-vP8foVpSfce1OgcHejWFFe_Z4w4VQ8-FrCCjm7MisELiVNGQk_KR5-wLkteJvqaIabrSchDjtBJjnVzz9QQGpTpPcH1jmwtvPQ/output.jpg?psid=1&width=450&height=830)
