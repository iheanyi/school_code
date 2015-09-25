//Declare global variables

var interval;
var currentX = 0;
var currentY = 0;
var ctr = 0;

var matrix = [['01','02','03'],['04','05','06'],['07','08','09']];;

function buildInitialTable() {
  var table = document.createElement('table');
  table.setAttribute('id', 'outTable');
  table.setAttribute('border', 1);

  //var ctr = 1;
  for(var i = 0; i < 3; i++) {
    var tableRow = document.createElement('tr');
    for(var j = 0; j < 3; j++) {
      var rowCell = document.createElement('td');
      rowCell.innerHTML = matrix[i][j];
      tableRow.appendChild(rowCell);
    }

    table.appendChild(tableRow);
  }
  document.body.appendChild(table);
}

function updateTable() {
  console.log("replaced!" + ctr);

  if(ctr >= 9) {
    console.log("GREATER THAN LIMIT");
    stopInterval();
    clearInterval(this);
    clearInterval(interval);
    return;
    //break;
  }

  if(ctr % 2 == 0) {
    matrix[currentX][currentY] = 'O'
  } else {
    matrix[currentX][currentY] = 'X'
  }
  currentY++;
  if(currentY >= 3) {
    currentX++;
    currentY = 0;
  }

  var oldTable = document.getElementById('outTable');
  var table = document.createElement('table');
  table.setAttribute('id', 'outTable');
  table.setAttribute('border', 1);

  for(var i = 0; i < 3; i++) {
    var tableRow = document.createElement('tr');
    for(var j = 0; j < 3; j++) {
      var rowCell = document.createElement('td');
      rowCell.innerHTML = matrix[i][j];
      tableRow.appendChild(rowCell);
    }

    table.appendChild(tableRow);
  }

  document.body.replaceChild(table, oldTable);

  ctr++;

}

function stopInterval() {
  window.clearInterval(interval);
}

function startInterval() {
  var intervalTracker = setInterval(function() {
    if(ctr > 9) {
      console.log("Clearing interval.");
      window.clearInterval(intervalTracker);
      window.clearInterval(this);
    }

    updateTable();

  }, 10);
}

window.onload = function () {

  buildInitialTable();
  interval = setInterval(updateTable, 3000);

}