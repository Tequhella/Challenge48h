
element1 = document.getElementById("check1")
element2 = document.getElementById("check2")
element3 = document.getElementById("check3")
element4 = document.getElementById("check4")
element5 = document.getElementById("check5")
element6 = document.getElementById("check6")
element7 = document.getElementById("check7")
element8 = document.getElementById("check8")
button = document.getElementById("Bvalid")

let seconds = 0;
setInterval(() => {
    console.log(seconds);
    seconds++;
    // if (seconds ==  10000 ){
    //     element1.checked = false;
    //     element2.checked = false;
    //     element3.checked = false;
    //     element4.checked = false;
    //     element5.checked = false;
    //     element6.checked = false;
    //     element7.checked = false;
    //     element8.checked = false;
    //     //element1.checked = false; 
    // }
}, 1000);
let end = false;
function RandomCheck(Click){
    contenu = Click.id
    console.log(contenu)
    if (seconds > 35){
        switch(contenu){
            case "check1":
                element4.checked = false;
                element5.checked = false;
                break;
            case "check2":
                element6.checked = false;
                element8.checked = false;
                break;
            case "check3":
                element3.checked = false;
                element7.checked = true;
                break;
            case "check4":
                element7.checked = false;
                element5.checked = true;
                element6.checked = true;
                break;
            case "check5":
                element1.checked = true;
                element4.checked = false;
                break;
            case "check6":
                element8.checked = true;
                element2.checked = false;
                break;
            case "check7":
                element8.checked = false;
                element3.checked = false;
                element1.checked = true;
                break;
            case "check8":
                element4.checked = true;
                element6.checked = false;
                element1.checked = false;  
                element5.checked = false;
                break;
            default:
        }
    }else if (seconds <= 35){
        switch(contenu){
            case "check1":
                element4.checked = false;
                element5.checked = false;
                
                break;
            case "check2":
                element6.checked = false;
                element8.checked = false;
                break;
            case "check3":
                element3.checked = false;
                element7.checked = true;
                element1.checked = false;
                element2.checked = true;
                // if (element7.checked == true){
                //     element7.checked = false;
                //     element8.checked = true;
                // }
                if (element5.checked == true && element7.checked == true && element4.checked == true){
                    element5.checked = false;
                    element7.checked = false;
                    element4.checked = false;
                }

                break;
            case "check4":
                element7.checked = false;
                element5.checked = true;
                element6.checked = true;
                break;
            case "check5":
                element1.checked = true;
                element4.checked = false;
                break;
            case "check6":
                element8.checked = true;
                element2.checked = false;
                element4.checked = false;
                break;
            case "check7":
                element8.checked = false;
                element3.checked = false;
                element1.checked = true;
                element3.checked = false;
                break;
            case "check8":
                element4.checked = true;
                element6.checked = false;
                element1.checked = false;  
                element5.checked = false;
                break;
            default:
        }
    }
    
    if((element1.checked != element2.checked) && (element3.checked != element4.checked)&& (element5.checked != element6.checked)&& (element7.checked != element8.checked )){
            console.log("ah oui oui")
            //button.style.backgroundColor = "green"
            button.className -= "Nonbutton"
            button.className = "button"
            end = true;
    }else{
        button.className -= "button"
        button.className = "Nonbutton"
        end = false;
    }

    /*
    if (element1.checked == true){
        element3.checked = false;
        element4.checked = false;
        element5.checked = false;
    }

    if (element2.checked == true){
        element8.checked = false;
        element7.checked = false;
        element6.checked = false;
    }
    if (element5.checked == true){
        element8.checked = false;

    }
    if (element7.checked == true){
        element3.checked = true;
        element4.checked = true;
    }
    if (element8.checked == true){
        element8.checked = false;
        element1.checked = false;
        element2.checked = true;
    }
    if (element5.checked == true){
        element7.checked = false;
        element3.checked = true;
    }
    if (element8.checked == true){
        element8.checked = false;
        element1.checked = false;
        element2.checked = true;
    }else if(element8.checked == false){
        element4.checked = false;
        element3.checked = true;
    }
    


    console.log(element1.checked);
    console.log(element2.checked);
    console.log(element3.checked);
    console.log(element4.checked);
    console.log(element5.checked);
    console.log(element6.checked);
    console.log(element7.checked);
    console.log(element8.checked);
    */
}

function FinalAlert(){
    if (end == true){
        alert('Bravo, vous avez gagné!')
    }
}

function showModal(Yes) {
    contenu = Yes.id
    if(contenu == "Bvalidoui"){
        document.querySelector('.modal2').style.display = 'block';
        document.querySelector('.modal').style.display = 'none';
    }else if (end == true){
        document.querySelector('.modal').style.display = 'block';
    }
}
  
function hideModal() {
    if (end == true){
        document.querySelector('.modal').style.display = 'none';
    }
}