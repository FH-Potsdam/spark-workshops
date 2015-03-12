$(document).ready(function() {
  $("#api-token").sisyphus();
  $("#core-id").sisyphus();

  var baseURL = "https://api.spark.io/v1/devices/";
  var variable = "count";
  var method = "blink";
  var command = "toggle";
  // var coreid =
  // var token =

  $("#toggle").click(function(event) {
    /* Act on the event */
    console.log(event);
    var url = baseURL + $("#core-id").val() + "/" + method;

    $.ajax({
      type: "POST",
      url: url,
      data: {
        access_token: $("#api-token").val(),
        args: command
      },
      success: function() {
        console.log("toggled blink");
      },
      dataType: "json"
    }).fail(function(obj) {
      console.log("error: ", obj);
    });
  });

  $("#count").click(
    function(event) {
      console.log(event);
      var url = baseURL + $("#core-id").val() + "/" + variable + "?access_token=" + $("#api-token").val();

      $.getJSON(url, function(res) {
        $("#count-val").html(res.result);
      })
        .fail(function(obj) {
          console.log("error:", obj);
        });

    });
});