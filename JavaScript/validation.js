<html>
<head>
<script>
function Sumana() { var name = document.forms["REG_form"]["Name"]; var sex =
document.forms["REG_form"]["sex"]; var Collage = document.forms["REG_form"]["Collage Name"]; var what =
document.forms["REG_form"]["Branch"];
var EMail = document.forms["REG_form"]["EMail"]; var phone =document.forms["REG_form"]["phone"]; if
(name.value == "") {window.alert("Please enter you're name."); name.focus(); return false;
}
if (sex.value == "") { window.alert("Please enter you're sex.");sex.focus();
return false;
}
if (Collage.value == "") { window.alert(
"Please Enter you're collage name."); Collage.focus();return false;
}
if (what.selectedIndex < 1) { alert("Please enter you're course.");what.focus();
return false;
}
if (EMail.value == "") {
window.alert("Please enter you're E-Mail ID"); EMail.focus();return false;
}
if (phone.value == "") { window.alert(
"Please enter you're phone number."); phone.focus();return false;
}
return true;
}
</script>
<style> div {
box-sizing: border-box; width: 100%; border: 100px solid black; float: center; align-content: center; align-items:
Center;
}
form { margin: 0 auto; width: 600px;
}
</style>
</head>
<body>
<h1 style="text-align: center;">REGISTRATION FORM</h1>
<form name="REG_form" action="#" onsubmit="return Sumana()"method="post">
<p>Name: <input type="text" size="65" name="Name" /></p>
<br />
<p>Sex:
<select type="text" value="" name="sex">
<option>---</option>
<option>MALE</option>
<option>FEMALE</option>
<option>OTHER</option>
</select>
</p>
<br />
<p>Collage name: <input type="text" size="65" name="Collage Name"
/></p>
<br />
<p>Email: <input type="text" size="65" name="EMail" /></p>
<br />
<p>Phone no: <input type="text" size="65" name="phone" /></p>
<br />
<p> BRANCH:
<select type="text" value="" name="Subject">
<option>BTECH</option>
<option>BBA</option>
<option>BCA</option>
<option>B.COM</option>
</select>
</p>
<br />
<br />
<p>
<input type="submit" value="SUBMIT" name="Submit" />
</p>
</form>
</body>
</html>