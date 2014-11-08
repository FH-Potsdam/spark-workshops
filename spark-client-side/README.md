Spark Client Side
=================


####This uses AJAX. So it needs http-server if you run it localy.  

create next to your "main.js" a file called "private" and add your credentials in there like this:  

    {
      "username":"you@example.me",
      "password":"123456"
    }

run:  

    npm install && bower install

then run:  

    http-server  

and go to [http://0.0.0.0:8080/](http://0.0.0.0:8080/)  

![](screen.png)  

Thanks to [@edgarsilva](https://github.com/edgarsilva). See the [issue](https://github.com/spark/sparkjs/issues/34).  