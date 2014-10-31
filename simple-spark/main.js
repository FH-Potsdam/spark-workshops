// I think I need to
//
// - login
// -
// sparkLogin(function(data) {
// console.log(data);
// device.getVariable('count', function(err, data) {
// if (err) {
//   console.log('An error occurred while getting attrs:', err);
// } else {
// console.log('Core attr retrieved successfully:', data);
// }
// });
//
// var devicesPr = spark.listDevices();
// devicesPr.then(
//   function(devices){
//     console.log('Devices: ', devices);
//   },
//   function(err) {
//     console.log('List devices call failed: ', err);
//   }
// );
spark.login({
    accessToken: '3e9a015c022107b39a6f471aaa2083d15f34baf4'
}, function(err, body) {
    if (err !== null) {
        console.log('API call login completed on callback:', body);
        console.log('err: ', err);
        return;
    }

var cnt = 0;
    spark.claimCore("53ff72066667574829202167", function(err, data) {
        console.log('spark.claimCore err:', err);
        console.log('spark.claimCore data:', data);


spark.listDevices(function(devices) {
  var device = devices[0];

  console.log('Device name: ' + device.name);
  console.log('- connected?: ' + device.connected);
  console.log('- variables: ' + device.variables);
  console.log('- functions: ' + device.functions);
  console.log('- version: ' + device.version);
  console.log('- requires upgrade?: ' + device.requiresUpgrade);
});
        var cnt = 0;
        setInterval(function() {
          cnt++;
        $( "#target" ).text( cnt );
      // console.log(cnt);
}, 1000);

    });
});
// });