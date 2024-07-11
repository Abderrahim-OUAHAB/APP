const choices=["rock","paper","scissors"];
const player=document.getElementById("playerDisplay");
const computer=document.getElementById("computerDisplay");
const res=document.getElementById("resDisplay");
const sp=document.getElementById("sp");
const sc=document.getElementById("sc");
let ps=0;
let cs=0;
function createFlower() {
  const flower = document.createElement('div');
  flower.className = 'flower';
  const x = Math.random() * window.innerWidth;
  flower.style.left = x + 'px';
  document.getElementById('flowerContainer').appendChild(flower);

  // Animation de la fleur tombante
  setTimeout(() => {
      flower.style.transition = 'transform 3s ease-out, opacity 1s ease-out';
      flower.style.transform = 'translateY(' + (window.innerHeight + 100) + 'px)';
      flower.style.opacity = '0';
  }, 100);

  // Supprimer la fleur après l'animation
  setTimeout(() => {
      flower.remove();
  }, 4000);
}


function playGame(choice){
const computerChoice=choices[Math.floor(Math.random()*3)];
let result ="";
let shapeChoise;
let comChoice;
switch(choice){
    case "rock":
        shapeChoise="👊🏻";
      break;
    case "paper":
        shapeChoise="🖐🏻";
        break;
    case "scissors":
            shapeChoise="✌🏻";
            break;
}
switch(computerChoice){
    case "rock":
        comChoice="👊🏻";
      break;
    case "paper":
        comChoice="🖐🏻";
        break;
    case "scissors":
        comChoice="✌🏻";
            break;
}
  if(choice===computerChoice){
    result="DRAW 😐";

  }else{
    switch(choice){
        case "rock":
          result=  (computerChoice ==="scissors") ? "WIN 🥳" :"LOST 🥺";
          break;
        case "paper":
            result=  (computerChoice ==="rock") ? "WIN 🥳" :"LOST 🥺";
            break;
        case "scissors":
                result=  (computerChoice ==="paper") ? "WIN 🥳" :"LOST 🥺";
                break;
    }
  }
  switch(result){
    case "WIN 🥳":
        res.style.color="green";
        ps++;
        sp.textContent=ps;
        createFlower();
        break;
        case "LOST 🥺":
            res.style.color="red";
            cs++;
            sc.textContent=cs;
            break;
           default:
            res.style.color="grey";
                break;
  }
  player.textContent=shapeChoise;
  computer.textContent= comChoice;
  res.textContent=result;


}

