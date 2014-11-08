// I think I need to
var error = function(err) {
      console.log('API call failed: ', err);
    };

var callback = function(err, body) {
  console.log('API call login completed on callback:', body);
  var devicesPr = spark.listDevices();

  devicesPr.then(
    function(data) {
      console.log('Core attrs retrieved successfully:', data);
      if (data.length > 0) {
        var a_core = data[0];
        console.log('This is the first registerd device', a_core);
        console.log('Device name: ' + a_core.name);
        console.log('- connected?: ' + a_core.connected);
        console.log('- variables: ' + a_core.variables);
        console.log('- functions: ' + a_core.functions);
        console.log('- version: ' + a_core.version);
        console.log('- requires upgrade?: ' + a_core.requiresUpgrade);

        // now it works. Thanks to edgarsilva
        // https://github.com/edgarsilva
        // https://github.com/spark/sparkjs/issues/34
        a_core.getAttributes(function(err, data) {
          if (err) {
            console.log('An error occurred while getting device attrs:', err);
          } else {
            console.log('Device attrs retrieved successfully:', data);
          }
        });
        // needs the example src/sparkworkshop_publish/sparkworkshop_publish.ino
        //
        // https://github.com/FH-Potsdam/2014-2015-WiSe-spark-core-workshop/blob/master/src/sparkworkshop_publish/sparkworkshop_publish.ino
        setInterval(function() {
        a_core.getVariable('count', function(err, data) {
          if (err) {
            console.log('An error occurred while getting attrs:', err);
          } else {
            console.log('Core attr retrieved successfully:', data);
         $( "#target" ).html( "<h1>My name is \"" + a_core.name + "\" and I'm at count</h1><h2>"+ data.result +"</h2>");
          }
        });
      }, 1000);
      }
    },error);
};

$.getJSON("private", function (obj) {
// console.log(obj);
spark.login(obj, callback);

});



// //         var cnt = 0;
// //         setInterval(function() {
// //           cnt++;
// //         $( "#target" ).text( cnt );
// //       // console.log(cnt);
// // }, 1000);