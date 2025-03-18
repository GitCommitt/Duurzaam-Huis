<?php
header('Access-Control-Allow-Origin: *');

// Takes raw data from the request
$json = file_get_contents('php://input');

if(empty($json)) {
  $json = file_get_contents("jsonInput.txt");
 
  echo  $json;
}
else {
  // If length of the json is longer than 1024, do not change the json file.
  if(strlen($json) > 1024) {
    exit("not parsing data, data is over 1024 characters!");
  }

  // Converts it into a PHP object
  // can be used later to read specific keys
  $data = json_decode($json);

  

  
  // Haal bestaande JSON-gegevens op uit het bestand
  $fileContents = file_get_contents("jsonInput.txt");
  $fileData = json_decode($fileContents);

  // Update gegevens
  $fileData->ldr = $data->ldr_value;
  $fileData->dht11->temperature = $data->temperature;
  $fileData->dht11->humidity = $data->humidity;
  $fileData->dht11->heatIndex = $data->heat_index;

  $fileData->lights = [true,true,true];
  // Willekeurige LED-status genereren
  for ($i = 0; $i < count($fileData->lights); $i++) {
    $fileData->lights[$i] = rand(0, 1);
}
// Zet bijgewerkte gegevens om naar JSON
$finalJson = json_encode($fileData);


  //open & write to file
  $jsonFile = fopen("jsonInput.txt", "w");
  fwrite($jsonFile, $finalJson . "\n");
  fclose($jsonFile);

  
  // Stuur JSON-response terug
  header("Content-Type: application/json; charset=utf-8");
  echo json_encode($finalJson);
}





