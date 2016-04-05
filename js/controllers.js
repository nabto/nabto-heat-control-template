angular.module('app.controllers', [])

.controller('aCMEHeatPump9000Ctrl', function($scope) {

  var baseUrl = 'nabto://mr.demo.nab.to/';

  $scope.temperature = 0;

  function fetch(request, cb) {
    window.nabto.fetchUrl(baseUrl + request, function(status, result) {
      if (!status && result.response) {
        cb(result.response);
      }
      else {
        console.error("Something went wrong");
      }
    });
  }

  $scope.heatPumpUpPushed = function() {
    console.log('UP');
    var newTemp = $scope.temperature + 1;
    fetch('nabto_heatpump_set_temp.json?temp=' + newTemp, function(response) {
      $scope.temperature = response.temp;
    });
  };

  $scope.heatPumpDownPushed = function() {
    console.log('DOWN');
    var newTemp = $scope.temperature - 1;
    fetch('nabto_heatpump_set_temp.json?temp=' + newTemp, function(response) {
      $scope.temperature = response.temp;
    });
  };

  $scope.$watch('heatPumpActive', function(newValue, oldValue) {
    console.log('CHANGED: ' + newValue);
  });
})

.controller('cloudCtrl', function($scope) {

});
