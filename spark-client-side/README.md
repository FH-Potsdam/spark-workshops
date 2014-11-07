Spark Client Side
=================

This is a tryout to use the Spark Core Javascript SDK.
Unfortunately it thorws an error when trying to get a variable. :-(  

####This uses AJAX. So it needs http-server if you run it localy.  

create a file next to yout "main.js" file called "private" and add your credentials in there like this:  

    {
      "username":"you@example.me",
      "password":"123456"
    }

run:  

    npm install && bower install

the run:  

    http-server  

and go to [http://0.0.0.0:8080/](http://0.0.0.0:8080/)  