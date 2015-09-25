/**
 * @author Kevin Casault
 */
(function() {

	var $ = function(id) {
		return document.getElementById(id);
	};

	var objContacts = [{
		"firstName" : "John",
		"lastName" : "Doe",
		"phoneNumber" : "(222) 555-1212",
		"emailAddress" : "jdoe@whatever.com"
	}, {
		"firstName" : "John",
		"lastName" : "Doe",
		"phoneNumber" : "(222) 555-1212",
		"emailAddress" : "jdoe@whatever.com"
	}, {
		"firstName" : "John",
		"lastName" : "Doe",
		"phoneNumber" : "(222) 555-1212",
		"emailAddress" : "jdoe@whatever.com"
	}, {
		"firstName" : "John",
		"lastName" : "Doe",
		"phoneNumber" : "(222) 555-1212",
		"emailAddress" : "jdoe@whatever.com"
	}];

	var strContacts = [["John", "Doe", "(222) 555-1212", "jdoe@whatever.com"], ["John", "Doe", "(222) 555-1212", "jdoe@whatever.com"], ["John", "Doe", "(222) 555-1212", "jdoe@whatever.com"], ["John", "Doe", "(222) 555-1212", "jdoe@whatever.com"]];

	var outputTableFromObj = function(objArray) {
		var arr = [];
		arr = objArray;

		var tableHeaders = ["First Name", "Last Name", "Phone", "Email"];
		var headerRow = document.createElement("tr");

		for(var i =0; i < tableHeaders.length; i++) {
			cellHead = document.createElement("td");
			cellHead.innerHTML = tableHeaders[i];
			headerRow.appendChild(cellHead);
		}

		var mTable = document.createElement("table");
		mTable.appendChild(headerRow);
		mTable.setAttribute("border", 1);
		//var contacts = document.getElementById("contacts1");
		for (var i = 0; i <= arr.length - 1; i++) {
			var obj = {};
			obj = arr[i];
			var tableRow = document.createElement("tr")
			for (var idx in obj) {
				var cell = document.createElement("td");
				cell.innerHTML = obj[idx];
				tableRow.appendChild(cell);
			}

			mTable.appendChild(tableRow);
		}

		return mTable;
	};

	var outputTableFromArray = function(strArray) {
		var output = "<table border='1'><tr><td>First Name</td><td>Last Name</td><td>Phone</td><td>Email</td></tr>";

		var tableHeaders = ["First Name", "Last Name", "Phone", "Email"];
		var headerRow = document.createElement("tr");

		for(var i =0; i < tableHeaders.length; i++) {
			cellHead = document.createElement("td");
			cellHead.innerHTML = tableHeaders[i];
			headerRow.appendChild(cellHead);
		}

		var mTable = document.createElement("table");
		mTable.appendChild(headerRow);
		mTable.setAttribute("border", 1);

		for (var i = 0; i <= strArray.length - 1; i++) {
			var tableRow = document.createElement("tr")
			var a = [];
			a = strArray[i];
			for (var j = 0; j <= a.length - 1; j++) {
				var cell = document.createElement("td");
				cell.innerHTML = a[j];
				tableRow.appendChild(cell);
				//output = output + "<td>" + a[j] + "</td>";
			}
			//output = output + "</tr>";
			mTable.appendChild(tableRow);
		}
		//output = output + "</table>";


		return mTable;

	};

	window.onload = function() {
		$("contacts1").appendChild(outputTableFromObj(objContacts));
		$("contacts2").appendChild(outputTableFromArray(strContacts));
	};

})();