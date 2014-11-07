// I think I need to
//
// - login
//
var error = function(err) {
      console.log('API call failed: ', err);
    };
var callback = function(err, body) {
  console.log('API call login completed on callback:', body);
  var devicesPr = spark.getAttributesForAll();

  devicesPr.then(
    function(data) {
      console.log('Core attrs retrieved successfully:', data);
      if (data.length > 0) {
        var a_core = data[2];
        console.log('This is the first registerd device', a_core);
        console.log('Device name: ' + a_core.name);
        console.log('- connected?: ' + a_core.connected);
        console.log('- variables: ' + a_core.variables);
        console.log('- functions: ' + a_core.functions);
        console.log('- version: ' + a_core.version);
        console.log('- requires upgrade?: ' + a_core.requiresUpgrade);
        // works until here

        // this produces an error
        a_core.getAttributes(function(err, data) {
          if (err) {
            console.log('An error occurred while getting device attrs:', err);
          } else {
            console.log('Device attrs retrieved successfully:', data);
          }
        });
        // this produces an error as well
        a_core.getVariable('count', function(err, data) {
          if (err) {
            console.log('An error occurred while getting attrs:', err);
          } else {
            console.log('Core attr retrieved successfully:', data);
          }
        });
      }
    },error());
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