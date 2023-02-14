const button = document.getElementById("unique-button");

const soluce = document.getElementById("valide-button");

const clickHere = document.getElementById("soluce-click");

const papers = document.querySelectorAll(".paper");

const find = document.getElementById("give-indice");

const b1 = document.getElementById("bur-1");
const b2 = document.getElementById("bur-2");
const b3 = document.getElementById("bur-3");
const b4 = document.getElementById("bur-4");
const b5 = document.getElementById("bur-5");
const b6 = document.getElementById("bur-6");
const b8 = document.getElementById("bur-8");
const b9 = document.getElementById("bur-9");
const b10 = document.getElementById("bur-10");

const waitTime = 3 * 60 * 1000;

const articleShow = document.querySelector(".articles");

const showMenu = document.querySelector(".menu");

const showContenu = document.querySelector(".contenu");

const buttonFind = document.getElementById("soluce-button");

const bureau = document.querySelectorAll(".bare");

const pass = document.querySelector(".inputBox");

const paperContainer = document.querySelector(".container");

let motDePasseAttendu = "peine"; // Définir le mot de passe attendu
const textResolve = document.querySelector(".box-text");

let nombreBoutonsClic = 11; // Définir le nombre minimum de boutons à cliquer
let boutonsClicsEffectués = 0; // Initialiser le compteur de clics

const departMinutes = 10;
let temps = departMinutes * 60;

const timerElement = document.getElementById("timer");

let accesDepart = 1;
let acces = 0;

// -------Pop d'alert d'indice------------
window.alert("Vous pourrez recevoir un indice au bout de 3 min");
// ---------------------------------------

let champMotDePasse = document.getElementById("log-input");

champMotDePasse.addEventListener("input", verifierMotDePasse);

function verifierMotDePasse() {
  if (champMotDePasse.value === motDePasseAttendu) {
    afficherBouton();
    acces++;
  } else {
    cacherBouton();
  }
};

function afficheBureau() {
  if (acces < accesDepart) {
    paperContainer.style.visibility = "hidden";
    soluce.style.visibility = "hidden";
  } else {
    paperContainer.style.visibility = "visible";
    soluce.style.visibility = "visible";
  }
};

function afficherBouton() {
  textResolve.style.visibility = "visible"; // Afficher le bouton si le mot de passe est correct
};

function cacherBouton() {
  textResolve.style.visibility = "hidden"; // Masquer le bouton si le mot de passe est incorrect
};

setInterval(() => {
  let minutes = parseInt(temps / 60, 10)
  let secondes = parseInt(temps % 60, 10)

  minutes = minutes < 10 ? "0" + minutes : minutes
  secondes = secondes < 10 ? "0" + secondes : secondes

  timerElement.innerText = `${minutes}:${secondes}`
  temps = temps <= 0 ? 0 : temps - 1
}, 1000);

clickHere.addEventListener("click", () => {
  afficheBureau();
});

soluce.addEventListener("click", () => {
  button.style.display = "block";
});

papers.forEach(paper => {
  paper.addEventListener("click", () => {
    const direction = Math.random() < 0.5 ? -1 : 1;
    paper.style.transform = `translateX(${direction * 100}%) rotate(-3deg)`;
  });
});

button.addEventListener("click", () => {
  window.alert("Adresse du bourreau : 123 Rue des Étoiles Filantes, Cielville, Nébulie")
  window.location.href = "question.html";
});

window.addEventListener('load', function () {
    console.log('Cette fonction est exécutée une fois quand la page est chargée.');
});

bureau.forEach(bare => {
  bare.addEventListener("click", () => {
    articleShow.style.visibility = "hidden";
    paperContainer.style.visibility = "hidden";
    soluce.style.visibility = "hidden";
    console.log(boutonsClicsEffectués);
    boutonsClicsEffectués++;
    // window.alert("Il n'y a rien dans ce bureau");
    saisieUtilisateur();
  });
});

b1.addEventListener("click", () => {
  articleShow.style.visibility = "visible";
  boutonsClicsEffectués++;
  saisieUtilisateur();
});

b2.addEventListener("click", () => {
  window.alert("Il n'y a rien dans ce bureau");
});

b3.addEventListener("click", () => {
  window.alert("Il n'y a rien dans ce bureau aussi, j'avoue c'est vide.");
});

b4.addEventListener("click", () => {
  let couleurs = ["white", "red"];
  setInterval(() => {
  let couleurAleatoire = couleurs[Math.floor(Math.random() * couleurs.length)];
  document.body.style.backgroundColor = couleurAleatoire;
}, 2000);
});

b5.addEventListener("click", () => {
  window.alert("Il n'y a rien dans ce bureau");
});

b6.addEventListener("click", () => {
  window.alert("Il n'y a rien dans ce bureau à part la peine du prisonnier");
});

b8.addEventListener("click", () => {
  window.alert("Eh non, y'a rien ici non plus ! Dommage !!");
});

b9.addEventListener("click", () => {
  window.alert("Peut-être qu'un texte est caché, à vous de voir");
});

b10.addEventListener("click", () => {
  window.alert("Il n'y a rien dans ce bureau");
  window.alert("Il n'y a rien dans ce bureau");
  window.alert("Il n'y a rien dans cette peine");
  window.alert("Il n'y a rien dans ce bureau");
  window.alert("Il n'y a rien dans cette peine");
});

document.addEventListener("copy", (event) => {
  event.preventDefault();
  alert("Je ne te permets pas de copier !");
});

buttonFind.addEventListener("click", () => {
  showMenu.style.visibility = "hidden";
  showContenu.style.visibility = "visible";
  boutonsClicsEffectués++;
  saisieUtilisateur();
})

function saisieUtilisateur() {
  if (boutonsClicsEffectués < nombreBoutonsClic) {
    // Ne permettre pas à l'utilisateur de saisir des données
    pass.style.visibility = "hidden";
  } else {
    // Autoriser l'utilisateur à saisir des données
    // ...
    pass.style.visibility = "visible";
  }
};

// Démarre une minuterie pour déclencher l'affichage du bouton après le temps d'attente
setTimeout(function() {
  const answer = document.querySelector(".button-indice");
  answer.style.visibility = "visible";
}, waitTime);

find.addEventListener("click", () => {
  window.alert("L'indice est dans la peine de mort, chercher dans les bureaux");
});


//-------Fonction de pop-------------
/*function pop() {
  window.alert("Aller on se dépêche, plus vite !!");
};

setInterval(pop, 10000);*/
//------------------------------------

//-------Fonction de indice-------------
/*function indice() {
  window.alert("Flemme pour l'indice, enfaite ☻");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
  window.alert("Bonne chance !!");
};

setTimeout(indice, 100000);*/
//------------------------------------