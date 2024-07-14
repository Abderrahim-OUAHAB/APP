async function fetchData() {
    try {
        const pokemonNameId = document.getElementById("search-input").value.toLowerCase();
        const response = await fetch(`https://pokeapi-proxy.freecodecamp.rocks/api/pokemon/${pokemonNameId}`);
        if (!response.ok) {
            window.alert("Pokémon not found");
            return; 
        }
        const data = await response.json();
        const name = document.getElementById("pokemon-name");
        const id = document.getElementById("pokemon-id");
        const weight = document.getElementById("weight");
        const height = document.getElementById("height");
        const types = document.getElementById("types");
        const hp = document.getElementById("hp");
        const attack = document.getElementById("attack");
        const defense = document.getElementById("defense");
        const specialAttack = document.getElementById("special-attack");
        const specialDefense = document.getElementById("special-defense");
        const speed = document.getElementById("speed");
        const imgPoke = document.getElementById("sprite");

        const pokeName = data.name;
        const pokeId = data.id;
        const pokeWeight = data.weight;
        const pokeHeight = data.height;
        const pokeTypes = data.types;
        const typeNames = [];
        pokeTypes.forEach(item => {
            typeNames.push(item.type.name);
        });

        const pokeStats = data.stats;
        const hpRate = [];
        pokeStats.forEach(item => {
            hpRate.push(item.base_stat);
        });
        const pokeHpValue = hpRate[0];  
        const pokeAttack = hpRate[1];
        const pokeDefense = hpRate[2];
        const pokeSpecialAttack = hpRate[3];  
        const pokeSpecialDefense = hpRate[4];  
        const pokeSpeed = hpRate[5];
        const pokeSprite = data.sprites.front_default;

        name.textContent = pokeName;
        name.style.display = "block";

        imgPoke.src = pokeSprite;
        imgPoke.style.display = "block";

        id.textContent = `#${pokeId}`;
        id.style.display = "block";
        weight.textContent = `Weight: ${pokeWeight}`;
        weight.style.display = "block";
        height.textContent = `Height: ${pokeHeight}`;
        height.style.display = "block";
         types.textContent='';
        typeNames.forEach(t=>{
            const sp=document.createElement("span");
            sp.textContent=t;
            types.appendChild(sp);
        })
        
        types.style.display = "block";

        hp.textContent = pokeHpValue;
        attack.textContent = pokeAttack;
        defense.textContent = pokeDefense;
        specialAttack.textContent = pokeSpecialAttack;
        specialDefense.textContent = pokeSpecialDefense;
        speed.textContent = pokeSpeed;
    } catch (error) {
        console.error("Could not fetch resource", error);
    }
}
