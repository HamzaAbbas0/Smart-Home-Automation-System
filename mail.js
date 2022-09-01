// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBOFX0OFBNfFUyF8iv80rNLHKSaR6b-DFc",
  authDomain: "homeautomation-109af.firebaseapp.com",
  databaseURL: "https://homeautomation-109af-default-rtdb.firebaseio.com",
  projectId: "homeautomation-109af",
  storageBucket: "homeautomation-109af.appspot.com",
  messagingSenderId: "291891143111",
  appId: "1:291891143111:web:ba1be35833cd5a98c579e2"
};

//initillize the firebase
firebase.initializeApp(firebaseConfig);

// reference of the my datbase
var WebpageFirebaseDB = firebase.database().ref("LIGHTS ON-OFF");
var WebpageFirebaseDB1 = firebase.database().ref("FAN ON-OFF");


const getValueInput3 = () => {
  var inputValue3 = document.getElementById("togBtn").checked; 
  WebpageFirebaseDB.update({STATE: inputValue3 }); 
  console.log(inputValue3);  
}
const getValueInput4 = () => {
  var inputValue4 = document.getElementById("togBtn1").checked; 
  WebpageFirebaseDB1.update({ STATE: inputValue4 }); 
  console.log(inputValue4);  
}
function changeText() {
  x= document.getElementById('txt1');
  if (x.innerHTML === 'LIGHTS OFF'){
    x.innerHTML = "LIGHTS ON";
  }
  else{
    x.innerHTML = "LIGHTS OFF";
  }
}
function changeText1() {
  x= document.getElementById('txt2');
  if (x.innerHTML === 'FAN OFF'){
    x.innerHTML = "FAN ON";
  }
  else{
    x.innerHTML = "FAN OFF";
  }
}

