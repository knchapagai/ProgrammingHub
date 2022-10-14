//Logic for generating random number

function initiate() {
    let min = 1;
    let max = 6;
    let random = Math.floor(Math.random() * (max - min + 1)) + 1;
    document.getElementById("number").innerHTML = 'The nummber is ' + random;

    document.getElementById("dice").innerHTML = `<img src = '${random}.png' alt= '${random}' style='height: 17rem;'>`


}