var $ = function (id) { return document.getElementById(id) }

function setColorAttr(color) {
  var node = document.createAttribute("class");
  node.value = color;
  return node
}


window.onload = function () {
  var mButton = document.getElementById('btnRedraw');

  mButton.onclick = function () {
    var mTable = document.getElementById('mtable');

    mTable.innerHTML = "";

    var multTable = document.createElement('table');
    var rows = document.getElementById('txtRowColumn');
    console.log(rows.value);
    var width = 12;
    var length = 15;
    var mult = new Array(15);
    var colorCode = document.querySelector('input[name="radColor"]:checked') ? document.querySelector('input[name="radColor"]:checked').value : "";
/*    for (var i = 0; i < 12; i++) {
      mult[i] = new Array(15);
    }*/


    for(var i = 0; i <= width; i++) {
      var row_cell = document.createElement("tr");

      for(var j = 0; j <= length; j++) {
        var cell = document.createElement("td");

        if(i == rows.value ||  j == rows.value) {
          cell.setAttribute("class", colorCode);
        }

        if(i == j && i > 0) {
          cell.setAttribute("class", "yellow");
        }

        if(i == 0) {
          cell.innerHTML = j;
          cell.setAttribute("class", "gray");
        } else if(j == 0) {
          cell.innerHTML = i;
          cell.setAttribute("class", "gray");
        } else {
          cell.innerHTML = i * j;
        }



        row_cell.appendChild(cell);
      }

      multTable.appendChild(row_cell);
    }
    mTable.appendChild(multTable);

  }
}