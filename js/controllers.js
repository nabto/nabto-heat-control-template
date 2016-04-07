angular.module('app.controllers', [])

.controller('aCMEHeatPump9000Ctrl', function($scope, $ionicPlatform) {

  /* Change this to your device ID */
  var device = 'nabto://heat.demo.nab.to/';

  function fetch(request, cb) {
    console.log('Fetch: ' + request);

    window.nabto.fetchUrl(device + request, function(status, result) {
      if (!status && result.response) {
        return cb(result.response);
      }
      console.error("Something went wrong");
    });
  }

  function updateTemperature() {
    fetch('nabto_heatpump_get_temp.json?', function(response) {
      $scope.temperature = response.temp;
      $scope.$digest();
    });
  }

  function updateState() {
    fetch('nabto_heatpump_get_state.json?', function(reponse) {
      $scope.heatState = reponse.state;
      $scope.$digest();
    });
  }

  function updateMode() {
    fetch('nabto_heatpump_get_mode.json?', function(response) {
      $scope.heatMode = response.mode.toString();
      $scope.$digest();
    });
  }

  $ionicPlatform.ready(function() {
    updateTemperature();
    updateState();
    updateMode();
  });

  $scope.heatPumpUpPushed = function() {
    var newTemp = $scope.temperature + 1;
    fetch('nabto_heatpump_set_temp.json?temp=' + newTemp, function(response) {
      $scope.temperature = response.temp;
      $scope.$digest();
    });
  };

  $scope.heatPumpDownPushed = function() {
    var newTemp = $scope.temperature - 1;
    fetch('nabto_heatpump_set_temp.json?temp=' + newTemp, function(response) {
      $scope.temperature = response.temp;
      $scope.$digest();
    });
  };

  $scope.heatStateChanged = function() {
    var newState = $scope.heatState ? 0 : 1;
    fetch('nabto_heatpump_set_state.json?state=' + newState, function(response) {
      $scope.heatState = response.state;
      $scope.$digest();
    });
  };

  $scope.heatModeChanged = function(newMode) {
    fetch('nabto_heatpump_set_mode.json?mode=' + newMode, function(response) {
      $scope.heatMode = response.mode;
      $scope.$digest();
    });
  };
})

.controller('cloudCtrl', function($scope) {

});
